#ifndef GS_PLAYING_H
#define GS_PLAYING_H

#include "game_state.h"

#include <Urho3D/Graphics/Light.h>
#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Graphics/Animation.h>
#include <Urho3D/Graphics/AnimatedModel.h>
#include <Urho3D/Graphics/AnimationState.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/Skybox.h>
#include <Urho3D/UI/Button.h>
#include <Urho3D/UI/BorderImage.h>
#include <Urho3D/UI/CheckBox.h>
#include <Urho3D/UI/Font.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/UIEvents.h>
#include <Urho3D/UI/Window.h>
#include <Urho3D/UI/LineEdit.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/Engine/Application.h>
#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Input/InputEvents.h>
#include <Urho3D/Physics/PhysicsEvents.h>
#include <Urho3D/Physics/RigidBody.h>
#include <Urho3D/Physics/CollisionShape.h>
#include <Urho3D/Physics/PhysicsWorld.h>
#include <Urho3D/IO/Log.h>
#include <Urho3D/Graphics/ParticleEmitter.h>
#include <Urho3D/Graphics/ParticleEffect.h>

/// The game state handling playing a level.
class gs_playing : public game_state
{
public:
    Urho3D::Text* text_;
    Urho3D::Node* node_player;
    Urho3D::Node* node_player_model;
    Urho3D::RigidBody* body_player;
    double timer_playing=0;
    float goal_time=0;
    std::vector<Urho3D::Vector3> torch_positions;
    std::vector<Urho3D::Vector3> flag_positions;
    std::vector<Urho3D::Node*> flag_nodes;
    float cam_distance=14;
    float camera_yaw=20;
    float camera_pitch=20;
    bool rocks_spawned=false;
    Urho3D::Vector3 player_pos_last;
    Urho3D::AnimationState* player_stand;
    //Urho3D::AnimationState* player_walk;
    Urho3D::AnimationState* player_run;
    Urho3D::AnimationState* player_jump;
    Urho3D::AnimationState* player_reversing;
    Urho3D::ParticleEmitter* player_emitter_back;
    Urho3D::ParticleEmitter* player_emitter_front;
    Urho3D::ParticleEmitter* player_emitter_left;
    Urho3D::ParticleEmitter* player_emitter_right;

    gs_playing();
    void update(Urho3D::StringHash eventType,Urho3D::VariantMap& eventData);
    void HandleKeyDown(Urho3D::StringHash eventType,Urho3D::VariantMap& eventData);
    void spawn_torch(Urho3D::Vector3 pos);

    virtual const Urho3D::String& GetTypeName() const {static Urho3D::String name("gs_playing");return name;}   // this could be correct
};

#endif // GS_PLAYING_H
