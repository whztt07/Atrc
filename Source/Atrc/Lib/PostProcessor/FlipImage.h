#pragma once

#include <Atrc/Lib/Core/PostProcessor.h>

namespace Atrc
{
    
class FlipImage : public PostProcessor
{
public:

    void Process(Image *image) const noexcept override;
};

} // namespace Atrc
