#pragma once

namespace hh::gfx {
    class GOCOcclusionCapsule : public game::GOComponent, public fnd::HFrameListener {
    public:
        struct Capsule {
            hh::fnd::Reference<hh::fnd::HFrame> frame;
            int unk1;
            int pad1;
            char nodeName[128];
            hh::fnd::WorldPosition worldPos;
            csl::math::Vector3 scale;
            uint32_t unk2;
            uint32_t unk3;
            float unk4;
            uint32_t unk5;
            uint32_t unk6;
            float unk7;
            float unk8;
            float unk9;
        };

        uint64_t unk1;
        csl::ut::MoveArray<Capsule> capsules;
        int unk3;

		virtual void* GetRuntimeTypeInfo() override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void HFrameUpdatedCallback(const fnd::HFrame* frame, bool unkParam) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCOcclusionCapsule)
    };
}
