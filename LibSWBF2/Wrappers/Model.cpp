#include "stdafx.h"
#include "Level.h"
#include "InternalHelpers.h"

namespace LibSWBF2::Wrappers
{
	bool Model::FromChunk(Level* mainContainer, modl* modelChunk, Model& out)
	{
		if (mainContainer == nullptr)
		{
			LOG_ERROR("Given mainContainer was NULL!");
			return false;
		}
		if (modelChunk == nullptr)
		{
			LOG_ERROR("Given modelChunk was NULL!");
			return false;
		}

		out.p_Model = modelChunk;

		List<segm*>& segments = modelChunk->m_Segments;
		for (size_t i = 0; i < segments.Size(); ++i)
		{
			Segment segment;
			if (Segment::FromChunk(mainContainer, segments[i], segment))
			{
				out.m_Segments.Add(segment);
			}
		}
		return true;
	}

	String Model::GetName() const
	{
		return p_Model->p_Name->m_Text;
	}

	const List<Segment>& Model::GetSegments() const
	{
		return m_Segments;
	}
}