ifdef NDEBUG
	CMAKE_FLAGS := -DCMAKE_BUILD_TYPE=Release
	BUILD_DIR := build-release
else
	CMAKE_FLAGS := -DCMAKE_BUILD_TYPE=Debug
	BUILD_DIR := build
endif

JOBS ?= 4

.PHONY: test
test: build
	make -j$(JOBS) -C $(BUILD_DIR) test

.PHONY: build
build:
	cmake $(CMAKE_FLAGS) -S . -B $(BUILD_DIR)
	make -j$(JOBS) -C $(BUILD_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
