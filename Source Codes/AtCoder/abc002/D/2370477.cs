using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var vals = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var n = vals[0];
            var m = vals[1];

            var relation = new List<int[]>();
            foreach(var i in Enumerable.Range(0, m))
            {
                var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                relation.Add(input);
            }

            var mask = Enumerable.Range(0, n).Select(x => (int)Math.Pow(2,x)).ToArray();

            var result = -1;
            for (var i = (int)Math.Pow(2, n) - 1; i>0; i--)
            {
                result = Math.Max(result, isHabatu(i, mask, relation));
            }

            if (result == -1) Console.WriteLine(1);
            else Console.WriteLine(result);
        }

        static int isHabatu(int seed, int[] mask, List<int[]> relations)
        {
            var member = new List<int>();
            foreach (var i in Enumerable.Range(0, mask.Length))
            {
                if ((seed & mask[i]) != 0) member.Add(i + 1);
            }

            for(var i =0; i<member.Count; i++)
            {
                for(var j = i+1;j<member.Count;j++)
                {
                    if (!relations.Any(x => x[0] == member[i] && x[1] == member[j])) return -1;
                }
            }
            return member.Count;
        }
    }

}