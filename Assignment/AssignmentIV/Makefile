# Compilers
CC      := gcc
CXX     := g++

# Flags
CFLAGS   := -std=c23 -Wall -Wextra -Wpedantic -g
CXXFLAGS := -std=c++23 -Wall -Wextra -Wpedantic -g

# ==== C version executables ====
C_BIN0 := C/hash_function
C_BIN1 := C/hash_function_1

# ==== C++ version executables ====
CXX_BIN0 := CXX/hash_function_cpp
CXX_BIN1 := CXX/hash_function_cpp_1

# ===== Default: build everything =====
all: $(C_BIN0) $(C_BIN1) $(CXX_BIN0) $(CXX_BIN1)

# ===== C builds =====
$(C_BIN0): C/main.o C/hash_fn.o
	$(CC) $(CFLAGS) -o $@ $^

$(C_BIN1): C/main_1.o C/hash_fn_1.o
	$(CC) $(CFLAGS) -o $@ $^

# ===== C++ builds =====
$(CXX_BIN0): CXX/main.o CXX/hash_fn.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(CXX_BIN1): CXX/main_1.o CXX/hash_fn_1.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# ==== Object file rules ====
C/%.o: C/%.c
	$(CC) $(CFLAGS) -c $< -o $@

CXX/%.o: CXX/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Convenience targets
c: $(C_BIN0) $(C_BIN1)
cxx: $(CXX_BIN0) $(CXX_BIN1)

clean:
	$(RM) C/*.o CXX/*.o $(C_BIN0) $(C_BIN1) $(CXX_BIN0) $(CXX_BIN1)

.PHONY: all clean c cxx
