#pragma once
#include "Chunks/LVL/prim/prim.h"
#include "Chunks/LVL/prim/prim.DATA.h"
#include "Chunks/LVL/prim/MASK.h"
#include "Chunks/LVL/wrld/XFRM.h"
#include "Chunks/STR.h"

#include "Types/Vector4.h"
#include "Types/Vector3.h"
#include "Types/Matrix3x3.h"


namespace LibSWBF2::Wrappers
{
	using namespace LibSWBF2::Chunks::LVL::prim;
	using namespace LibSWBF2::Chunks::LVL::wrld;
	using namespace LibSWBF2::Types;
	using namespace LibSWBF2::Chunks;

	class LIBSWBF2_API CollisionPrimitive
	{
		friend class Level;
		friend class List<CollisionPrimitive>;

		CollisionPrimitive() = default;
		

	private:
		DATA_PRIM *p_FieldsChunk;
		XFRM *p_TransformChunk;
		STR<"NAME"_m> *p_NameChunk;
		MASK *p_MaskChunk;

	public:
		static bool FromChunks(DATA_PRIM *fields, XFRM *transform, 
							STR<"NAME"_m> *name, MASK *mask,
							CollisionPrimitive& out);
		
		CollisionPrimitive(DATA_PRIM *fields, XFRM *transform, 
                           STR<"NAME"_m> *name, MASK *mask);

		String GetName() const;

		Vector4 GetRotation() const;
		Vector3 GetPosition() const;

		ECollisionPrimitiveType GetPrimitiveType() const;
		ECollisionMaskFlags GetMaskFlags() const;

		bool GetCubeDims(float_t& xOut, float_t& yOut, float_t& zOut) const;
		bool GetCylinderDims(float_t& radiusOut, float_t& heightOut) const;
		bool GetSphereRadius(float_t &radiusOut) const;
		
		String ToString() const;
	};
}