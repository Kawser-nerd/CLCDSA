using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleJam
{  
    public class CyclesCache
    {
        public static HashSet<int>[] CyclesCachedValues = Enumerable.Range(0, 2000001).Select(GetCycles).ToArray();

        public static HashSet<int> GetCycles(int number)
        {
            var result = new HashSet<int>();
            var sb = new StringBuilder();
            sb.Append(number);
            var digits = sb.Length;
            for (int i = 0; i < digits; i++)
            {
                var ch = sb[0];
                sb.Remove(0, 1);
                sb.Append(ch);
                var cycled = int.Parse(sb.ToString());
                if (cycled < number)
                    result.Add(cycled);
            }
            return result;
        }

        public static int GetPairsCount(int a, int b)
        {
            int result = 0;
            for (int i = a; i <= b; i++)
                checked
                {
                    result += CyclesCachedValues[i].Count(c => c >= a);    
                }
                
            return result;
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            var tr = new StreamReader(@"C:\GJ\input.in");
            using (var tw = new StreamWriter(@"C:\GJ\output.out"))
            {
                int testCount = int.Parse(tr.ReadLine());
                for (int i = 0; i < testCount; i++)
                {
                    var line = tr.ReadLine();
                    var ints = line.Split().Select(int.Parse).ToArray();

                    tw.WriteLine(string.Format("Case #{0}: {1}", i+1, CyclesCache.GetPairsCount(ints[0], ints[1])));
                }
            }
        }
    }
}
