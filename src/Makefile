CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -Wno-unused-parameter -g #-fmax-errors=1
LDFLAGS=-lcheck -pthread -lm
ifeq ($(shell uname), Linux)
	LDFLAGS += -lsubunit
endif

GCOVFLAGS=--coverage
GCOV_DIR=gcov

TEST_DIR=tests
SRC_DIR=operations
OBJ_DIR=obj
OBJ_DIR_GCOV=obj/$(GCOV_DIR)
OBJ_DIR_TEST=obj/$(TEST_DIR)

SRCS=$(wildcard $(SRC_DIR)/*.c)
SRCS_TEST=$(wildcard $(TEST_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
OBJS_TEST=$(patsubst $(TEST_DIR)/%.c,$(OBJ_DIR_TEST)/%.o,$(SRCS_TEST))
OBJS_GCOV=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR_GCOV)/%.o,$(SRCS))

LIB=s21_decimal.a
TEST=test

.PHONY: all $(TEST) $(LIB) gcov_report clean rebuild clang_n clang_i valgrind

all: $(LIB)

$(TEST): $(OBJS_GCOV) $(OBJS_TEST)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) $(GCOVFLAGS) -o $@
	./$@

$(LIB): $(OBJS)
	ar rcs $(LIB) $^
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_TEST)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(OBJ_DIR_TEST)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_GCOV)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR_GCOV)
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c $< -o $@

# gcov report with gcovr
gcov_report:
	mkdir -p $(GCOV_DIR)
	gcovr --html-details -o $(GCOV_DIR)/index.html --filter "$(SRC_DIR)/*"
	open $(GCOV_DIR)/index.html

# gcov report with lcov
lcov_report:
	mkdir -p $(GCOV_DIR)
	lcov -o $(GCOV_DIR)/Coverage_Report.info -c -d $(OBJ_DIR_GCOV)
	genhtml -o $(GCOV_DIR) $(GCOV_DIR)/Coverage_Report.info

clean:
	rm -rf $(OBJ_DIR) $(GCOV_DIR) $(TEST) $(LIB)

rebuild: clean all

clang_n:
	clang-format -n --style=Google *.[ch] $(SRC_DIR)/*.[ch] $(TEST_DIR)/*.[ch]

clang_i:
	clang-format -i --style=Google *.[ch] $(SRC_DIR)/*.[ch] $(TEST_DIR)/*.[ch]

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./$(TEST)
