#pragma once

#define GOCOMPONENT_CLASS_DECLARATION(ClassName) private:\
		static const hh::game::GOComponentClass* instance;\
		static ClassName* Create(csl::fnd::IAllocator* allocator);\
	public:\
		static const hh::game::GOComponentClass* GetClass();

namespace app::player
{
	class Sonic;
}

namespace hh::game
{
	class GOComponent;
	class GameObject;
	class GOComponentClass
	{
	public:
		const char* pName;
		void* inheritanceChain{};
		GOComponentClass* parent{};
		const char* dynamicName;
		size_t size;
        GOComponent* (*instantiator)(csl::fnd::IAllocator* pAllocator);
		void* unk1;
		void* unk2;
	};
	
	class GOComponent : public fnd::RefByHandleObject
	{
	public:
		enum class GOCEventMask : uint16_t {
			WANT_DEACTIVATE_EVENT = 2,
			WANT_UPDATE_SET_EDITOR = 0x200,
		};

		enum class GOCEvent {
			ACTIVATE = 0,
			DEACTIVATE,
			MESSAGE_768,
			UNK3,
			UNK4,
			UNK5,
			OBJECT_LAYER_CHANGED,
		};

		struct Unk1 {
			int64_t unk39;
			int64_t unk40;
		};

		uint32_t flags;
		int32_t unk45;
		GameObject* pOwnerGameObject{};
		csl::ut::Bitset<GOCEventMask> gocEventMask;
		uint16_t unk47;
		char flags38; // seen 0, 1, 2
		uint16_t unk49;
		char unk50;
		uint32_t nameHash;
		uint32_t messageMask;
		GOComponentClass* pStaticClass{};
		Unk1 unknown43[3];

		GOComponent(csl::fnd::IAllocator* pAllocator);
		virtual ~GOComponent();

		virtual void* GetClassId();
		virtual void Update() {}
		virtual void GetDebugInfoMaybe();
		virtual bool ProcessMessage(fnd::Message& msg) { return false; }
		virtual bool fUnk5() { return false; }
		virtual void LoadReflection(const fnd::RflClass& rflClass) {}

		/*
		 * When event is OBJECT_LAYER_CHANGED, data contains previous layer id.
		 */
		virtual void OnGOCEvent(GOCEvent event, GameObject& ownerGameObject, void* data) {}

		static GOComponent* Create(GameObject& ownerGameObject, const GOComponentClass& componentClass);

		inline GameObject* GetOwnerGameObject() {
			return pOwnerGameObject;
		}

		GOComponent* GetComponentByClass(const GOComponentClass& componentClass) const;

		template<typename T>
		GOComponent* GetComponent() const {
			GetComponentByClass(T::GetClass());
		}

		void SetNameHash(const char* name);
	};
}
