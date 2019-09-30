using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            for (int i = 0; i < N; ++i)
            {
                Int64 cbase;
                string s = Console.ReadLine();
                Dictionary<char, Int64> dict = new Dictionary<char, Int64>();
                Int64 rslt = 0;
                Int64 base_ = s.ToCharArray().Distinct().Count();
                if (base_ == 1)
                    base_ = 2;
                Int64 k = 0;
                for (int j = 0; j < s.Length; ++j)
                {
                    if (!dict.ContainsKey(s[j]))
                        dict[s[j]] = k++;
                    cbase = dict[s[j]];
                    if (cbase == 0)
                        cbase = 1;
                    else if (cbase == 1)
                        cbase = 0;
                    rslt = rslt * base_ + cbase;
                };
                Console.WriteLine("Case #{0}: {1}", i + 1, rslt);
            };
        }
    }
}
