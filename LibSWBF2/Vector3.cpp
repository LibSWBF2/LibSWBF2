#include "stdafx.h"
#include "Vector3.h"

namespace LibSWBF2::Types
{
	Vector3::Vector3() : Vector2(), z(0)
	{
		
	}

	Vector3::Vector3(const float_t& x, const float_t& y, const float_t& z) : Vector2(x, y), z(z)
	{
		
	}

	Vector3::~Vector3()
	{

	}

	void Vector3::WriteToStream(FileWriter& stream)
	{
		stream.WriteFloat(x);
		stream.WriteFloat(y);
		stream.WriteFloat(z);
	}

	void Vector3::ReadFromStream(FileReader& stream)
	{
		x = stream.ReadFloat();
		y = stream.ReadFloat();
		z = stream.ReadFloat();
	}
}