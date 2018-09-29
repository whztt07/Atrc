#include "../Core/Entity.h"
#include "PureColor.h"

AGZ_NS_BEG(Atrc)

PureColorBRDF::PureColorBRDF(const Spectrum &color)
    : color_(color)
{

}

BxDFType PureColorBRDF::GetType() const
{
    return CombineBxDFTypes(BxDFType::Ambient, BxDFType::Reflection);
}

Spectrum PureColorBRDF::Eval(
    const EntityIntersection &sl, const Vec3r &wi, const Vec3r &wo) const
{
    return SPECTRUM::BLACK;
}

Option<BxDFSample> PureColorBRDF::Sample(
    const EntityIntersection &sl, const Vec3r &wo, SampleSeq2D &samSeq,
    BxDFType type) const
{
    return None;
}

Real PureColorBRDF::PDF(
    const EntityIntersection &sl, const Vec3r &wi, const Vec3r &wo) const
{
    return Real(0);
}

Spectrum PureColorBRDF::AmbientRadiance() const
{
    return color_;
}

PureColorMaterial::PureColorMaterial(const Spectrum &color)
    : color_(color)
{

}

RC<BxDF> PureColorMaterial::GetBxDF(const SurfaceLocal &sl) const
{
    return MakeRC<PureColorBRDF>(color_);
}

AGZ_NS_END(Atrc)
