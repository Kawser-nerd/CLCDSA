using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QualificationRound
{
    public class RevengeOfThePancakes : Problem
    {
        protected override string SolveCase()
        {
            var input = this.ReadNextLineAsString().TrimEnd('+');
            var flipCount = 0;
            while (input.Length > 0)
            {
                input = input.TrimEnd(flipCount % 2 == 0 ? '-' : '+');
                flipCount++;
            }

            return flipCount.ToString();
        }
    }
}
