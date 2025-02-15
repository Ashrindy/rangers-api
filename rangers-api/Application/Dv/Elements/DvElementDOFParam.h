#pragma once

namespace app::dv{
    class DvElementDOFParam : public AppDvElementBase{
    public:
        struct Data {
        public:
            struct DOFParam {
            public:
                float focus;
                float focusRange;
                float nearDist;
                float farDist;
            };

            enum class Flags : unsigned int {
                USE_FOCUS_LOOK_AT,
                ENABLE_CIRCLE_DOF,
                DRAW_FOCAL_PLANE,
                UNK0
            };

            csl::ut::Bitset<Flags> flags;
            DOFParam param;
            DOFParam finishParam;
            float cocMaxRadius;
            float focalTransition;
            int bokehSampleCount;
            int bokehQuality;
            float bokehIntensity;
            float rtScale;
            float unk5[5];
            float curveData[32];
        };

        int framesOnScreen;
        bool jobGenerated;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementDOFParam)
    };
}