using CodeJam.PractiseProblems;
using System;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var problem = new OversizedPancakeFlipper();
            //problem.Solve(@"..\..\files\A-test-practice.in");
            //problem.Solve(@"..\..\files\A-small-attempt0.in");
            problem.Solve(@"..\..\files\A-large.in");
            Console.ReadLine();
        }
    }
}
