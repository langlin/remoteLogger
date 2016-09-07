/*
 * remoteLogger.cpp
 *
 *  Created on: Sep 2, 2016
 *      Author: langlin
 */

#include <remoteLogger.h>
#include <string.h>

remoteLogger* remoteLogger::pRemoteLogger = NULL;
bool remoteLogger::interfaceError = false;

remoteLogger::remoteLogger()
{
	context = zmq_ctx_new();
	publisher = zmq_socket(context, ZMQ_PUB);
	message = new char[MESSAGE_BUFFER_LENGTH];
	int rc = zmq_bind(publisher, TCP_STRING);
	printf("%d\n", rc);
}

remoteLogger::~remoteLogger()
{
	zmq_close(publisher);
	zmq_ctx_destroy(context);
}

remoteLogger *
remoteLogger::getRemoteLogger()
{
	if (NULL == pRemoteLogger)
	{
		pRemoteLogger = new remoteLogger;
	}

	return remoteLogger::pRemoteLogger;
}

char *
remoteLogger::getBuffer()
{
	return message;
}

uint32_t
remoteLogger::getBufferSize()
{
	return MESSAGE_BUFFER_LENGTH;
}

void
remoteLogger::send()
{
	if (interfaceError)
	{
		//do nothing
	}
	else
	{
		zmq_send(publisher, message, strlen(message), 0);
	}
}
