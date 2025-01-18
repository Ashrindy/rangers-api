#pragma once

namespace app::level {
    class ResMasterLevel;
}

namespace hh::game {
    class MasterLevelListener {
    public:
        virtual ~MasterLevelListener() = default;
        virtual void MLL_UnkFunc1(uint64_t unkParam1, uint64_t unkParam2, uint64_t unkParam3) {}
        virtual void MLL_UnkFunc2() {}
        virtual void MLL_UnkFunc3() {}
    };

    class MasterLevel : public fnd::ReferencedObject, public LevelListener {
    public:
        fnd::Reference<app::level::ResMasterLevel> resource;
        csl::ut::MoveArray<Level*> levels;
        csl::ut::StringMap<Level*> levelsByName;
        csl::ut::InplaceMoveArray<MasterLevelListener*, 1> listeners;
        csl::ut::MoveArray<void*> unk4;

        DEFAULT_CREATE_FUNC(MasterLevel);
        virtual void LL_UnkFunc1(void* unkParam1) override;
        virtual void LL_UnkFunc2(void* unkParam1) override;
        virtual void LL_UnkFunc3(void* unkParam1) override;

        Level* GetLevel(const char* name) const;
    };
}
