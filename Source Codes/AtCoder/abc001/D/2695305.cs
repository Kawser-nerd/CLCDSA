using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCorder
{
    class Program
    {
        static void Main(string[] args)
        {
            var res1 = int.Parse(Console.ReadLine());

            var ls = new List<int[]>();
            for (var i = 0; i < res1; i++)
            {
                var memo = Console.ReadLine().Split('-').Select(x => int.Parse(x)).ToArray();
                ls.Add(memo);
            }

            var orderedList = ls.OrderBy(x => x[0]);

            foreach (var n in orderedList)
            {
                var r = n[0] % 5;
                n[0] -= r;
                r = n[1] % 5;
                n[1] += (10 - r) % 5;
                if (n[1] % 100 == 60)
                {
                    n[1] += 40;
                }
            }

            var ans = new List<int[]>();
            var row = new int[1];
            var befStr = 0;
            var befEnd = 0;
            foreach (var n in orderedList)
            {
                if(befEnd == 0)
                {
                    befStr = n[0];
                    befEnd = n[1];
                    continue;
                }
                if(befEnd < n[0])
                {
                    ans.Add(new int[] { befStr, befEnd });
                    befStr = n[0];
                    befEnd = n[1];
                    continue;
                }

                if(befEnd < n[1]) befEnd = n[1];
            }
            ans.Add(new int[] { befStr, befEnd});

            foreach (var a in ans)
            {
                Console.WriteLine(string.Format("{0:0000}", a[0]) + "-" + string.Format("{0:0000}", a[1]));
            }
        }
    }
}