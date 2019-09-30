using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var problem = new Round1CProblemC();
            problem.Solve(@"..\..\files\C-large.in");
            Console.ReadLine();
        }
    }
}
