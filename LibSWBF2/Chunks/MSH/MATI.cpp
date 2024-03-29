#include "pch.h"
#include "MATI.h"
#include "FileReader.h"
#include "FileWriter.h"

namespace LibSWBF2::Chunks::MSH
{
	void MATI::RefreshSize()
	{
		m_Size = sizeof(int32_t);
	}

	void MATI::WriteToStream(FileWriter& stream)
	{
		BaseChunk::WriteToStream(stream);
		stream.WriteInt32(m_MaterialIndex);
	}

	void MATI::ReadFromStream(FileReader& stream)
	{
		BaseChunk::ReadFromStream(stream);
		m_MaterialIndex = stream.ReadInt32();
		BaseChunk::EnsureEnd(stream);
	}
}