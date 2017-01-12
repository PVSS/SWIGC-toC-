%module(directors="1") IKVP
%feature("director");

%include <IKVP.h>
%template(KVPAccessProviderForScanProtocol) KVPAccessProvider<ScanProtocol>;

%include <ScanProtocol.h>

