using CodeJam.PractiseProblems;
using System;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            //var problem = new Round1AProblemA();
            //problem.Solve(@"..\..\files\A-test-practice.in");
            //problem.Solve(@"..\..\files\A-small-attempt1.in");
            //problem.Solve(@"..\..\files\A-large.in");

            //var problem = new Round1AProblemB();
            //problem.Solve(@"..\..\files\B-test-practice.in");
            //problem.Solve(@"..\..\files\B-small-attempt0.in");
            //problem.Solve(@"..\..\files\B-large.in");

            var problem = new Round1AProblemC();
           // problem.Solve(@"..\..\files\C-test-practice.in");
            problem.Solve(@"..\..\files\C-small-attempt3.in");
            //problem.Solve(@"..\..\files\C-large.in");
            Console.ReadLine();
        }
    }
}