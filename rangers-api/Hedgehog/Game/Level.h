#pragma once

namespace hh::game {
    class LevelListener {
    public:
        virtual ~LevelListener() = default;

        virtual void LL_UnkFunc1(void* unkParam1) {}
        virtual void LL_UnkFunc2(void* unkParam1) {}
        virtual void LL_UnkFunc3(void* unkParam1) {}
    };

    class MasterLevel;
    class Level : public fnd::ReferencedObject {
    public:
        csl::ut::VariableString name;
        MasterLevel* masterLevel;
        fnd::Reference<ResLevel> resource;
        csl::ut::InplaceMoveArray<csl::ut::VariableString, 2> files;
        fnd::Reference<fnd::ResourceLoader> resourceLoader;
        csl::ut::MoveArray<Level*> dependencies;
        csl::ut::InplaceMoveArray<LevelListener*, 1> listeners;
        bool loaded;
        uint16_t wordCA;
        uint32_t dwordCC;
        uint8_t byteD0;
        uint32_t dwordD4;
        csl::ut::VariableString unk1;
        csl::ut::VariableString unk2;

        CREATE_FUNC(Level, const char* name, MasterLevel* masterLevel);
        void Setup();

        void AddListener(LevelListener* listener);
        void RemoveListener(LevelListener* listener);
        void AddDependency(Level* dependency);
    };
}
