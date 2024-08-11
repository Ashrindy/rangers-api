#pragma once

namespace hh::needle {
    class ModelParamBuildJob : public ParamBuildJob {
    public:
        ModelRenderJobBase* modelRenderJob;
        virtual void Prepare(ParameterValueObject* parameters, PipelineInfo* pipelineInfo) override;
        virtual void Run(void* params, PipelineInfo* pipelineInfo, unsigned int viewportId, unsigned int parameterId) override;
    };
}