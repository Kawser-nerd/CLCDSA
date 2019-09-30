using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC075
{
    class Bugged
    {
        public static void Main()
        {
            var n = int.Parse(ReadLine().Trim());
            var scores = (new int[n]).Select(i => int.Parse(ReadLine().Trim())).ToArray();
            var others = scores.Where(i => i % 10 != 0).OrderBy(i => i).ToArray();
            if (others.Length == 0) WriteLine(0);
            else if (others.Sum() % 10 == 0) WriteLine(scores.Sum() - others[0]);
            else WriteLine(scores.Sum());
        }
    }
}