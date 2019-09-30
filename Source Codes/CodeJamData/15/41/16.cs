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
            var problem = new Round2ProblemA();
            //problem.Solve(@"..\..\files\practice.in");
            problem.Solve(@"..\..\files\A-large.in");
            Console.ReadLine();
        }
    }
}
