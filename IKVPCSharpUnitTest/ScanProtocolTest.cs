using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Diagnostics;


namespace IKVPCSharpUnitTest
{
    [TestClass]
    public class ScanProtocolTest
    {
        [TestMethod]
        public void CanIterateScanProtocol()
        {
            var v = new ScanProtocol();
            var node = v.GetFirstChild().GetNextSibling();
            while(node != null)
            {
                var val = node.GetValue();

                Trace.Write(val);
                node = node.GetNextSibling();
            }
            
        }
    }
}
