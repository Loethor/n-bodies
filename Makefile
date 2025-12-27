BUILD_DIR := build

.PHONY: all
all:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake ..
	@cd $(BUILD_DIR) && $(MAKE)

.PHONY: run
run: all
	@$(BUILD_DIR)/app

.PHONY: test
test: all
	@cd $(BUILD_DIR) && ctest --output-on-failure

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
