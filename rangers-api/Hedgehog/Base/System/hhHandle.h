#pragma once

namespace hh::fnd
{
	class HandleBase
	{
	protected:
		uint32_t handle{};

		void Set(const RefByHandleObject* pObj);
		RefByHandleObject* Get(HandleManagerBase* handleManager) const;
		
	public:
		HandleBase()
		{
			
		}
		
		HandleBase(const RefByHandleObject* pObj)
		{
			Set(pObj);
		}

		bool operator==(const HandleBase& other)
		{
			return handle == other.handle;
		}

		bool operator!=(const HandleBase& other)
		{
			return !operator==(other);
		}

		bool operator==(const RefByHandleObject* pObj)
		{
			return pObj == nullptr ? handle == 0 : handle == pObj->handle;
		}

		bool operator!=(const RefByHandleObject* pObj)
		{
			return !operator==(pObj);
		}

		HandleBase& operator=(const RefByHandleObject* pObj)
		{
			Set(pObj);
			return *this;
		}

		HandleBase& operator=(const HandleBase& hObj)
		{
			handle = hObj.handle;
			return *this;
		}
	};

	template<typename T, typename M = typename T::HandleManager>
	class Handle : public HandleBase
	{
	public:
		Handle()
		{
			
		}

		Handle(const T* pObj) : HandleBase(pObj)
		{
			
		}


		Handle<T, M>& operator=(T* pObj)
		{
			Set(pObj);
			return *this;
		}

		Handle<T, M>& operator=(const Handle<T, M>& hObj)
		{
			handle = hObj.handle;
			return *this;
		}

		T* operator*() const
		{
			return reinterpret_cast<T*>(HandleBase::Get(RESOLVE_STATIC_VARIABLE(M::instance)));
		}

		operator T*() const
		{
			return operator*();
		}

		T* operator->() const
		{
			return operator*();
		}
	};
}
