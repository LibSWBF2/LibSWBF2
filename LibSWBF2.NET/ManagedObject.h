#pragma once
using namespace System;

namespace LibSWBF2NET
{
	template<class T>
	public ref class ManagedObject
	{
	private:
		T* m_Instance = nullptr;

	protected:
		T* GetInstance()
		{
			return m_Instance;
		}

	public:
		ManagedObject(T* instance) : m_Instance(instance)
		{

		}

		~ManagedObject()
		{
			this->!ManagedObject();
		}

		// Finalizer (Managed destructor, called by GC)
		!ManagedObject()
		{
			if (m_Instance != nullptr)
			{
				delete m_Instance;
			}
		}
	};
}
 