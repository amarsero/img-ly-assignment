class PipelineStage {
public:
	enum class Actions { DecodeImage, DecompressData, ParseJson };
	std::vector<Actions> actions;
};