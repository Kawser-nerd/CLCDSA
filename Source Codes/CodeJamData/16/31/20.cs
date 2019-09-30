using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam1ca
{
    class Program
    {
        static readonly string small = "small.txt";
        static readonly string large = "large.txt";
        static void Main(string[] args)
        {
            Problem(large);
        }
        static char itoc(int i)
        {
            return (char)('A' + i);
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
                                int N = int.Parse(sr.ReadLine());
                                List<string> evacuation = new List<string>();
                                var senate = sr.ReadLine().Split(' ').Select(int.Parse).ToArray<int>();
                                int total = 0;
                                for (int j = 0; j < N; j++)
                                {
                                    total += senate[j];
                                }
                                while (total > 0)
                                {
                                    if (total == 2)
                                    {
                                        string res = string.Empty;
                                        for (int j = 0; j < N; j++)
                                        {
                                            if (senate[j] > 0)
                                            {
                                                res += itoc(j);
                                            }
                                        }
                                        evacuation.Add(res);
                                        total -= 2;
                                        continue;
                                    }
                                    int max1 = 0;
                                    int max1j = -1;
                                    int max2 = 0;
                                    int max2j = -1;
                                    int max3 = 0;
                                    int max3j = -1;
                                    for (int j = 0; j < N; j++)
                                    {
                                        if (senate[j] >= max1)
                                        {
                                            max3j = max2j;
                                            max3 = max2;
                                            max2j = max1j;
                                            max2 = max1;
                                            max1j = j;
                                            max1 = senate[j];
                                        }
                                        else if (senate[j] >= max2)
                                        {
                                            max3j = max2j;
                                            max3 = max2;
                                            max2j = j;
                                            max2 = senate[j];
                                        }
                                        else if (senate[j] > max3)
                                        {
                                            max3j = j;
                                            max3 = senate[j];
                                        }
                                    }
                                    // remove one from the max to stay with 1-1;
                                    if (total == 3)
                                    {
                                        evacuation.Add(itoc(max1j).ToString());
                                        senate[max1j]--;
                                        total -= 1;

                                        continue;
                                    }
                                    if (total == 4 && max2 == 2) // situation 2-2
                                    {
                                        string res = string.Empty + itoc(max1j);
                                            res += itoc(max2j);
                                        evacuation.Add(res);
                                        senate[max1j]--;
                                        senate[max2j]--;
                                        total -= 2;

                                        continue;
                                    }
                                    if (max1 >= 2 && max2 == 1)
                                    {

                                        string res = string.Empty + itoc(max1j);
                                            res+= itoc(max1j);
                                        evacuation.Add(res);
                                        senate[max1j] -= 2;
                                        total -= 2;

                                        continue;
                                    }
                                    else
                                    {
                                        string res = string.Empty + itoc(max1j);
                                        res += itoc(max2j);
                                        evacuation.Add(res);
                                        senate[max1j]--;
                                        senate[max2j]--;
                                        total -= 2;

                                        continue;
                                    }
                                    if (max1 == 1) //1-1-1-1
                                    {
                                        string res = string.Empty + itoc(max1j);
                                        res += itoc(max2j);
                                        evacuation.Add(res);
                                        senate[max1j]--;
                                        senate[max2j]--;
                                        total -= 2;

                                        continue;
                                    }
                                }
                                sw.WriteLine("Case #{0}: {1}", i, string.Join(" ", evacuation));

                            }

                        }
                    }
                }
            }
        }
    }
}
