using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using static System.Console;
namespace AtCoder.ARC086
{
    class NotSoDivers
    {
        public static void Main()
        {
            var nk = ReadLine().Split(' ').Select(_ => int.Parse(_));
            var n = nk.First(); var k = nk.Last();
            var array = new int[(n + 1)];
            foreach (var a in ReadLine().Split(' ').Select(_ => int.Parse(_)))
            {
                array[a]++;
            }
            var balls = array.Where(_ => _ != 0).OrderByDescending(_ => _).ToArray();
            if (balls.Count() <= k) WriteLine(0);
            else
            {
                var res = n;
                for (var i = 0; i < k; ++i) res -= balls[i];
                WriteLine(res);
            }
        }
    }
}