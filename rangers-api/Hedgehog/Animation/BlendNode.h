#pragma once

namespace hh::anim {
    class BlendNodeBase : public fnd::ReferencedObject {
    public:
        enum class Flag : uint16_t {
            UNK1 = 1,
            UNK2 = 2,
            UNK3 = 3,
            UNK10 = 10,
        };
    public:

        BlendNodeType type;
        bool hasTargetNodeInTree; // hasTargetNode? see SetTargetNode
        csl::ut::Bitset<Flag> flags;
        float blendFactor;
        BlendNodeBase* parent;
        BlendNodeBase* hierarchyRoot;
        csl::ut::InplaceMoveArray<BlendNodeBase*, 2> children;

        BlendNodeBase(BlendNodeType type);

        virtual void* GetRuntimeTypeInfo() const;
        virtual bool Accept() { return true; }
        virtual bool UnkFunc3() { return false; }
        virtual uint64_t UnkFunc4();
        virtual void UpdateWeight(BlendTreeSyncContext& syncContext, float weight) = 0;
        virtual void UpdateMotionWeight(BlendTreeSyncContext& syncContext, float weight) = 0;
        virtual uint64_t GetLocalBlendMaskImpl() const = 0;
        virtual unsigned int SyncLocalBlendMask() const {}
        virtual void ResetBlendMask(const char* mask);
        virtual bool UnkFunc10() { return false; }
        virtual uint64_t UnkFunc11();
        virtual void UnkFunc12() {}
        virtual void UnkFunc13() {}
        void SetHierarchyRoot(BlendNodeBase* root);
        void ClearChildren();

        // uint64_t Accept(BlendTreeVisitor& visitor);
        uint64_t CalcDescendantFlag();
        uint64_t CopyVariableToMember(float variable);
        uint64_t GetLocalBlendMask() const;
        bool HasBlendMask() const;
        uint64_t MarkBlendMaskDirty();
        uint64_t ResetBlendMask(const uint8_t* unkParam);
        uint64_t SetWeight(float weight);
        void SyncAll(BlendTreeSyncContext& syncContext);
        void AddChild(BlendNodeBase* child);
        void RemoveChild(BlendNodeBase* child);
    };

    class BlendNodeParameter : public Bindable {
    public:
        BlendNodeBase* blendNode;
        short variableIndex;
        short unk102;
        float value;

        virtual void Bind(float value, void* unkParam) override;
    };

    class ClipNode : public BlendNodeBase {
    public:
        uint8_t unk101;
        short clipIndex;
        float weight;
        fnd::Reference<AnimationControl> animationControl;
        AsmResourceManager::BlendMaskInfo* blendMask;

        CREATE_FUNC(ClipNode, const AsmResourceManager& resourceManager, int clipIndex, bool multiCycle);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool Accept() override;
        virtual bool UnkFunc3() override;
        virtual void UpdateWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual void UpdateMotionWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual uint64_t GetLocalBlendMaskImpl() const override;
        virtual void ResetBlendMask(const char* mask) override;
        virtual void UnkFunc13() override;
    };

    class LayerBlendNode : public BlendNodeBase {
        BlendNodeBase* targetNode;
        AsmResourceManager::BlendMaskInfo* blendMaskInfo;
        csl::ut::MoveArray<void*>* unk6; // -> refers to unk5 in asmresourcemanager
        csl::ut::MoveArray<void*> unk7; // sized by bone count

    public:
        CREATE_FUNC(LayerBlendNode, const AsmResourceManager& resourceManager, LayerData* layer)

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool Accept() override;
        virtual bool UnkFunc3() override;
        virtual void UpdateWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual void UpdateMotionWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual uint64_t GetLocalBlendMaskImpl() const override;
        virtual unsigned int SyncLocalBlendMask() const override;
        void SetTargetNode(BlendNodeBase* node);
    };

    class BranchBlendNode : public BlendNodeBase {
    public:
        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool Accept() override;
        virtual bool UnkFunc3() override;
        virtual void UpdateMotionWeight(BlendTreeSyncContext& syncContext, float weight) override;

    };

    class LerpBlendNode : public BranchBlendNode {
    public:
        csl::ut::MoveArray<BlendNodeBase*> blendChildren;
        BlendNodeParameter blendFactor;
        int currentChild;
        float unk102;

        CREATE_FUNC(LerpBlendNode, csl::ut::MoveArray<BlendNodeBase*>& children, AsmResourceManager* asmResourceManager, short variableIndex);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual uint64_t UnkFunc4() override;
        virtual void UpdateWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual void UpdateMotionWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual uint64_t GetLocalBlendMaskImpl() const override;
        virtual unsigned int SyncLocalBlendMask() const override;
        virtual bool UnkFunc10() override;
        virtual uint64_t UnkFunc11() override;
        virtual void UnkFunc12() override;
    };

    class AdditiveBlendNode : public BranchBlendNode {
    public:
        CREATE_FUNC(AdditiveBlendNode, BlendNodeBase* node1, BlendNodeBase* node2, int unkParam);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void UpdateWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual void UpdateMotionWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual uint64_t GetLocalBlendMaskImpl() const override;
        virtual bool UnkFunc10() override;
        virtual uint64_t UnkFunc11() override;
        virtual void UnkFunc12() override;
    };

    class OverrideBlendNode : public BranchBlendNode {
    public:
        CREATE_FUNC(OverrideBlendNode, BlendNodeBase* node1, BlendNodeBase* node2, int unkParam);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void UpdateWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual void UpdateMotionWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual uint64_t GetLocalBlendMaskImpl() const override;
        virtual bool UnkFunc10() override;
        virtual uint64_t UnkFunc11() override;
        virtual void UnkFunc12() override;
    };

    class TwoPointLerpBlendNode : public BranchBlendNode {
    public:
        virtual void* GetRuntimeTypeInfo() const override;
        virtual void UpdateWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual void UpdateMotionWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual uint64_t GetLocalBlendMaskImpl() const override;
        virtual unsigned int SyncLocalBlendMask() const override;
        virtual void UnkFunc12() override;
    };

    class MulBlendNode : public BranchBlendNode {
    public:
        virtual void* GetRuntimeTypeInfo() const override;
        virtual void UpdateWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual void UpdateMotionWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual uint64_t GetLocalBlendMaskImpl() const override;
        virtual unsigned int SyncLocalBlendMask() const override;
        virtual void UnkFunc12() override;
    };

    class BlendSpaceNode : public BranchBlendNode {
    public:
        BlendSpaceData* blendSpaceData;
        csl::ut::MoveArray<void*> unk1;
        BlendNodeParameter xParam;
        BlendNodeParameter yParam;
        char unk2;
        short containingTriangleIndex;
        csl::math::Vector2 position;
        float blendFactor[3];

        BlendSpaceNode(csl::fnd::IAllocator* allocator, AsmResourceManager* asmResourceManager, BlendSpaceData* blendSpaceData);

        static BlendSpaceNode* Create(csl::fnd::IAllocator* allocator, const csl::ut::MoveArray<BlendNodeBase*> children, AsmResourceManager* asmResourceManager, int blendSpaceIndex);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual uint64_t UnkFunc4() override;
        virtual void UpdateWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual void UpdateMotionWeight(BlendTreeSyncContext& syncContext, float weight) override;
        virtual uint64_t GetLocalBlendMaskImpl() const override;
        virtual unsigned int SyncLocalBlendMask() const override;
        virtual bool UnkFunc10() override;
        virtual uint64_t UnkFunc11() override;
        virtual void UnkFunc12() override;

        int GetContainingTriangleIndex(const csl::math::Vector2& point) const;
    };
}
