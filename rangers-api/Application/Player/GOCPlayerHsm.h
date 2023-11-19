#pragma once

namespace app::player {
    class GOCPlayerHsm : public hh::game::GOComponent {
        uint64_t unk101;
        hh::ut::HsmBase hsm;
        uint64_t unk102;
        uint64_t unk103;
        uint64_t unk104;
        uint64_t unk105;
        uint32_t unk106;
        bool unk107;
        csl::ut::InplaceMoveArray<void*, 1> unk108;
        uint64_t unk109;
        uint64_t unk110;
        uint32_t unk111;
        uint64_t unk112;
        uint16_t unk113;
        bool unk114;
    public:
        struct Config {

        };

        GOCPlayerHsm(csl::fnd::IAllocator* pAllocator);
		virtual void* GetClassId() override;
		virtual void Update() override;
		virtual void GetDebugInfoMaybe() override;
		virtual bool ProcessMessage(hh::fnd::Message& msg) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        void Initialize(const Config& config);
        void SetState(uint32_t stateId, uint32_t unkParam1);

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerHsm);
    };
}
