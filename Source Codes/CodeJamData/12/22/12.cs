using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace test
{
    class Program {
        static void Main(string[] args) {
            Ctest ct1 = new Ctest();
            if (args.Length > 0) {
                ct1.main(args[0]);
            } else {
                ct1.main("test.txt");
            }
        }
    }
}
