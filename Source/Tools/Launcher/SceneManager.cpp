﻿#include "SceneManager.h"

using namespace AGZ;
using namespace ObjMgr;

void SceneManager::Initialize(const ConfigGroup &params)
{
    if(IsAvailable())
        throw SceneInitializationException("Scene: reinitialized");

    // 摄像机

    auto camera = GetSceneObject<Atrc::Camera>(params["camera"], arena_);

    std::vector<Atrc::Entity*> entities;
    std::vector<Atrc::Light*> lights;

    // 创建实体

    auto &entArr = params["entities"].AsArray();
    for(size_t i = 0; i < entArr.Size(); ++i)
    {
        auto ent = EntityManager::GetInstance().GetSceneObject(entArr[i], arena_);
        if(!ent)
            throw SceneInitializationException("SceneManager: unknown entity type");
        entities.push_back(ent);
        
        auto light = ent->AsLight();
        if(light)
            lights.push_back(light);
    }

    // 创建光源

    auto &lgtArr = params["lights"].AsArray();
    for(size_t i = 0; i < lgtArr.Size(); ++i)
    {
        auto light = LightManager::GetInstance().GetSceneObject(lgtArr[i], arena_);
        if(!light)
            throw SceneInitializationException("SceneManager: unknown light type");
        lights.push_back(light);
    }

    scene_.camera = camera;

    for(auto ent : entities)
        scene_.entities_.push_back(ent);
    for(auto lgt : lights)
        scene_.lights_.push_back(lgt);

    for(auto light : lights)
        light->PreprocessScene(scene_);
}

bool SceneManager::IsAvailable() const
{
    return scene_.camera != nullptr;
}

const Atrc::Scene &SceneManager::GetScene() const
{
    if(!IsAvailable())
        throw SceneInitializationException("Scene: uninitialized");
    return scene_;
}