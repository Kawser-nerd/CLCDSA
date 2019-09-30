using CodeJam.PractiseProblems;
using System;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var problem = new BathroomStalls();
            //problem.Solve(@"..\..\files\C-test-practice.in");
            //problem.Solve(@"..\..\files\C-small-2-attempt0.in");

            problem.Solve(@"..\..\files\C-large.in");
            Console.ReadLine();
        }
    }
}
