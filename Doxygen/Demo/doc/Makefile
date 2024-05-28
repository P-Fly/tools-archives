doc:
	@echo Gen $@
	@mkdir -p $(BUILD_DOC_DIR)
	@cp doxygen.cfg.in $(BUILD_DOC_DIR)/doxygen.cfg
	@sed -i s:[@]top_srcdir[@]:..:g $(BUILD_DOC_DIR)/doxygen.cfg
	@sed -i s:[@]VERSION[@]:$(VERSION):g $(BUILD_DOC_DIR)/doxygen.cfg
	@sed -i s:[@]BUILD_DOC_DIR[@]:$(BUILD_DOC_DIR):g $(BUILD_DOC_DIR)/doxygen.cfg
	@doxygen $(BUILD_DOC_DIR)/doxygen.cfg
