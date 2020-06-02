#include "stdafx.h"
#include "MTRL.h"

namespace LibSWBF2::Chunks::LVL::modl
{
    void MTRL::RefreshSize()
    {
        throw std::runtime_error("Not implemented!");
    }

    void MTRL::WriteToStream(FileWriter& stream)
    {
        throw std::runtime_error("Not implemented!");
    }

    void MTRL::ReadFromStream(FileReader& stream)
    {
        BaseChunk::ReadFromStream(stream);

        m_Flags = (EMaterialFlags)stream.ReadUInt32();
        m_DiffuseColor.ReadFromStream(stream);
        m_SpecularColor.ReadFromStream(stream);
        m_SpecularExponent = stream.ReadUInt32();
        m_Unknown[0] = stream.ReadUInt32();
        m_Unknown[1] = stream.ReadUInt32();
        m_AttachedLight = stream.ReadString();

        BaseChunk::EnsureEnd(stream);
    }

    String MTRL::ToString()
    {
        return
            "Flags = " + MaterialFlagsToString(m_Flags) + "\n" +
            "Diffuse Color = " + m_DiffuseColor.ToString() + "\n" +
            "Specular Color = " + m_SpecularColor.ToString() + "\n" +
            "Specular Exponent = " + std::to_string(m_SpecularExponent).c_str() + "\n" +
            "Attached Light = " + m_AttachedLight;
    }
}