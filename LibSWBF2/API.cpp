#include "stdafx.h"
#include "API.h"
#include "Logger.h"

namespace LibSWBF2
{
	API void AddLogMessage(const char* message, const ELogType logType)
	{
		Logger::Add(message, logType);
	}

	API void GetLogMessages(const ELogType logType)
	{

	}
}