#include <Atrc/Common.h>
#include <Atrc/Material/BxDF.h>

AGZ_NS_BEG(Atrc)

Spectrum BxDF::AmbientRadiance(const Intersection &inct) const
{
    return SPECTRUM::BLACK;
}

AGZ_NS_END(Atrc)
