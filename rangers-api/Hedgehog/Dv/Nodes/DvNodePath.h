#pragma once

namespace hh::dv{
    class DvNodePath : public DvNodeBase {
    public:
        struct Data {
        public:
            csl::math::Matrix44 matrix;
        };

        float unk0;
        float unk1;
        Data binaryData;
        csl::math::Matrix44 worldMat;
        csl::math::Transform transform;
        long nodeSize;

        virtual void Setup(void* setupInfo) override;
        virtual void Update(int curFrame) override;
        virtual int GetUpdateTiming() override;

        DV_NODE_DECLARATION_BASE(DvNodePath)
    };
}