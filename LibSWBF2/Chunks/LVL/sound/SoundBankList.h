#pragma once
#include "SoundBaseChunk.h"
//#include "Types/SoundBankHeader.h"

namespace LibSWBF2::Chunks::LVL::sound
{
	//using Types::SoundBankHeader;

	struct SampleBank;

	struct LIBSWBF2_API SoundBankList : public SoundBaseChunk<"SoundBankList"_fnv>
	{
		//SoundBankHeader m_SoundBankHeader;

		List<SampleBank *> m_SampleBanks;


		void RefreshSize() override;
		void WriteToStream(FileWriter& stream) override;
		void ReadFromStream(FileReader& stream) override;

		String ToString() const override;
	};
}