#pragma once

namespace hh::physics {
    class PhysicsWorldBullet : public PhysicsWorld, public game::GameManagerListener {
        // uint32_t unk201[32];
        // uint64_t unk202;
        // uint64_t unk203;
        // uint64_t unk204;
        // uint64_t unk205;
        // uint64_t unk206;
        // uint64_t unk207;

        virtual uint64_t UnkFunc1() override;
        virtual uint64_t UnkFunc2() override;
        virtual uint64_t UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual uint64_t UnkFunc5() override;
        virtual uint64_t UnkFunc6() override;
        virtual uint64_t PerformRayCastClosest() override;
        virtual uint64_t PerformRayCastAllHits() override;
        virtual uint64_t UnkFunc9() override;
        virtual uint64_t UnkFunc10() override;
        virtual uint64_t UnkFunc11() override;
        virtual uint64_t UnkFunc12() override;
        virtual uint64_t UnkFunc13() override;
        virtual void PostShutdownObjectCallback(game::GameManager* gameManager) override;

        GAMESERVICE_CLASS_DECLARATION(PhysicsWorldBullet)
    };
}
