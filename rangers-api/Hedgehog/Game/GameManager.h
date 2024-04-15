#pragma once

namespace hh::game
{
	class alignas(8) GameStepListener
	{
	public:
		virtual ~GameStepListener() = default;
		virtual void PreStepCallback(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo) {}
		virtual void PostStepCallback(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo) {}
		virtual void UpdateCallback(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo) {}
	};
	
    class alignas(8) GamePauseListener {
	public:
		virtual ~GamePauseListener() = default;
        virtual void GPL_UnkFunc1() {}
        virtual void GPL_UnkFunc2() {}
    };

	class alignas(8) GameUpdateListener
	{
	public:
		virtual ~GameUpdateListener() = default;
		virtual void PreObjectUpdateCallback(GameManager* gameManager, void* unkParam) {}
		virtual void PostObjectUpdateCallback(GameManager* gameManager, void* unkParam) {}
	};

	class alignas(8) GameManagerListener
	{
	public:
		virtual ~GameManagerListener() = default;
		virtual void GameObjectAddedCallback(GameManager* gameManager, GameObject* gameObject) {}
		virtual void GameObjectRemovedCallback(GameManager* gameManager, GameObject* gameObject) {}
		virtual void GameServiceAddedCallback(GameService* gameService) {}
		virtual void GameServiceRemovedCallback(GameService* gameService) {}
		virtual void MessageProcessedCallback(GameManager* gameManager, const fnd::Message& msg) {}
		virtual void PreShutdownObjectCallback(GameManager* gameManager) {}
		virtual void PostShutdownObjectCallback(GameManager* gameManager) {}
		virtual void GML_UnkFunc8() {}
	};

	class GameManager;

	struct GameManagerOperation {
		enum class OperationId : uint8_t {
			SET_OBJECT_LAYER = 1,
			MAYBE_RELEASE_OBJECT = 4,
		};

		OperationId id;
		GameObject* gameObject;
		uint32_t layerId; // could be variable based on operation id, don't know yet
		uint32_t unk1;
		uint64_t unk2;
		uint64_t unk3; // unsure, just based off of array stride
	};
	class GameManagerOperationQueue : public fnd::ReferencedObject {
		GameManager* pGameManager;
		csl::ut::MoveArray<void*> unk1;
		csl::ut::MoveArray<GameManagerOperation> pendingOperations; // or maybe specifically layer operations
		fnd::MessageQueue messageQueue;
		csl::fnd::Mutex mutex;
	public:
		GameManagerOperationQueue(csl::fnd::IAllocator* pAllocator, GameManager* pGameManager);
		void ExecuteAllPendingLayerOperations();
	};

	class GameManagerCallbackUtil {
		static void FirePreShutdownObject(GameManager* gameManager);
		static void FirePostShutdownObject(GameManager* gameManager);
		static void FireGameObjectAdded(GameManager* gameManager, GameObject* gameObject);
		static void FireGameObjectRemoved(GameManager* gameManager, GameObject* gameObject);
		static void FireObjectLayerSet(GameManager* gameManager, GameObject* gameObject);
		static void FireMessageProcessed(GameManager* gameManager, const fnd::Message& message);
		static void FirePreObjectUpdate(GameManager* gameManager, void* unkParam); // probably GameStepInfo or UpdatingPhase
		static void FirePostObjectUpdate(GameManager* gameManager, void* unkParam); // probably GameStepInfo or UpdatingPhase
		static void FirePreStep(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo);
		static void FirePostStep(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo);
		static void FireUpdate(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo);
	};

	class GameObjectCallbackUtil {
		static void FireObjectLayerSet(GameObject* gameObject);
	};

	class GameApplication;

	struct WorldObjectCInfo;

	class GameManager : public fnd::ReferencedObject, public fnd::ReloaderListener, private csl::ut::NonCopyable
	{
		GameService* CreateService(GameServiceClass* gameServiceClass, csl::fnd::IAllocator* residentAllocator);
		static bool DispatchFunc(const fnd::Message& message, void* userData);
		void RiseMessageProcessed(const fnd::Message& message);
	public:
		uint32_t unk33;
		uint32_t unk34;
		void* unk35;
		csl::ut::FixedArray<GameObjectLayer*, 32> m_GameObjectLayers{};
		csl::ut::MoveArray<GameObject*> m_Objects{ pAllocator };
		csl::ut::MoveArray<GameService*> m_Services{ pAllocator };
		csl::ut::PointerMap<GameServiceClass*, GameService*> m_ServicesByClass{ pAllocator };
		csl::ut::MoveArray<GameObject*> shutdownObjects;
		csl::ut::MoveArray<GameManagerListener*> m_ManagerListeners{ pAllocator };
		csl::ut::MoveArray<void*> unk42; // csl::ut::MoveArray<GameObjectListener> m_ObjectListeners{ pAllocator };
		csl::ut::MoveArray<void*> unk43; // csl::ut::MoveArray<ComponentListener> m_ComponentListeners{ pAllocator };
		csl::ut::MoveArray<void*> unk44;
		csl::ut::MoveArray<void*> unk45;
		csl::ut::MoveArray<GamePauseListener*> m_PauseListeners{ pAllocator };
		csl::ut::MoveArray<GameStepListener*> m_StepListeners{ pAllocator };
		csl::ut::MoveArray<GameUpdateListener*> m_UpdateListeners{ pAllocator };
		csl::ut::MoveArray<void*> unk49;
		uint32_t unk50; // See GameManagerCallbackUtil::FirePostShutdownObject
		uint32_t unk50b;
		uint32_t unk51;
		csl::ut::MoveArray<void*> unk52;
		fnd::MessageQueue messageQueue;
		GameManagerOperationQueue* pOperationQueue;
		uint32_t unk55;
		GameApplication* pApplication;

		GameManager(csl::fnd::IAllocator* pAllocator, GameApplication* pApplication);
		virtual void PreResourceReloadCallback(fnd::ManagedResource* resource) override;
		virtual void PostResourceReloadCallback(fnd::ManagedResource* resource) override;

		static GameManager* instance;
		static GameManager* GetInstance();

		//template <typename T>
		//T* GetService()
		//{
		//	for (auto* pService : m_Services)
		//	{
		//		if (pService == nullptr)
		//			continue;

		//		if (strcmp(pService->pStaticClass->pName, T::GetServiceName()) == 0)
		//			return reinterpret_cast<T*>(pService);
		//	}
		//
		//	return { nullptr };
		//}

		//GameService* GetService(const char* in_pServiceName)
		//{
		//	for (auto* pService : m_Services)
		//	{
		//		if (pService == nullptr)
		//			continue;

		//		if (strcmp(pService->pStaticClass->pName, in_pServiceName) == 0)
		//			return pService;
		//	}

		//	return { nullptr };
		//}

		// template <typename T>
		// T* GetGameObject()
		// {
		// 	for (auto* pObject : m_Objects)
		// 	{
		// 		if (pObject == nullptr)
		// 			continue;

		// 		if (strcmp(pObject->pObjectName, T::GetObjectName()) == 0)
		// 			return reinterpret_cast<T*>(pObject);
		// 	}

		// 	return { nullptr };
		// }

		GameService* GetService(const GameServiceClass* gameServiceClass);

		template<typename T>
		T* GetService() {
			return static_cast<T*>(GetService(T::GetClass()));
		}

		GameObject* GetGameObject(const char* in_pObjectName)
		{
			for (auto* pObject : m_Objects)
			{
				if (pObject == nullptr)
					continue;

				if (strcmp(pObject->pObjectName, in_pObjectName) == 0)
					return pObject;
			}

			return { nullptr };
		}

		template<typename T>
		T* CreateService(csl::fnd::IAllocator* residentAllocator) {
			return static_cast<T*>(CreateService(T::GetClass(), residentAllocator));
		}

		csl::ut::MoveArray<GameService*>& GetServices() {
			return m_Services;
		}

		inline GameApplication* GetApplication() const {
			return pApplication;
		}

		void RegisterService(GameService* service);
		void UnregisterService(GameService* service);
		void RegisterObject(GameObject* object, fnd::WorldPosition* transform, GameObject* parent, const WorldObjectCInfo& cInfo);
		void RegisterNamedObject(GameObject* object, const char* name, bool copyName, fnd::WorldPosition* transform, GameObject* parent);
		void RegisterGameStepListener(GameStepListener& listener);
		void UnregisterGameStepListener(GameStepListener& listener);
		void RegisterGamePauseListener(GamePauseListener& listener);
		void UnregisterGamePauseListener(GamePauseListener& listener);
		void AddListener(GameManagerListener* listener);
		void RemoveListener(GameManagerListener* listener);
		void ReloadInputSettings(bool unkParam1);
		void ShutdownPendingObjects();
		void ClearAllGameObjects();
		void SendMessageToLayer(int layer, const fnd::Message& message);
		void SetObjectLayer(GameObject* gameObject, int layerId);
		void PerformMessages();
	};
}
