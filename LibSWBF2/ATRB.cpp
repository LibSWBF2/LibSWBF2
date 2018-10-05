#include "stdafx.h"
#include "ATRB.h"

namespace LibSWBF2::Chunks::Mesh
{
	ATRB::ATRB()
	{

	}

	ATRB::~ATRB()
	{

	}

	void ATRB::RefreshSize()
	{
		m_Size = sizeof(uint8_t) + sizeof(uint8_t) + sizeof(uint8_t) + sizeof(uint8_t);
	}

	void ATRB::WriteToStream(FileWriter& stream)
	{
		BaseChunk::WriteToStream(stream);
		stream.WriteByte(m_RenderFlags);
		stream.WriteByte(m_RenderType);
		stream.WriteByte(m_Data0);
		stream.WriteByte(m_Data1);
	}

	void ATRB::ReadFromStream(FileReader& stream)
	{
		BaseChunk::ReadFromStream(stream);
		m_RenderFlags = (ERenderFlags)stream.ReadByte();
		m_RenderType = (ERenderType)stream.ReadByte();
		m_Data0 = stream.ReadByte();
		m_Data1 = stream.ReadByte();
	}
}