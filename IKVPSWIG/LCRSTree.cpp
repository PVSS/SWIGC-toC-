#include <iostream>
#include "IKVP.h"
#include "ScanProtocol.h"

using namespace std;

int main()
{
	ScanProtocol sp;
	std::cout << sp.GetData() << std::endl;
	std::cout << sp.GetFirstChild()->GetValue() << std::endl;
	IKVPNode* sib = sp.GetFirstChild()->GetNextSibling();
	while (sib != NULL)
	{
		std::cout << sib->GetValue() << std::endl;
		sib = sib->GetNextSibling();
	}
	char ch;
	cin >> ch;
}

