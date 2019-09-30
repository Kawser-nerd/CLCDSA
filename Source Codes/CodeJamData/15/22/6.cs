using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace R1B
{
    class B
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
                        var inps = Console.In.ReadLine().Split(" ".ToCharArray());
                        int r = int.Parse(inps[0]);
                        int c = int.Parse(inps[1]);
                        int n = int.Parse(inps[2]);
                        var res = r * c;
                        var rex = 1 << res;
                        var answer = res * 2;
                        for (int j = 0; j<rex; ++j)
                        {
                            bool[,] mat = new bool[17, 17];
                            int ct = 0;
                            int xx = 0;
                            int yy = 0;
                            var jj = j;
                            while (jj > 0)
                            {
                                mat[xx, yy] = (jj & 1) == 1;
                                if (mat[xx, yy]) {
                                    ++ct;
                                }
                                jj >>= 1;
                                ++yy;
                                if (yy == c)
                                {
                                    yy = 0;
                                    ++xx;
                                }
                            }
                            if (ct == n)
                            {
                                var cur = 0;
                                for (int x = 0; x < r; ++x) {
                                    for (int y = 0; y < c; ++y) {
                                        if (x > 0 && mat[x - 1, y] && mat[x, y])
                                            ++cur;
                                        if (y > 0 && mat[x, y-1] && mat[x, y])
                                            ++cur;
                                    }
                                }
                                answer = Math.Min(answer, cur);
                            }
                        }
                        Console.WriteLine("Case #{0}: {1}", i, answer);
                    }
                }
            }  
        }
    }
}
