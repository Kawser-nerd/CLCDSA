using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace R1B
{
    class C
    {
        static void Main(string[] args)
        {
            using (var streamWriter = new StreamWriter(new FileStream("./output.txt", FileMode.Create, FileAccess.Write)))
            {
                using (var streamReader = new StreamReader(new FileStream("./input.txt", FileMode.Open, FileAccess.Read)))
                {
                    Console.SetIn(streamReader);
                    Console.SetOut(streamWriter);

                    var t = int.Parse(Console.In.ReadLine());
                    for (int i = 1; i <= t; ++i)
                    {
                        int[,] hikers = new int[500005, 2];
                        int c = 0;
                        var n = int.Parse(Console.In.ReadLine());
                        for (int j = 0; j < n; ++j) {
                            var inps = Console.In.ReadLine().Split(" ".ToCharArray());
                            var d = int.Parse(inps[0]);
                            var h = int.Parse(inps[1]);
                            var m = int.Parse(inps[2]);
                            for (;h > 0 ;--h)
                            {
                                hikers[c,0] = d;
                                hikers[c++,1] = m++;
                            }

                        }
                        var res = 0;
                        if (c > 1)
                        {
                            var t1 = (360L - hikers[0, 0]) * hikers[0, 1];
                            var t2 = (720L - hikers[1, 0]) * hikers[1, 1];
                            var t3 = (720L - hikers[0, 0]) * hikers[0, 1];
                            var t4 = (360L - hikers[1, 0]) * hikers[1, 1];
                            if (t1 >= t2 || t4 >= t3)
                                res = 1;
                        }
                        Console.WriteLine("Case #{0}: {1}", i, res);
                    }
                }
            }  
        }
    }
}
