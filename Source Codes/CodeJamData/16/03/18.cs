using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QualificationRound
{
    public class Program
    {
        public static void Main(string[] args)
        {
            //var problem = new CountingSheep();
            //problem.Solve(@"..\..\files\A-sample.in");

            //var problem = new RevengeOfThePancakes();
            //problem.Solve(@"..\..\files\B-sample.in");

            var problem = new CoinJam();
            problem.Solve(@"..\..\files\C-large.in");

            //var problem = new Fractiles();
            //problem.Solve(@"..\..\files\D-large.in");

            Console.ReadLine();
        }
    }
}
