using CodeJam.PractiseProblems;
using System;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var problem = new TidyNumbers();
            //problem.Solve(@"..\..\files\B-test-practice.in");
            //problem.Solve(@"..\..\files\B-small-attempt0.in");
            problem.Solve(@"..\..\files\B-large.in");
            Console.ReadLine();
        }
    }
}
