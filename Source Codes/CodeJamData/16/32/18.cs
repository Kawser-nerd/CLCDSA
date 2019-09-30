using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam1cb
{
    class Program
    {
        static readonly string small = "small.txt";
        static readonly string large = "large.txt";
        static void Main(string[] args)
        {
            Problem(large);
        }

        static void Problem(string file)
        {
            using (var fsi = new FileStream(file, FileMode.Open))
            {
                using (var sr = new StreamReader(fsi))
                {
                    var fspl = file.Split('.');
                    using (var fso = new FileStream(fspl[0] + "-output." + fspl[1], FileMode.Create))
                    {
                        using (var sw = new StreamWriter(fso))
                        {
                            int T = int.Parse(sr.ReadLine());
                            for (int i = 1; i <= T; i++)
                            {
                                var line = sr.ReadLine().Split(' ').Select(long.Parse).ToArray<long>();
                                long B = line[0];
                                long M = line[1];
                                long max = 1;
                                for (long j = 0; j < B - 2; j++) max *= 2;
                                if (M > max)
                                {
                                    sw.WriteLine("Case #{0}: IMPOSSIBLE", i);
                                    continue;
                                }
                                int[,] matrix = new int[B,B];
                                long[] pathToB = new long[B];

                                // temp max significant bit.
                                long temp = M;
                                long pow2 = 1;
                                int cnt = 0;
                                matrix[0, B - 1] = 1;
                                pathToB[0] = 1;
                                temp /= 2;
                                while (temp> 0)
                                {
                                    cnt++;
                                    temp /= 2;
                                    pow2 *= 2;
                                    pathToB[cnt] = pow2/2;
                                    matrix[0, cnt] = 1;
                                    for (int j = 0; j < cnt; j++)
                                    {
                                        matrix[j, cnt] = 1;
                                    }
                                    matrix[cnt, B - 1] = 1;
                                }
                                temp = M - pow2;
                                if (temp > 0) {
                                    matrix[cnt + 1, B - 1] = 1;
                                    matrix[0, cnt + 1] = 1;
                                    temp--;
                                    for (int j = cnt; j > 0; j--)
                                    {
                                        if (pathToB[j] <= temp)
                                        {
                                            matrix[j, cnt + 1] = 1;
                                            temp -= pathToB[j];
                                        }
                                    }
                                    Console.WriteLine(cnt);
                                    //Console.ReadLine();
                                }
                                sw.WriteLine("Case #{0}: POSSIBLE", i);
                                for (int j = 0; j < B; j++)
                                {
                                    string res = string.Empty;
                                    for (int k = 0; k < B; k++)
                                    {
                                        res += matrix[j, k];
                                    }
                                    sw.WriteLine(res);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
