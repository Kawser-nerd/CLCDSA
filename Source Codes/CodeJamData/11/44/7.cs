using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using CodeJam11.Round2;

namespace CodeJam11
{
    class Program
    {
        static void Main(string[] args)
        {
            if(args.Length != 2)
                return;
            var p = new Problem4();
            p.Solve(args[0], args[1]);
        }
    }
}
