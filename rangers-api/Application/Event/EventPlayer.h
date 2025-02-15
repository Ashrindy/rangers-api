#pragma once

namespace app::evt {
    class EventPlayerListener {
    public:
        virtual void EPL_UnkFunc1() {}
        virtual void EPL_UnkFunc2() {}
        virtual void EPL_UnkFunc3() {}
        virtual void EPL_UnkFunc4() {}
        virtual void EPL_UnkFunc5() {}
        virtual void EPL_UnkFunc6() {}
        virtual void EPL_UnkFunc7() {}
        virtual void EPL_UnkFunc8() {}
        virtual void EPL_UnkFunc9() {}
    };

    class EventPlayer;

    struct EventSetupData {
    public:
        struct UnkStr {
        public:
            long long qword0;
            int dword8;
            long long qwordC;
            long long qword14;
            long long qword1C;
            long long qword24;
            long long qword2C;
            long long qword34;
            long long qword3C;
            int dword44;
            int dword48;
            int dword4C;
            char byte50;
        };

        struct UnkStr1 {
        public:
            long long unk7;
            bool unk9Toggle;
            csl::math::Vector3 unk9;

            void SetUnk9(csl::math::Vector3* unk9Value);
        };

        enum class PlayFlag : unsigned int {
            USE_SETUP_TRANSFORM, // uses the position, rotation and scale variables instead of the ones in the file
            STOP_FADE_OUT,       // whetever the cutscene should end or it should be in a limbo
            CANT_SKIP,           // whetever the cutscene is unskippable or not
            UNK0,                // unknown
            UNK1,                // unknown
            ENABLE_HUD,          // whetever the cockpit ui will show up
        };

        enum class PlayerFlag : unsigned char {
            USE_POSITION,   // set the player position from world position
            USE_ROTATION,   // set the player rotation from world position
            UNK0,           // unknown
        };

        char cutsceneName[40];
        char soundName[40];
        csl::math::Vector3 position;
        csl::math::Quaternion rotation;
        csl::math::Vector3 scale;
        int unk2;
        float speed;
        csl::ut::Bitset<PlayFlag> playFlags;
        UnkStr unkStr;
        long long unk4;
        char unk5;
        hh::fnd::ReferencedObject* owner0;
        hh::fnd::WorldPosition playerWorldPos;
        csl::ut::Bitset<PlayerFlag> playerFlags;
        char flags2;
        hh::fnd::ReferencedObject* owner1;
        UnkStr1 unkStr1;

        void Setup(const char* cutsceneName);
        static void SetName(char* name, const char* nameValue, long long unk);
        void SetCutsceneName(const char* name, long long unk){
            SetName(cutsceneName, name, unk);
        }
        void SetSoundName(const char* name, long long unk){
            SetName(soundName, name, unk);
        }
        void SetTransform(csl::math::Vector4* transform);
    };

    class EventScene : public hh::fnd::BaseObject, hh::dv::DvSceneControlListener {
    public:
        struct UnkStr0 {
        public:
            struct UnkStr1 {
            public:
                void* unkFnc0;
                void* unkFnc1;
                void* unkFnc2;
                char unk0;
            };
            UnkStr1 unkStrs[2];
            char unk0;
        };

        EventPlayer* evtPlayer;
        UnkStr0 unkStr;
        hh::dv::DiEventManager* diEvtMgr;
        EventSetupData setupData;
        void* resourceCollection;
        int unk0;
        int unk1;
        long long unk2;
        float unk3;
    };

    class EventSceneManager : public hh::fnd::BaseObject {
    public:
        EventPlayer* evtPlayer;
        csl::ut::MoveArray<EventScene*> evtScenes;
        csl::ut::MoveArray<csl::ut::VariableString> cutsceneNames;
    };

    class EventEnvironmentContext;

    class EventEnvironment : public hh::fnd::BaseObject {
    public:
        EventEnvironmentContext* evtEnvCtx;

        virtual bool EE_UnkFunc1() {}
        virtual bool EE_UnkFunc2() {}
        virtual void EE_UnkFunc3() {}
        virtual void EE_UnkFunc4() {}
        virtual void EE_UnkFunc5() {}
        virtual void EE_UnkFunc6() {}
        virtual void EE_UnkFunc7() {}
        virtual void EE_UnkFunc8() {}
        virtual void EE_UnkFunc9() {}
        virtual void EE_UnkFunc10() {}
        virtual void EE_UnkFunc11() {}
        virtual void EE_UnkFunc12() {}
        virtual void EE_UnkFunc13() {}
        virtual int EE_UnkFunc14() {}
        virtual void EE_UnkFunc15() {}
        virtual void EE_UnkFunc16() {}
    };

    class EventEnvironmentContext : public hh::fnd::BaseObject {
    public:
        EventPlayer* evtPlayer;
        EventSetupData setupData[2];
        app_cmn::camera::CameraParameter camParam;
        bool isPlaying;
    };

    class EventEnvironmentManager : public hh::fnd::BaseObject {
    public:
        EventEnvironmentContext* evtEnvCtx;
        csl::ut::MoveArray<EventEnvironment*> evtEnvs;
    };

    class EventPlayer : public hh::game::GameService, hh::game::GameStepListener, hh::game::GameManagerListener, hh::dv::DvSceneControlListener {
    public:
        class MyDvSceneControlListener {
        public:
            char id;
            EventPlayer* eventPlayer;

            virtual void* EventPlayerDtor();
            virtual void* GetEventPlayerRuntimeTypeInfo();
            virtual void* EventPlayerProcessMessage();
            virtual void KillDvSceneControl(int64_t a2);
            virtual void UnkFunc0() {};
            virtual void* EventPlayerIsAcceptingMessages();
            virtual void* EventPlayerOnAddedToGame();
            virtual void UnkFunc1() {};
            virtual void UnkFunc2() {};
            virtual void UnkFunc3() {};
            virtual void UnkFunc4() {};
            virtual void UnkFunc5() {};
            virtual void* EventPlayerUnk();
            virtual bool UnkFunc6() { return false; };
            virtual void UnkFunc7() {};
            virtual void UnkFunc8() {};
        };

        enum class Flag : unsigned long long {
            LOADING0  =    0x10000000,
            LOADING1  =    0x30000000,
            UNLOADING =    0x40000000,
            PLAYING   =   0x200000000,
            PAUSED    =   0x600000000,
            FADING    =  0x1000000000,
            UNK0      =  0x8000000000,
        };

        hh::ut::TinyFsm<EventPlayer, hh::ut::TinyFsmEvent> fsm;
        hh::dv::DiEventManager* diEvtMgr;
        long long unk0;
        MyDvSceneControlListener dvSceneControlListeners[2];
        csl::ut::MoveArray<EventPlayerListener*> listeners;
        EventSceneManager* evtSceneMgr;
        EventEnvironmentManager* evtEnvMgr;
        hh::fnd::Handle<hh::game::GameObject> fadeObject;
        int unk2;
        hh::fnd::Handle<hh::game::GameObject> eventLayerChecker;
        char unk4;
        int unk5;
        csl::ut::Bitset<Flag> flags;

        void AddListener(EventPlayerListener* listener);
        void RemoveListener(EventPlayerListener* listener);
        void PlayEvent(EventSetupData* setupData);
        bool IsPlaying();
        bool IsntPlaying();
        bool UnkFadeObjectFSM();

        virtual void* GetRuntimeTypeInfo() override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void OnAddedToGame() override;
        virtual void OnRemovedFromGame() override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
        virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
        virtual void GameServiceAddedCallback(hh::game::GameService* gameService) override;
        virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;
        virtual bool DSCL_UnkFunc1(void* unk0, void* unk1) override;
        virtual bool DSCL_UnkFunc2(void* unk0, void* unk1) override;
        virtual bool DSCL_UnkFunc3() override;
        virtual void OnCutsceneEnd() override;
        virtual bool DSCL_UnkFunc13(void* unk0) override;
        virtual bool DSCL_UnkFunc14() override;

        GAMESERVICE_CLASS_DECLARATION(EventPlayer)
    };
}
