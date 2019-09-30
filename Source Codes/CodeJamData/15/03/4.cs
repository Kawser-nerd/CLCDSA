using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2015_0_C
{
    class Program
    {
        static int[][] op = {
                                new [] { 0, 1, 2, 3, 4, 5, 6, 7 },
                                new [] { 1, 4, 3, 6, 5, 0, 7, 2 },
                                new [] { 2, 7, 4, 1, 6, 3, 0, 5 },
                                new [] { 3, 2, 5, 4, 7, 6, 1, 0 },
                                new [] { 4, 5, 6, 7, 0, 1, 2, 3 },
                                new [] { 5, 0, 7, 2, 1, 4, 3, 6 },
                                new [] { 6, 3, 0, 5, 2, 7, 4, 1 },
                                new [] { 7, 6, 1, 0, 3, 2, 5, 4 }
                            };
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var parts = Console.ReadLine().Split();
                var repCount = long.Parse(parts[1]);
                var symbols = Console.ReadLine().Select(c => (int)(c - 'i') + 1).ToList();
                var totalCount = symbols.Count * repCount;

                var cycle = symbols.Aggregate((acc, n) => op[acc][n]);
                var found = false;
                if (cycle != 0 && (cycle == 4 && repCount % 2 != 0 || cycle != 4 && repCount % 4 == 2))
                {
                    var target = 0;
                    var foundI = false;
                    var cycleMonitor = 0;
                    for (int i = 0; i < totalCount - 1 && cycleMonitor < symbols.Count * 4; i++)
                    {
                        target = op[target][symbols[i % symbols.Count]];
                        if (target == 1 && !foundI)
                        {
                            foundI = true;
                            target = 0;
                            cycleMonitor = 0;
                            continue;
                        }
                        if (target == 2 && foundI)
                        {
                            found = true;
                            break;
                        }
                        cycleMonitor++;
                    }
                }
                Console.WriteLine("Case #{0}: {1}", testN, found ? "YES" : "NO");
            }
        }
    }
}
