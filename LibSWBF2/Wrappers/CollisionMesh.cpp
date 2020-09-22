#include "stdafx.h"
#include "CollisionMesh.h"
#include "InternalHelpers.h"
#include <stdint.h>


namespace LibSWBF2::Wrappers
{
    bool CollisionMesh::FromChunk(coll *collChunk, CollisionMesh& out)
    {
        if (collChunk == nullptr)
        {
            return false;
        }
        out = CollisionMesh(collChunk);
        return true;
    }
    
    CollisionMesh::CollisionMesh(coll *collChunk) : p_CollisionChunk(collChunk) {}


    String CollisionMesh::GetName() const
    {
        return p_CollisionChunk -> p_ChunkName -> ToString();
    }

    void CollisionMesh::GetIndexBuffer(ETopology requestedTopology, uint32_t& count, uint32_t*& indexBuffer)
    {
        if (requestedTopology != ETopology::TriangleList || p_CollisionChunk == nullptr)
        {
            count = 0;
            return;
        }

        if (m_Indicies.Size() == 0) //lazy load
        {
            List<TREE_LEAF *>& leaves = p_CollisionChunk -> p_Tree -> m_Leaves;
            
            for (int i = 0; i < leaves.Size(); i++)
            {
                m_Indicies.Append(TriangleStripToTriangleList(leaves[i] -> m_Indicies));
            }
        }

        count       = m_Indicies.Size();
        indexBuffer = m_Indicies.GetArrayPtr();
    }

    void CollisionMesh::GetVertexBuffer(uint32_t& count, Vector3*& vertexBuffer) const
    {
    	if (p_CollisionChunk== nullptr)
    	{
    		count = 0;
    		return;
    	}

    	List<Vector3>& verts = p_CollisionChunk -> p_Verts -> m_Verts;
        count = verts.Size();
        vertexBuffer = verts.GetArrayPtr();
    }
        
    String CollisionMesh::ToString() const
    {
    	if (p_CollisionChunk == nullptr)
    	{
    		return "";
    	}

        return p_CollisionChunk -> p_ChunkName -> ToString() + "\n" +
               p_CollisionChunk -> p_Info -> ToString();
    }
}

