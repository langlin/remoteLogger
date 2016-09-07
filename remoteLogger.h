/*
 * remoteLogger.h
 *
 *  Created on: Sep 2, 2016
 *      Author: langlin
 */

#ifndef REMOTELOGGER_H_
#define REMOTELOGGER_H_

#include <stdio.h>
#include <zmq.h>
#define TCP_STRING "tcp://eth0:5556"
#define MESSAGE_BUFFER_LENGTH 4096
//#define REMOTE_LOGGER

class remoteLogger {
public:
	virtual ~remoteLogger();

	static remoteLogger *getRemoteLogger();

	char *getBuffer();
	uint32_t getBufferSize();

	void send();

private:
	remoteLogger();

private:
	static remoteLogger* pRemoteLogger;
	static bool interfaceError;
	void *context;
	void *publisher;
	char *message;
};

#endif /* REMOTELOGGER_H_ */
