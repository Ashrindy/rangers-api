#pragma once

#include "External/helpers.h"
// #include "External/sigscan.h"

// // Lua 5.4.1
// #include "External/Lua541/include/lua.hpp"

// Common Sonicteam Library

#ifndef EXPORTING_TYPES
#include "Sonicteam/math/math.h"
#include <functional>
#endif

// Why does the Win32 API do this...
#ifdef UpdateResource
#undef UpdateResource
#endif

#include "Sonicteam/System/IAllocator.h"

#include "Sonicteam/Utility/collections/Array.h"
#include "Sonicteam/Utility/collections/FixedArray.h"
#include "Sonicteam/Utility/collections/HashMap.h"
#include "Sonicteam/Utility/collections/LinkList.h"
#include "Sonicteam/Utility/collections/MoveArray.h"
#include "Sonicteam/Utility/collections/MoveArray32.h"
#include "Sonicteam/Utility/collections/InPlaceMoveArray.h"
#include "Sonicteam/Utility/collections/PointerMap.h"
#include "Sonicteam/Utility/collections/StringMap.h"
#include "Sonicteam/Utility/Hash.h"
#include "Sonicteam/Utility/BasicString.h"
#include "Sonicteam/Utility/Bitset.h"
#include "Sonicteam/Utility/Color.h"
#include "Sonicteam/Utility/NonCopyable.h"
#include "Sonicteam/Utility/Pair.h"
#include "Sonicteam/Utility/String.h"
#include "Sonicteam/Utility/VariableString.h"

#include "Sonicteam/System/Singleton.h"
#include "Sonicteam/System/Mutex.h"
#include "Sonicteam/System/HeapBase.h"
#include "Sonicteam/System/TlsfHeap.h"
#include "Sonicteam/System/FreeListHeap.h"
#include "Sonicteam/System/Delegate.h"

#include "Hedgehog/Rsdx/hhMTSimpleJobJoint.h"
#include "Hedgehog/Rsdx/hhmtjobdispatchfunctions.h"

#include "Hedgehog/System/hhAllocator.h"
#include "Hedgehog/System/SingletonInitNode.h"

// Hedgehog Library
#include "Hedgehog/Base/System/MemoryRouter.h"
#include "Hedgehog/Base/System/hhBaseObject.h"
#include "Hedgehog/Base/System/hhReferencedObject.h"
#include "Hedgehog/Base/System/RefByHandleObject.h"
#include "Hedgehog/Base/System/hhProperty.h"
#include "Hedgehog/Base/System/hhCollection.h"
#include "Hedgehog/Base/System/HFrame.h"
#include "Hedgehog/Base/System/HandleManager.h"
#include "Hedgehog/Base/System/hhHandle.h"
#include "Hedgehog/Base/System/ReloaderListener.h"
#include "Hedgehog/Base/System/SUpdateInfo.h"
#include "Hedgehog/Base/System/UpdatingPhase.h"

// Hedgehog Universe Library
#include "Hedgehog/Base/Universe/hhMessenger.h"
#include "Hedgehog/Base/Universe/hhMessage.h"
#include "Hedgehog/Base/Universe/MessageQueue.h"
#include "Hedgehog/Base/Universe/MessageManager.h"

#include "Hedgehog/Utility/TempString.h"
#include "Hedgehog/Utility/TempMoveArray.h"
#include "Hedgehog/Utility/FSM/TinyFsm.h"
#include "Hedgehog/Utility/FSM/StateDesc.h"
#include "Hedgehog/Utility/FSM/State.h"
#include "Hedgehog/Utility/FSM/Hsm.h"
#include "Hedgehog/Utility/BinaryFile.h"
#include "Hedgehog/Utility/AabbTree.h"

#include "Hedgehog/Base/Type/hhBaseTypes.h"
#include "Hedgehog/Base/Type/WorldPosition.h"
#include "Hedgehog/Base/Type/LogData.h"
#include "Hedgehog/Base/Type/Triangle.h"
#include "Hedgehog/Base/Type/Geometry.h"
#include "Hedgehog/Base/Type/WireGeometry.h"

#include "Hedgehog/Cri/CriSystem.h"

#include "Hedgehog/Filesystem/FileInfo.h"
#include "Hedgehog/Filesystem/FileBind.h"

// Resources
#include "Hedgehog/Resource/Uri.h"
#include "Hedgehog/Resource/InplaceUri.h"
#include "Hedgehog/Resource/InplaceTempUri.h"
#include "Hedgehog/Resource/File.h"
#include "Hedgehog/Resource/ResourceNameResolver.h"
#include "Hedgehog/Resource/FilePathResolver.h"
#include "Hedgehog/Resource/ManagedResource.h"
#include "Hedgehog/Resource/ResourceTypeRegistry.h"
#include "Hedgehog/Resource/ResourceContainer.h"
#include "Hedgehog/Resource/SimpleResourceContainer.h"
#include "Hedgehog/Resource/StaticResourceContainer.h"
#include "Hedgehog/Resource/DynamicResourceContainer.h"
#include "Hedgehog/Resource/Packfile.h"
#include "Hedgehog/Resource/ResourceLoader.h"
#include "Hedgehog/Resource/ResourceManagerRelatedUnk1.h"
#include "Hedgehog/Resource/ResourceManager.h"
#include "Hedgehog/Resource/ResourceResolver.h"
#include "Hedgehog/Resource/FilePathResolverUtil.h"
#include "Hedgehog/Resource/FileCache.h"
#include "Hedgehog/Resource/FileLoader.h"

#include "Hedgehog/Rsdx/rsdx_noncopyable.h"
#include "Hedgehog/Needle/Utility/Binhash.h"
#include "Hedgehog/Needle/Types.h"
#include "Hedgehog/Needle/Rectangle.h"
#include "Hedgehog/Needle/Box.h"
#include "Hedgehog/Needle/EntryLink.h"
#include "Hedgehog/Needle/RsFlagMask.h"
#include "Hedgehog/Needle/CScratchMemoryContext.h"
#include "Hedgehog/Needle/NeedleObject.h"
#include "Hedgehog/Needle/NeedleRefcountObject.h"
#include "Hedgehog/Needle/Utility/intrusive_ptr.h"
#include "Hedgehog/Needle/NeedleSStr.h"
#include "Hedgehog/Needle/NeedleRefcountResource.h"
#include "Hedgehog/Needle/TNeedleRefcountResource.h"
#include "Hedgehog/Needle/TNeedleRefcountUniqueObjectBase.h"
#include "Hedgehog/Needle/CNameIDObject.h"
#include "Hedgehog/Needle/CNameIDObjectStatic.h"
#include "Hedgehog/Needle/SRawImageInfo.h"
#include "Hedgehog/Needle/ParameterValue.h"
#include "Hedgehog/Needle/MirageResource.h"
#include "Hedgehog/Needle/SurfaceBase.h"
#include "Hedgehog/Needle/Texture.h"
#include "Hedgehog/Needle/Buffer.h"
#include "Hedgehog/Needle/ConstantBuffer.h"
#include "Hedgehog/Needle/VertexShader.h"
#include "Hedgehog/Needle/PixelShader.h"
#include "Hedgehog/Needle/ComputeShader.h"
#include "Hedgehog/Needle/VertexLayout.h"
#include "Hedgehog/Needle/RenderTarget.h"
#include "Hedgehog/Needle/UnorderedAccessView.h"
#include "Hedgehog/Needle/DepthStencil.h"
#include "Hedgehog/Needle/MaterialResource.h"
#include "Hedgehog/Needle/MeshResource.h"
#include "Hedgehog/Needle/Model.h"
#include "Hedgehog/Needle/ModelInstance.h"
#include "Hedgehog/Needle/PBRModelInstance.h"
#include "Hedgehog/Needle/RenderingCommandList.h"

#include "Hedgehog/Needle/ViewportSetting.h"
#include "Hedgehog/Needle/UnorderedAccessViewsSetting.h"
#include "Hedgehog/Needle/RenderTargetsSetting.h"
#include "Hedgehog/Needle/SamplerStateSetting.h"

#include "Hedgehog/Needle/RenderingDeviceContext.h"
#include "Hedgehog/Needle/RenderingDevice.h"
#include "Hedgehog/Needle/ParameterValueObjectContainer.h"
#include "Hedgehog/Needle/PrimitiveRenderer.h"
#include "Hedgehog/Needle/Renderable.h"
#include "Hedgehog/Needle/FxCamera.h"
#include "Hedgehog/Needle/SceneContext.h"
#include "Hedgehog/Needle/SceneContextManager.h"
#include "Hedgehog/Needle/SupportFX.h"
#include "Hedgehog/Needle/SceneParamContainer.h"
#include "Hedgehog/Needle/RenderingPipeline.h"
#include "Hedgehog/Needle/GatherRenderingPassContext.h"
#include "Hedgehog/Needle/WorldRenderingPipelineExecContext.h"
#include "Hedgehog/Needle/WorldRenderingPipeline.h"
#include "Hedgehog/Needle/RenderTexturePipeline.h"
#include "Hedgehog/Needle/RenderingPipelineRangers.h"
#include "Hedgehog/Needle/RenderUnit.h"
#include "Hedgehog/Needle/RenderTexture.h"

#include "Hedgehog/Needle/ImplDX11/Types.h"
#include "Hedgehog/Needle/ImplDX11/NeedleResourceContainer.h"
// #include "Hedgehog/Needle/ImplDX11/SDevStatus.h"
#include "Hedgehog/Needle/ImplDX11/CmdNeedleRefcountObject.h"
#include "Hedgehog/Needle/ImplDX11/TextureDX11Impl.h"
#include "Hedgehog/Needle/ImplDX11/BufferDX11Impl.h"
#include "Hedgehog/Needle/ImplDX11/ShaderDX11Impl.h"
#include "Hedgehog/Needle/ImplDX11/VertexLayoutImpl.h"
#include "Hedgehog/Needle/ImplDX11/SResourceInfo.h"
#include "Hedgehog/Needle/ImplDX11/SResourceContext.h"
#include "Hedgehog/Needle/ImplDX11/SShaderContext.h"
#include "Hedgehog/Needle/ImplDX11/DevicUniqueObjectContainerDX11.h"
#include "Hedgehog/Needle/ImplDX11/SFlushParameterContext.h"
#include "Hedgehog/Needle/ImplDX11/SParameterQueue.h"
#include "Hedgehog/Needle/ImplDX11/SParameterBuffer.h"
#include "Hedgehog/Needle/ImplDX11/RenderingDeviceDispatchDX11.h"
#include "Hedgehog/Needle/ImplDX11/DeviceObjectDX11.h"
#include "Hedgehog/Needle/ImplDX11/RenderingDeviceContextDX11.h"
#include "Hedgehog/Needle/ImplDX11/RenderingDeviceDX11.h"

#include "Hedgehog/GraphicsFoundation/ResTexture.h"
#include "Hedgehog/GraphicsFoundation/Renderable.h"
#include "Hedgehog/GraphicsFoundation/RenderableContainer.h"
#include "Hedgehog/GraphicsFoundation/ViewportData.h"
#include "Hedgehog/GraphicsFoundation/SharedDebugDrawResource.h"
#include "Hedgehog/GraphicsFoundation/SharedDebugDrawResourceNeedle.h"
#include "Hedgehog/GraphicsFoundation/DrawContext.h"
#include "Hedgehog/GraphicsFoundation/DrawContextNeedle.h"
#include "Hedgehog/GraphicsFoundation/GraphicsGeometry.h"
#include "Hedgehog/GraphicsFoundation/GraphicsGeometryNeedle.h"
#include "Hedgehog/GraphicsFoundation/GraphicsContext.h"
#include "Hedgehog/GraphicsFoundation/DrawSystem.h"
#include "Hedgehog/GraphicsFoundation/DrawSystemNeedle.h"

#include "Hedgehog/Font/ResBitmapFont.h"
#include "Hedgehog/Font/TextListener.h"
#include "Hedgehog/Font/FontContainer.h"

// Hedgehog Framework
#include "Hedgehog/Framework/LocalHeap.h"
#include "Hedgehog/Framework/EventStack.h"
#include "Hedgehog/Framework/Window.h"
#include "Hedgehog/Framework/WindowD3D11.h"
#include "Hedgehog/Framework/FrameworkEnvironment.h"
#include "Hedgehog/Framework/BaseFramework.h"
#include "Hedgehog/Framework/FrameworkWin32.h"
#include "Hedgehog/Framework/Framework.h"
#include "Hedgehog/Framework/AppModule.h"
#include "Hedgehog/Framework/Application.h"

// HID
#include "Hedgehog/HID/InputDevice.h"
#include "Hedgehog/HID/InputDeviceFactory.h"
#include "Hedgehog/HID/ActiveDeviceManager.h"
#include "Hedgehog/HID/InputMap.h"

#include "Hedgehog/HID/InputDevices/Keyboard.h"
#include "Hedgehog/HID/InputDevices/KeyboardWin32.h"
#include "Hedgehog/HID/InputDevices/Mouse.h"
#include "Hedgehog/HID/InputDevices/MouseWin32.h"
#include "Hedgehog/HID/InputDevices/Gamepad.h"
#include "Hedgehog/HID/InputDevices/GamepadSteam.h"
#include "Hedgehog/HID/InputDevices/Pointing.h"
#include "Hedgehog/HID/InputDevices/PointingWin32.h"
#include "Hedgehog/HID/InputDevices/Vibration.h"
#include "Hedgehog/HID/InputDevices/VibrationWin32.h"

#include "Hedgehog/HID/DeviceManager.h"
#include "Hedgehog/HID/DeviceManagerWin32.h"

// // // System Messages
// // #include "System/Messages/MsgRobChaosEmerald.h"
#include "Hedgehog/Game/ObjectId.h"

// Hedgehog Reflection Library
#include "Hedgehog/Reflection/ResReflection.h"
#include "Hedgehog/Reflection/hhInternalClassMember.h"
#include "Hedgehog/Reflection/hhRflEntity.h"
#include "Hedgehog/Reflection/hhRflArray.h"
#include "Hedgehog/Reflection/hhRflCustomAttribute.h"
#include "Hedgehog/Reflection/hhRflClassMember.h"
#include "Hedgehog/Reflection/hhRflClassEnum.h"
#include "Hedgehog/Reflection/hhRflClass.h"
#include "Hedgehog/Reflection/hhRflTypeInfo.h"
#include "Hedgehog/Reflection/hhRflRegistry.h"
#include "Hedgehog/Reflection/hhRflTypeInfoRegistry.h"
#include "Hedgehog/Reflection/hhRflClassNameRegistry.h"
#include "Hedgehog/Reflection/hhBuiltinTypeRegistry.h"
// #include "Hedgehog/Reflection/hhDataResource.h"
#include "Hedgehog/Reflection/hhDataValue.h"
// #include "Hedgehog/Reflection/hhVariantDataUtil.h"
// #include "Hedgehog/Reflection/hhRflSerializeUtil.h"
#include "Application/Reflection/Types.h"

#include "Hedgehog/Debug/Messages.h"
#include "Hedgehog/Debug/ViewerContext.h"
#include "Hedgehog/Debug/Viewer.h"
#include "Hedgehog/Debug/ViewerContextManager.h"
#include "Hedgehog/Debug/ViewerManager.h"

// Hedgehog Game Library
#include "Hedgehog/Game/GameService.h"
#include "Hedgehog/Game/GameObject.h"
#include "Hedgehog/Game/GameObjectLayer.h"
#include "Hedgehog/Game/GOComponent.h"
#include "Hedgehog/Game/GameManager.h"
#include "Hedgehog/Game/GameJobQueue.h"
#include "Hedgehog/Game/GameUpdater.h"
#include "Hedgehog/Game/BucketedGameUpdater.h"
#include "Hedgehog/Game/GameApplication.h"
#include "Hedgehog/Game/InputManager.h"
#include "Hedgehog/Game/InputComponent.h"
#include "Hedgehog/Game/CameraComponent.h"
#include "Hedgehog/Game/CameraManager.h"
#include "Hedgehog/Game/ObjInfo.h"
#include "Hedgehog/Game/ObjInfoContainer.h"
#include "Hedgehog/Game/GameObjectRegistry.h"
#include "Hedgehog/Game/GOComponentRegistry.h"
#include "Hedgehog/Game/ObjInfoRegistry.h"
#include "Hedgehog/Game/GameObjectSystem.h"
#include "Hedgehog/Game/ErrorViewer.h"
#include "Hedgehog/Game/GameViewerContext.h"
#include "Hedgehog/Game/ObjectViewerContext.h"
#include "Hedgehog/Game/ServiceViewerContextBase.h"
#include "Hedgehog/Game/GameViewerBase.h"
#include "Hedgehog/Game/MousePickingViewer.h"
#include "Hedgehog/Game/ResObjectWorld.h"
#include "Hedgehog/Game/ObjectMap.h"
#include "Hedgehog/Game/ObjectDataAccessor.h"
#include "Hedgehog/Game/WorldObjectStatus.h"
#include "Hedgehog/Game/ObjectWorldChunk.h"
#include "Hedgehog/Game/ObjectWorldChunkLayer.h"
#include "Hedgehog/Game/ObjectWorldChunk.def.h"
#include "Hedgehog/Game/ObjectWorldExtension.h"
#include "Hedgehog/Game/ObjectWorld.h"

#include "Hedgehog/Game/GOComponents/GOCInput.h"
#include "Hedgehog/Game/GOComponents/GOCTransform.h"
#include "Hedgehog/Game/GOComponents/GOCActivator.h"

#include "Hedgehog/Game/DevMenu/Menu.h"
#include "Hedgehog/Game/FreeCamera.h"

#include "Hedgehog/GraphicsFoundation/RenderManagerBase.h"

#include "Hedgehog/Graphics/NeedleRenderer.h"
#include "Hedgehog/Graphics/RenderingWorld.h"
#include "Hedgehog/Graphics/RenderingComponent.h"
#include "Hedgehog/Graphics/Components/CriComponent.h"
#include "Hedgehog/Graphics/Components/LightComponent.h"
#include "Hedgehog/Graphics/Components/CaptureComponent.h"
#include "Hedgehog/Graphics/Components/ScreenShotComponent.h"
#include "Hedgehog/Graphics/RenderingEngine.h"
#include "Hedgehog/Graphics/RenderingEngineNeedle.h"
#include "Hedgehog/Graphics/RenderingEngineRangers.h"
#include "Hedgehog/Graphics/RenderManager.h"
#include "Hedgehog/Graphics/ResMaterial.h"
#include "Hedgehog/Graphics/GOCVisual.h"
#include "Hedgehog/Graphics/GOCVisualTransformed.h"
#include "Hedgehog/Graphics/GOCVisualModel.h"
#include "Hedgehog/Graphics/GOCVisualDebugDraw.h"
#include "Hedgehog/Graphics/VisualManager.h"
#include "Hedgehog/Graphics/VisibilityManager.h"
#include "Hedgehog/Graphics/FxParamEditor.h"

#include "Hedgehog/Physics/ShapeHolder.h"
#include "Hedgehog/Physics/EventQueue.h"
#include "Hedgehog/Physics/GOCCollider.h"
#include "Hedgehog/Physics/GOCSphereCollider.h"
#include "Hedgehog/Physics/GOCBoxCollider.h"
#include "Hedgehog/Physics/GOCCapsuleCollider.h"
#include "Hedgehog/Physics/GOCCylinderCollider.h"
#include "Hedgehog/Physics/PhysicsWorld.h"
#include "Hedgehog/Physics/PhysicsWorldBullet.h"
#include "Hedgehog/Physics/PhysicsViewerContext.h"
#include "Hedgehog/Physics/PhysicsViewerBase.h"
#include "Hedgehog/Physics/PhysicsMousePickingViewer.h"
#include "Hedgehog/Physics/PhysicsPickedObjectViewer.h"
#include "Hedgehog/Physics/BulletPhysicsModule.h"

#include "Hedgehog/Sound/GOCSound.h"

#include "Hedgehog/Animation/Trigger.h"
#include "Hedgehog/Animation/Bindable.h"
#include "Hedgehog/Animation/BindableCollection.h"
#include "Hedgehog/Animation/SkeletalMeshBinding.h"
#include "Hedgehog/Animation/SkeletonBlender.h"
#include "Hedgehog/Animation/ResAnimation.h"
#include "Hedgehog/Animation/ResAnimator.h"
#include "Hedgehog/Animation/AsmResourceManager.h"
#include "Hedgehog/Animation/BlendTreeSyncContext.h"
#include "Hedgehog/Animation/BlendNode.h"
#include "Hedgehog/Animation/AnimationInternalState.h"
#include "Hedgehog/Animation/AnimationStateMachine.h"
#include "Hedgehog/Animation/GOCAnimation.h"
#include "Hedgehog/Animation/GOCAnimationSingle.h"
#include "Hedgehog/Animation/GOCAnimator.h"
#include "Hedgehog/Animation/AnimationManager.h"
#include "Hedgehog/Animation/AnimationInterface.h"

#include "SurfRide/Types.h"
#include "SurfRide/Color.h"
#include "SurfRide/Math.h"
#include "SurfRide/Base.h"
#include "SurfRide/ReferencedObject.h"
#include "SurfRide/BinaryData.h"
#include "SurfRide/Transform.h"
#include "SurfRide/Cell.h"
#include "SurfRide/Text.h"
#include "SurfRide/Camera.h"
#include "SurfRide/Animation.h"
#include "SurfRide/UserData.h"
#include "SurfRide/Effects/Effect.h"
#include "SurfRide/Effects/Blur.h"
#include "SurfRide/Effects/Reflect.h"
#include "SurfRide/Casts/Cast.h"
#include "SurfRide/Casts/ImageCast.h"
#include "SurfRide/Casts/ReferenceCast.h"
#include "SurfRide/Casts/SliceCast.h"
#include "SurfRide/Layer.h"
#include "SurfRide/Scene.h"
#include "SurfRide/Project.h"
#include "SurfRide/Calc.h"

#include "Hedgehog/Text/ConverseTextListener.h"
#include "Hedgehog/Text/ConverseData.h"
#include "Hedgehog/Text/ConverseDataCollection.h"
#include "Hedgehog/Text/TagReplaceable.h"
#include "Hedgehog/Text/TagReplaceableCollection.h"
#include "Hedgehog/Text/TagReplacer.h"
#include "Hedgehog/Text/TextLanguageData.h"
#include "Hedgehog/Text/TextLanguageDataCollection.h"
#include "Hedgehog/Text/TextAppModule.h"

#include "Hedgehog/UI/ResSurfRideProject.h"
#include "Hedgehog/UI/SurfRideProjectContext.h"
#include "Hedgehog/UI/SurfRideHandle.h"
#include "Hedgehog/UI/Types.h"
#include "Hedgehog/UI/GOCSprite.h"
#include "Hedgehog/UI/LayerController.h"
#include "Hedgehog/UI/TextListenerObject.h"
#include "Hedgehog/UI/UITextInterface.h"
#include "Hedgehog/UI/TextObjectUpdater.h"
#include "Hedgehog/UI/GOCUICollider.h"
#include "Hedgehog/UI/GOCUIComposition.h"
#include "Hedgehog/UI/UIObject.h"
#include "Hedgehog/UI/UIElementBase.h"
#include "Hedgehog/UI/UIElement.h"
#include "Hedgehog/UI/UIElementGroup.h"
#include "Hedgehog/UI/UIElementGroupContainer.h"
#include "Hedgehog/UI/UITextElement.h"
#include "Hedgehog/UI/CastTextContainer.h"
#include "Hedgehog/UI/UIPanel.h"
#include "Hedgehog/UI/UIStackPanel.h"
#include "Hedgehog/UI/UIGridPanel.h"
#include "Hedgehog/UI/UIScrollBarElement.h"
#include "Hedgehog/UI/UIListViewElement.h"
#include "Hedgehog/UI/UIListener.h"
#include "Hedgehog/UI/UIManager.h"

#include "Hedgehog/User/UserInfoEvent.h"

// #include "System/Player/PlayerInformation.h"
// #include "System/Player/Blackboard.h"
// #include "System/Player/BlackboardBattle.h"
// #include "System/Player/Player.h"
// #include "System/Player/Sonic.h"


// // System Game Object Components
// #include "System/Player/goc/goc_PlayerBlackboard.h"
// #include "System/Player/goc/goc_PlayerKinematicParams.h"

// #include "System/AppResourceManagerListener.h"

// // Save
// #include "System/Save/SaveManagerListener.h"

// // Services
// #include "System/Services/service_LevelInfo.h"
// #include "System/Services/service_PhotoMode.h"
// #include "System/Services/service_UIOverlay.h"

// // HUD
// #include "System/HUD/RequestOverlayBegin.h"
// #include "System/HUD/RequestOverlayTagReplace.h"
// #include "System/HUD/RequestOverlayCaption.h"

// #include "System/Script/ScriptSequence.h"

// Builtin RflCustomAttributes
// #include "ApplicationCommon/Reflection/CaptionAttribute.h"
// #include "ApplicationCommon/Reflection/RangeAttribute.h"


#include "ApplicationCommon/FSM/GOCTinyFsm2.h"
#include "ApplicationCommon/FSM/GOCHsm2.h"

#include "ApplicationCommon/Camera/Types.h"
#include "ApplicationCommon/Camera/CameraExtension.h"
#include "ApplicationCommon/Camera/CameraController.h"
#include "ApplicationCommon/Camera/CameraInterpolator.h"
#include "ApplicationCommon/Camera/CameraFrame.h"
#include "ApplicationCommon/Camera/GOCCamera.h"
#include "ApplicationCommon/Camera/Messages.h"

#include "Application/Utilities/PriorityList.h"
#include "Application/Utilities/SendMessage.h"

#include "Application/Foundation/AppHeapManager.h"
#include "Application/Foundation/AppMessage.h"

#include "Application/FSM/StateContext.h"

#include "Application/Resource/AppResourceManager.h"

#include "Application/Save/SaveDataAccessor.h"
#include "Application/Save/SaveManager.h"
#include "Application/Save/Accessors/OptionData.h"

#include "Application/Camera/CameraBridge.h"
#include "Application/Camera/CameraService.h"

#include "Application/Player/CharacterId.h"
#include "Application/Player/PlayerCounterTimer.h"
#include "Application/Player/PlayerHsmContext.h"
#include "Application/Player/Blackboard/BlackboardContent.h"
#include "Application/Player/Blackboard/BlackboardAmy.h"
#include "Application/Player/Blackboard/BlackboardSpeed.h"
#include "Application/Player/Blackboard/BlackboardItem.h"
#include "Application/Player/Blackboard/BlackboardBattle.h"
#include "Application/Player/Blackboard/BlackboardStatus.h"
#include "Application/Player/Blackboard/BlackboardTails.h"
#include "Application/Player/Blackboard/Blackboard.h"
#include "Application/Player/Blackboard/GOCPlayerBlackboard.h"
#include "Application/Player/StateParameter.h"
#include "Application/Player/RelayedFlagsParameter.h"
#include "Application/Player/PlayerStateParameter.h"
#include "Application/Player/StatePlugin/StatePlugin.h"
#include "Application/Player/StatePlugin/StatePluginManager.h"
#include "Application/Player/StatePlugin/StatePluginBoost.h"
#include "Application/Player/StatePlugin/StatePluginCyberStart.h"
#include "Application/Player/GravityController.h"
#include "Application/Player/GOCPlayerHsm.h"
#include "Application/Player/GOCPlayerState.h"
#include "Application/Player/GOCPlayerParameter.h"
#include "Application/Player/GOCPlayerKinematicParams.h"
#include "Application/Player/ComponentCollector.h"
#include "Application/Player/VisualLocatorManager.h"
#include "Application/Player/PlayerVisual.h"
#include "Application/Player/GOCPlayerVisual.h"
#include "Application/Player/PlayerStateBase.h"
#include "Application/Player/States.h"
#include "Application/Player/PlayerStateBase.h"
#include "Application/Player/Messages.h"

#include "Application/Player/Player.h"
#include "Application/Player/Characters/Sonic.h"
#include "Application/Player/Characters/Tails.h"
#include "Application/Player/Characters/Amy.h"
#include "Application/Player/Characters/Knuckles.h"

#include "Application/Level/PlayerInformation.h"
#include "Application/Level/StageData.h"
#include "Application/Level/StageInfo.h"
#include "Application/Level/LevelInfo.h"
#include "Application/Level/ResLevel.h"
#include "Application/Level/ResMasterLevel.h"
#include "Application/Level/LevelManager.h"

#include "Application/Sound/CustomSound.h"

#include "Application/Text/AppTextListener.h"
#include "Application/Text/TextManager.h"

#include "Application/UI/AppUITextInterface.h"
#include "Application/UI/UIMusicSelect.h"
#include "Application/UI/Messages.h"

#include "Application/Game/GameCondition.h"
#include "Application/Game/GameModeResourceCollection.h"
#include "Application/Game/GameModeResourceModule.h"
#include "Application/Game/StageTerrainModule.h"
#include "Application/Game/StageObjectModule.h"
#include "Application/Game/GameModeResourceManager.h"
#include "Application/Game/GameMode.h"
#include "Application/Game/GameModeStage.h"
#include "Application/Game/GameModeExtension.h"
#include "Application/Game/GameModeLayerStatusExtension.h"
#include "Application/Game/TimeService.h"
#include "Application/Game/ApplicationExtension.h"
#include "Application/Game/ApplicationSequenceExtension.h"
#include "Application/Game/MenuSelect.h"
#include "Application/Game/GOCEvent.h"
#include "Application/Game/GOCEventCollision.h"
#include "Application/Game/GOCActionNotifier.h"
#include "Application/Game/Messages.h"

#include "Application/Event/EventPlayer.h"

#include "Application/Graphics/SceneParameters.h"
#include "Application/Graphics/FxParamManager.h"
#include "Application/Graphics/FxParamTimeProgressExtension.h"
#include "Application/Graphics/FxColManager.h"

#include "Application/Terrain/TerrainManager.h"

#include "Application/VolumeTrigger.h"
#include "Application/MyApplication.h"
#include "Application/IslandObjInfo.h"
#include "Application/ObjSwitchVolume.h"
#include "Application/ObjCamera.h"
#include "Application/ObjCameraVolume.h"
