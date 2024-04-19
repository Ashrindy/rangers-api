#pragma once

namespace app::game {
    // This name is guessed.
    class GameModeResourceCollection
        : public hh::fnd::ReferencedObject
    {
    public:
        struct Unk1 {
            uint32_t unk1;
            uint32_t unk2;
            const char* name;
            uint64_t unk3;
        };
        csl::ut::MoveArray<Unk1> resources;

        DEFAULT_CREATE_FUNC(GameModeResourceCollection)
    };
}
