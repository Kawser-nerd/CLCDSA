using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14
{
    using System.IO;

    class Program
    {
        public const string PATH_IN = @"D:\Dropbox\Competitions\GCJ14\GCJ14\IN\A-large.in";
        public const string PATH_OUT = @"D:\Dropbox\Competitions\GCJ14\GCJ14\OUT\alarge.OUT";


        static void Main(string[] args)
        {
            var s = new A();

            var lines = File.ReadAllLines(PATH_IN);

            var res = s.Solve(lines);

            File.WriteAllLines(PATH_OUT, res);
        }
    }
}
