#pragma once

#include <Atrc/Editor/Camera.h>
#include <Atrc/Editor/EntityController.h>
#include <Atrc/Editor/ScriptBuilder.h>

class CameraInstance;
class FilmFilterInstance;
class RendererInstance;
class SamplerInstance;

class SceneExportingContext : public ScriptBuilder
{
public:

    const DefaultRenderingCamera *const activeCamera;

    const CameraInstance     *const camera;
    const FilmFilterInstance *const filmFilter;
    const SamplerInstance    *const sampler;

    const std::filesystem::path workspaceDirectory;
    const std::filesystem::path scriptDirectory;

    Vec2i outputFilmSize;

    const EntityController *entityController;

    SceneExportingContext(
        const DefaultRenderingCamera *activeCamera,
        const CameraInstance *camera,
        const FilmFilterInstance *filmFilter,
        const SamplerInstance *sampler,
        std::filesystem::path workspace, std::filesystem::path scriptDir,
        const Vec2i &outputFilmSize)
        : activeCamera(activeCamera),
          camera(camera),
          filmFilter(filmFilter),
          sampler(sampler),
          workspaceDirectory(std::move(workspace)), scriptDirectory(std::move(scriptDir)),
          outputFilmSize(outputFilmSize),
          entityController(nullptr)
    {

    }
};
