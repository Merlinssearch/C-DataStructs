# Makefile - build library and tests, put all test artifacts into the `target/` folder.
# Usage:
#   make          # build static lib and test binaries into target/
#   make test     # build and run tests (executables in target/)
#   make valgrind # run tests under valgrind (if installed)
#   make clean

CC ?= gcc
AR ?= ar
RANLIB ?= ranlib

CFLAGS ?= -std=c11 -Wall -Wextra -g -Iinclude
SRCDIR := src
TARGET_DIR := target
OBJDIR := $(TARGET_DIR)/obj
BINDIR := $(TARGET_DIR)
TESTDIR := tests

SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

# put the static library inside target/ so all test artifacts live under target/
STATIC_LIB := $(TARGET_DIR)/libcdatastructs.a

TEST_SRCS := $(wildcard $(TESTDIR)/*.c)
TEST_BINS := $(patsubst $(TESTDIR)/%.c,$(BINDIR)/%,$(TEST_SRCS))

.PHONY: all clean test valgrind

all: $(STATIC_LIB) $(TEST_BINS)

# Build static library (placed in target/)
$(STATIC_LIB): $(OBJS) | $(TARGET_DIR)
	@printf "AR  $@\n"
	$(AR) rcs $@ $^
	@$(RANLIB) $@ || true

# Compile object files into target/obj
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@printf "CC  $<\n"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Single rule to ensure target dir exists (avoid duplicate rules)
$(TARGET_DIR):
	@mkdir -p $(TARGET_DIR)

# Build test binaries (link against the static library in target/)
$(BINDIR)/%: $(TESTDIR)/%.c $(STATIC_LIB) | $(TARGET_DIR)
	@printf "LINK $@\n"
	$(CC) $(CFLAGS) $< $(STATIC_LIB) -o $@

# Run tests
test: all
	@printf "Running tests from $(BINDIR)...\n"
	@for t in $(TEST_BINS); do \
	  printf "==> $$t\n"; \
	  if ! $$t; then echo "Test $$t failed"; exit 2; fi; \
	done
	@printf "All tests passed.\n"

# Run tests under valgrind (if available)
valgrind: all
	@if ! command -v valgrind >/dev/null 2>&1; then \
	  echo "valgrind not found; install valgrind or run 'make test'"; exit 1; \
	fi
	@for t in $(TEST_BINS); do \
	  printf "VALGRIND $$t\n"; \
	  valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 $$t || exit 2; \
	done
	@printf "Valgrind: no leaks detected (exit code 0)\n"

clean:
	@printf "Cleaning target/ ...\n"
	-rm -rf $(TARGET_DIR)
