#ifndef SCAN_PROTOCOL_H
#define SCAN_PROTOCOL_H

#include "IKVP.h"
struct ScanProtocolDataStruct;


class ScanProtocol : public KVPAccessProvider<ScanProtocol>
{
private:

	ScanProtocolDataStruct* data;
	
public:
	//A Dummy Function to Access the structure.
	int GetData();
	ScanProtocol();
};
#endif