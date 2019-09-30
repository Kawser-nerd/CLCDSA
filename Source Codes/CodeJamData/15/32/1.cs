using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2015_1C_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var parts = Console.ReadLine().Split().Select(int.Parse).ToArray();
                var K = parts[0];
                var L = parts[1];
                var S = parts[2];
                var keyboard = Console.ReadLine();
                var target = Console.ReadLine();

                var max = 0L;
                var E = 0L;
                var spaceSize = 1L;
                for (int i = 0; i < S; i++)
                {
                    spaceSize *= K;
                }

                for (long ev = 0; ev < spaceSize; ev++)
                {
                    var evt = ev;
                    var hits = 0;
                    for (int i = 0; i <= S - L; i++, evt /= K)
                    {
                        var found = true;
                        var evtt = evt;
                        for (int j = 0; j < L; j++)
                        {
                            var letterIndex = (int) (evtt % K);
                            evtt /= K;
                            if (keyboard[letterIndex] != target[j])
                            {
                                found = false;
                                break;
                            }
                        }
                        if (found)
                            hits++;
                    }
                    if (hits > max)
                        max = hits;
                    E += hits;
                }

                Console.WriteLine("Case #{0}: {1}", testN, max - ((double)E / spaceSize));
            }
        }
    }
}
