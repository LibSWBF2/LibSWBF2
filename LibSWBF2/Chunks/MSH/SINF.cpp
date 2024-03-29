#include "pch.h"
#include "SINF.h"
#include "FileReader.h"
#include "FileWriter.h"

namespace LibSWBF2::Chunks::MSH
{
	void SINF::RefreshSize()
	{
		m_Name.RefreshSize();
		m_FrameInformation.RefreshSize();
		m_BoundingBox.RefreshSize();

		m_Size = m_Name.GetDataSize() + m_FrameInformation.GetDataSize() + m_BoundingBox.GetDataSize();
	}

	void SINF::WriteToStream(FileWriter& stream)
	{
		BaseChunk::WriteToStream(stream);
		m_Name.WriteToStream(stream);
		m_FrameInformation.WriteToStream(stream);
		m_BoundingBox.WriteToStream(stream);
	}

	void SINF::ReadFromStream(FileReader& stream)
	{
		BaseChunk::ReadFromStream(stream);

		while (ThereIsAnother(stream))
		{
			ChunkHeader head = stream.ReadChunkHeader(true);
		
			if (head == "NAME"_h)
			{
				m_Name.ReadFromStream(stream);
			}
			else if (head == "FRAM"_h)
			{
				m_FrameInformation.ReadFromStream(stream);
			}
			else if (head == "BBOX"_h)
			{
				m_BoundingBox.ReadFromStream(stream);
			}
			else
			{
				SkipChunk(stream);
			}
		}

		BaseChunk::EnsureEnd(stream);
	}
}