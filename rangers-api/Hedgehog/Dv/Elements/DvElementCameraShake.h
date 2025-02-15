#pragma once

namespace hh::dv{
    class DvElementCameraShake : public DvElementBase {
    public:
        struct Data {
        public:
            int unk0;
            bool enabled;
            float intensity;
            float frequency;
            int unk2;
            int unk3;
            int unk4;
            int unk5;
        };

        Data binaryData;
        csl::math::Vector4 unk0;
        int unk1;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementCameraShake)
    };
}