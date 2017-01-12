#include "ScanProtocol.h"

struct ScanProtocolDataStruct
{
	int temp1;
	int temp2;
	int temp3;
	int temp4;
};

ScanProtocol::ScanProtocol()
{
	data = new ScanProtocolDataStruct();
	data->temp1 = 1;
	data->temp2 = 1;
	data->temp3 = 2;
	data->temp4 = 3;
	Index(12345);
}

int ScanProtocol::GetData()
{
	return data->temp1;
}