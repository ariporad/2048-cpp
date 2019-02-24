SRC_DIR=src

CPP_FILES=$(wildcard $(SRC_DIR)/*.cpp)
HEADER_FILES=$(wildcard $(SRC_DIR)/*.hpp)
OUT_FILE=2048-cpp

CLANG=/usr/bin/clang++
CLANG_OPTS=$(CPP_FILES) -std=c++17 -o $(OUT_FILE)

$(OUT_FILE): $(CPP_FILES) $(HEADER_FILES)
	@$(CLANG) $(CLANG_OPTS)
