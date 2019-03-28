/**
 *  Writer : badogyang
 *  class name : Exception
 *  Version : 1.0.0
 *
 *  usage : THROW_EXCEPTION(exceptionType, exceptionMessage);
 *
 *  theory : BYLib异常类族,用于处理程序中产生的各种类型的异常
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__));

namespace BYLib
{

class Exception
{
protected:
    char* m_message;
    char* m_location;

    void init(const char* message, const char* file, int line);
public:
    Exception(const char* message);
    Exception(const char* file, int line);
    Exception(const char* message, const char* file, int line);

    Exception(const Exception& e);
    Exception& operator = (const Exception& e);

    virtual const char* message() const;
    virtual const char* location() const;

    virtual ~Exception() = 0;
};

class ArithMeticException : public Exception
{
public:
    ArithMeticException() : Exception(0) {}
    ArithMeticException(const char* message) : Exception(message) {}
    ArithMeticException(const char* file, int line) : Exception(file, line) {}
    ArithMeticException(const char* message, const char* file, int line) : Exception(message, file, line) {}

    ArithMeticException(const ArithMeticException& e) : Exception(e) {}
    ArithMeticException& operator = (const ArithMeticException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

class NullPointerException : public Exception
{
public:
    NullPointerException() : Exception(0) {}
    NullPointerException(const char* message) : Exception(message) {}
    NullPointerException(const char* file, int line) : Exception(file, line) {}
    NullPointerException(const char* message, const char* file, int line) : Exception(message, file, line) {}

    NullPointerException(const NullPointerException& e) : Exception(e) {}
    NullPointerException& operator = (const NullPointerException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

class IndexOutOfBoundsException : public Exception
{
public:
    IndexOutOfBoundsException() : Exception(0) {}
    IndexOutOfBoundsException(const char* message) : Exception(message) {}
    IndexOutOfBoundsException(const char* file, int line) : Exception(file, line) {}
    IndexOutOfBoundsException(const char* message, const char* file, int line) : Exception(message, file, line) {}

    IndexOutOfBoundsException(const IndexOutOfBoundsException& e) : Exception(e) {}
    IndexOutOfBoundsException& operator = (const IndexOutOfBoundsException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

class NoEnoughMemoryException : public Exception
{
public:
    NoEnoughMemoryException() : Exception(0) {}
    NoEnoughMemoryException(const char* message) : Exception(message) {}
    NoEnoughMemoryException(const char* file, int line) : Exception(file, line) {}
    NoEnoughMemoryException(const char* message, const char* file, int line) : Exception(message, file, line) {}

    NoEnoughMemoryException(const NoEnoughMemoryException& e) : Exception(e) {}
    NoEnoughMemoryException& operator = (const NoEnoughMemoryException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

class InvaildParameterException : public Exception
{
public:
    InvaildParameterException() : Exception(0) {}
    InvaildParameterException(const char* message) : Exception(message) {}
    InvaildParameterException(const char* file, int line) : Exception(file, line) {}
    InvaildParameterException(const char* message, const char* file, int line) : Exception(message, file, line) {}

    InvaildParameterException(const InvaildParameterException& e) : Exception(e) {}
    InvaildParameterException& operator = (const InvaildParameterException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

}


#endif // EXCEPTION_H
