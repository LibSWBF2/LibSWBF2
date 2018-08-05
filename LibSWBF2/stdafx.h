// stdafx.h: Includedatei für Standardsystem-Includedateien
// oder häufig verwendete projektspezifische Includedateien,
// die nur in unregelmäßigen Abständen geändert werden.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Selten verwendete Komponenten aus Windows-Headern ausschließen
// Windows-Headerdateien:
#include <windows.h>



// TODO: Hier auf zusätzliche Header, die das Programm erfordert, verweisen.
#include <string>
#include <vector>
#include <fstream>
//#include "API.h"

namespace LibSWBF2
{
	using std::string;
	using std::vector;
	using std::ifstream;
	using std::ofstream;

	/*struct BaseChunk;
	struct MSH;
	struct SHVO;*/
}