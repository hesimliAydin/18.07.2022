#pragma once

template<typename T>
class SharedPointer
{
    T* _ptr;
    int* _count;

public:
    SharedPointer() : _ptr(nullptr), _count(NULL) {}

    SharedPointer(T* ptr) : _ptr(ptr), _count(new int(1)) {}

    SharedPointer(const SharedPointer<T>& other) : _ptr(other._ptr), _count(other._count)
    {
        (*_count)++;
    }

    SharedPointer<T>& operator=(const SharedPointer<T>& other)
    {
        if (_count != NULL)
        {
            (*_count)--;

            if (*_count == 0)
            {
                delete _ptr;
                delete _count;
            }
        }

        _ptr = other._ptr;
        _count = other._count;
        (*_count)++;

        return *this;
    }

    T* get()
    {
        return _ptr;
    }

    T* operator->()
    {
        return _ptr;
    }

    T& operator*()
    {
        return *_ptr;
    }

    ~SharedPointer()
    {
        if (_count != NULL)
        {
            (*_count)--;

            if (*_count == 0)
            {
                delete _ptr;
                delete _count;
            }
        }
    }
};
