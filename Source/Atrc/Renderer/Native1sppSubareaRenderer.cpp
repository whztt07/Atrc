#include <Atrc/Camera/Camera.h>
#include <Atrc/Renderer/Native1sppSubareaRenderer.h>

AGZ_NS_BEG(Atrc)

void Native1sppSubareaRenderer::Render(
    const Scene &scene, const Integrator &integrator,
    RenderTarget<Color3f> &output, const Subarea &area) const
{
    auto pw = output.GetWidth(), ph = output.GetHeight();
    for(uint32_t py = area.yBegin; py < area.yEnd; ++py)
    {
        Real y = Real(1) - Real(2) * (py + Real(0.5)) / ph;
        for(uint32_t px = area.xBegin; px < area.xEnd; ++px)
        {
            Real x = Real(2) * (px + Real(0.5)) / pw - Real(1);
            output(px, py) = integrator.GetRadiance(
                scene, scene.camera->GetRay({ x, y }));
        }
    }
}

AGZ_NS_END(Atrc)