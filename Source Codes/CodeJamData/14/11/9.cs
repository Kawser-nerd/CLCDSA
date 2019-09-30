using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemABig
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = Convert.ToInt32(Console.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                var NL = Console.ReadLine().Split(' ');
                var N = Convert.ToInt32(NL[0]);
                var L = Convert.ToInt32(NL[1]);
                var outlets = Console.ReadLine().Split(' ').Select(token => Convert.ToUInt64(token, 2)).ToArray();
                var devices = Console.ReadLine().Split(' ').Select(token => Convert.ToUInt64(token, 2)).ToArray();
                var hash = devices.ToDictionary(d => d, d => false);
                var options = devices.Select(d => d ^ outlets[0]).ToArray();
                var minS = Int32.MaxValue;
                foreach (var s in options)
                {
                    bool conflict = false;
                    foreach (var outlet in outlets)
                    {
                        if (!hash.ContainsKey(outlet ^ s))
                            conflict = true;
                        else if (hash[outlet ^ s])
                            conflict = true;
                        else
                            hash[outlet ^ s] = true;
                    }
                    foreach (var key in devices)
                        hash[key] = false;
                    if (!conflict)
                        minS = Math.Min(minS, NumberOfSetBits(s));
                }
                if (minS < Int32.MaxValue)
                    Console.WriteLine("Case #{0}: {1}", t, minS);
                else
                    Console.WriteLine("Case #{0}: NOT POSSIBLE", t);
            }
        }

        static int NumberOfSetBits(ulong i)
        {
            i = i - ((i >> 1) & 0x5555555555555555UL);
            i = (i & 0x3333333333333333UL) + ((i >> 2) & 0x3333333333333333UL);
            return (int)(unchecked(((i + (i >> 4)) & 0xF0F0F0F0F0F0F0FUL) * 0x101010101010101UL) >> 56);
        }
    }
}
