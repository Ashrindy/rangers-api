#pragma once

#define PLAYER_VISUAL_CLASS_DECLARATION_BASE(ClassName) private:\
		static const app::player::PlayerVisualClass playerVisualClass;\
    public:\
		static app::player::PlayerVisual* Create(csl::fnd::IAllocator* allocator, hh::game::GameObject* gameObject, ComponentCollection* componentCollection);\
		ClassName(csl::fnd::IAllocator* allocator, hh::game::GameObject* gameObject, ComponentCollection* componentCollection);

#define PLAYER_VISUAL_CLASS_DECLARATION(ClassName) PLAYER_VISUAL_CLASS_DECLARATION_BASE(ClassName)\
	public:\
		static const app::player::PlayerVisualClass* GetClass();

#define PLAYER_VISUAL_CLASS_DECLARATION_INLINE_GET_CLASS(ClassName) PLAYER_VISUAL_CLASS_DECLARATION_BASE(ClassName)\
	public:\
		static inline const app::player::PlayerVisualClass* GetClass() {\
			return &RESOLVE_STATIC_VARIABLE(playerVisualClass);\
		}

namespace app::player {
    class PlayerVisual;

    class PlayerVisualListener {
    public:
        virtual void PVL_UnkFunc1(void* unkParam1, void* unkParam2) = 0;
        virtual void PVL_UnkFunc2(void* unkParam1, void* unkParam2) = 0;
    };

    struct PlayerVisualClass {
        unsigned int nameHash;
        PlayerVisual* (*instantiator)(csl::fnd::IAllocator* allocator);
    };

    class GOCPlayerVisual;
    class PlayerVisual : public hh::fnd::ReferencedObject {
        hh::game::GameObject* gameObject;
        GOCPlayerVisual* gocPlayerVisual;
        ComponentCollection* componentCollection;
        hh::fnd::Reference<EffectList> effectList;
        uint16_t unk2;
    public:
        PlayerVisual(csl::fnd::IAllocator* allocator, hh::game::GameObject* gameObject, ComponentCollection* componentCollection);

        virtual unsigned int GetNameHash() const = 0;
        virtual void Initialize(hh::game::GameObject* gameObject, ComponentCollection* componentCollection) = 0;
        virtual void SetupEffects() {}
        virtual void UnkFunc4() {}
        virtual void UnkFunc5();
        virtual void UnkFunc6();
        virtual void Init() = 0;
        virtual void Deinit() = 0;

        Component& GetComponent(int id) const;
        hh::anim::GOCAnimator* GetComponentAnimator(char componentId) const;

        bool ChangeComponentAnimatorState(char componentId, const char* state);
        bool ChangeComponentAnimatorStateWithoutTransition(char componentId, const char* state);
        bool ChangeComponentAnimatorToNull(char componentId);
        bool ChangeComponentAnimatorToNull(char componentId, int unkParam);
        void SetComponentAnimatorActiveStateLocalTime(char componentId, float time);
        void SetComponentAnimatorPlaybackSpeed(char componentId, float speed);
        bool GetComponentAnimatorFloat(char componentId, const char* variableName, float* value);
        bool SetComponentAnimatorFloat(char componentId, const char* variableName, float value);
        // bool SetDefaultComponentAnimatorFloat(const char* variableName, float value);
        void AttachComponent(char componentId, hh::fnd::HFrame* frame);
        void DetachComponent(char componentId);

        void SetupEffectList(unsigned int effectCount);
    };
}
