/*
 * Generated by erpcgen 1.3.0 on Tue Nov 22 18:09:25 2016.
 *
 * AUTOGENERATED - DO NOT EDIT
 */

#include "test_arithmetic_server.h"
#include <new>
#include "erpc_port.h"

using namespace erpc;
#if !(__embedded_cplusplus)
using namespace std;
#endif


// Call the correct server shim based on method unique ID.
erpc_status_t Arithmetic_service::handleInvocation(uint32_t methodId, uint32_t sequence, Codec * codec)
{
    switch (methodId)
    {
        case kArithmetic_add_id:
            return add_shim(codec, sequence);

        case kArithmetic_sub_id:
            return sub_shim(codec, sequence);

        default:
            return kErpcStatus_InvalidArgument;
    }
}

// Server shim for add of Arithmetic interface.
erpc_status_t Arithmetic_service::add_shim(Codec * codec, uint32_t sequence)
{
    erpc_status_t err = kErpcStatus_Success;
    float a;
    float b;

    // startReadMessage() was already called before this shim was invoked.
    if (!err)
    {
        err = codec->startReadStruct();
    }

    if (!err)
    {
        err = codec->read(&a);
    }


    if (!err)
    {
        err = codec->read(&b);
    }

    if (!err)
    {
        err = codec->endReadStruct();
    }

    if (!err)
    {
        err = codec->endReadMessage();
    }

    // Invoke the actual served function.
    float result;
    if (!err)
    {
        result = add(a, b);
    }

    // reset codec for sending data
    codec->getBuffer()->setUsed(0);
    codec->reset();

    // Build response message.
    if (!err)
    {
        err = codec->startWriteMessage(kReplyMessage, kArithmetic_service_id, kArithmetic_add_id, sequence);
    }

    if (!err)
    {
        err = codec->write(result);
    }

    if (!err)
    {
        err = codec->endWriteMessage();
    }


    return err;
}

// Server shim for sub of Arithmetic interface.
erpc_status_t Arithmetic_service::sub_shim(Codec * codec, uint32_t sequence)
{
    erpc_status_t err = kErpcStatus_Success;
    float a;
    float b;

    // startReadMessage() was already called before this shim was invoked.
    if (!err)
    {
        err = codec->startReadStruct();
    }

    if (!err)
    {
        err = codec->read(&a);
    }


    if (!err)
    {
        err = codec->read(&b);
    }

    if (!err)
    {
        err = codec->endReadStruct();
    }

    if (!err)
    {
        err = codec->endReadMessage();
    }

    // Invoke the actual served function.
    float result;
    if (!err)
    {
        result = sub(a, b);
    }

    // reset codec for sending data
    codec->getBuffer()->setUsed(0);
    codec->reset();

    // Build response message.
    if (!err)
    {
        err = codec->startWriteMessage(kReplyMessage, kArithmetic_service_id, kArithmetic_sub_id, sequence);
    }

    if (!err)
    {
        err = codec->write(result);
    }

    if (!err)
    {
        err = codec->endWriteMessage();
    }


    return err;
}
erpc_service_t create_Arithmetic_service()
{
    return new (nothrow) Arithmetic_service();
}
