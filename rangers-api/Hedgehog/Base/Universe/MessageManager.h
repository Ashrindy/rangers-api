#pragma once

namespace hh::fnd {
    class MessageManager : public BaseObject, public csl::fnd::Singleton<MessageManager> {
		static bool DispatchCallback(Message& message, void* userData);
    public:
        MessageQueue queue;
        MessageManager(csl::fnd::IAllocator* allocator);
        static MessageManager* Create();
        Message* AddMessage(Message& message);
        void AddObject(Messenger* messenger);
        void RemoveObject(Messenger* messenger);
        void Dispatch();
        static HandleManager* handleManager;
        static Messenger* GetMessengerByHandle(const Handle<Messenger>& messenger);
    };
}