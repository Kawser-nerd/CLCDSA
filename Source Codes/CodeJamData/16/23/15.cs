using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14.R1B
{
    using System.IO;

    using Quals;

    class Program
    {
        public const string PATH_IN = @"C:\Users\sergey.shcheglov\Downloads\C-small-attempt0.in";
        public const string PATH_OUT = @"D:\Dropbox\Competitions\GCJ16\GCJ14\OUT\out.txt";


        static void Main(string[] args)
        {
            var s = new C();

            var lines = File.ReadAllLines(PATH_IN);

            var res = s.Solve(lines);

            File.WriteAllLines(PATH_OUT, res);
        }
    }
}
