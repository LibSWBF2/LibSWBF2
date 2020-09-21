#pragma once
#include "Chunks/GenericChunk.h"
#include "Chunks/STR.h"

namespace LibSWBF2::Chunks::LVL::prim
{
    struct LIBSWBF2_API prim : public GenericChunk<"prim"_m>
    {
    public:
	    void RefreshSize() override;
	    void WriteToStream(FileWriter& stream) override;
	    void ReadFromStream(FileReader& stream) override;

        Types::String ToString() override;
        
        STR<"INFO"_m> *p_InfoHeader;
    };
}