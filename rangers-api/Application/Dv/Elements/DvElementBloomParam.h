#pragma once

namespace app::dv{
    class DvElementBloomParam : public AppDvElementBase{
    public:
        struct Data {
        public:
            struct Parameters {
            public:
                float bloom;
                float sampleRadius;
                float blurQuality;
            };

            bool enabled;
            Parameters minParams;
            Parameters maxParams;
            float unk5[4];
            float curveData[32];
        };

        bool jobGenerated;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementBloomParam)
    };
}