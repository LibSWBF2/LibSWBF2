#pragma once
#include "BaseChunk.h"
#include "SINF.h"
#include "MATL.h"

namespace LibSWBF2::Chunks::Mesh
{
	struct MSH2 : public BaseChunk
	{
		MSH2();
		~MSH2();

		void RefreshSize() override;
		void WriteToStream(FileWriter& stream) override;
		void ReadFromStream(FileReader& stream) override;

	private:
		SINF m_SINF;
		MATL m_MATL;
	};
}