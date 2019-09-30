using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam1a
{
    class Problem3
    {
        public static void Main()
        {
            new Problem3().Start();
        }

        void Start()
        {
            var fileName = "C-small-attempt2";
            using (var input = new System.IO.StreamReader("../../IO/" + fileName + ".in"))
            using (var output = new System.IO.StreamWriter("../../IO/" + fileName + ".out"))
            {
                var TC = int.Parse(input.ReadLine());
                for (var testCase = 1; testCase <= TC; testCase++)
                {
                    Console.WriteLine("Case #" + testCase);
                    output.WriteLine("Case #" + testCase + ":");
                    int numTrees = int.Parse(input.ReadLine());
                    var trees = new Tuple<int, int>[numTrees];
                    for(int i = 0; i < numTrees; i++)
                    {
                        var line = input.ReadLine().Split(' ').Select(int.Parse).ToList();
                        trees[i] = new Tuple<int, int>(line[0], line[1]);
                    }
                    for (int i = 0; i < numTrees; i++)
                    {
                        var angles = new List<double>();
                        for (int j = 0; j < numTrees; j++)
                        {
                            if (j != i)
                            {
                                var x1 = trees[i].Item1;
                                var x2 = trees[j].Item1;
                                var y1 = trees[i].Item2;
                                var y2 = trees[j].Item2;
                                double angle;
                                if (x2 - x1 == 0)
                                {
                                    if (y2 - y1 > 0)
                                    {
                                        angle = Math.PI / 2.0;
                                    }
                                    else
                                    {
                                        angle = 3 * Math.PI / 2.0;
                                    }
                                }
                                else if (y2 - y1 == 0)
                                {
                                    if (x2 - x1 > 0)
                                    {
                                        angle = 0;
                                    }
                                    else
                                    {
                                        angle = Math.PI;
                                    }
                                }
                                else if (x2 - x1 >= 0)
                                {
                                    if (y2 - y1 >= 0)
                                    {
                                        angle = Math.Atan((double)(y2 - y1) / (x2 - x1));
                                    }
                                    else
                                    {
                                        angle = 2 * Math.PI + Math.Atan((double)(y2 - y1) / (x2 - x1));
                                    }
                                }
                                else
                                {
                                    if (y2 - y1 >= 0)
                                    {
                                        angle = Math.PI + Math.Atan((double)(y2 - y1) / (x2 - x1));
                                    }
                                    else
                                    {
                                        angle = Math.PI + Math.Atan((double)(y2 - y1) / (x2 - x1));
                                    }
                                }
                                angles.Add(angle);
                            }
                        }
                        angles.Sort();
                        var max = 0;
                        for(int j = 0; j < angles.Count; j++)
                        {
                            var treesIn = 1;
                            for(int k = (j == angles.Count - 1) ? 0 : (j + 1); k != j;)
                            {
                                if(angles[k] >= angles[j])
                                {
                                    if (angles[k] - angles[j] > Math.PI + 0.0000001)
                                        break;
                                }
                                else
                                {
                                    if (angles[j] - angles[k] < Math.PI - 0.0000001)
                                        break;
                                }

                                treesIn++;
                                if (++k == angles.Count)
                                    k = 0;
                            }
                            max = Math.Max(max, treesIn);
                        }
                        output.WriteLine(numTrees - 1 - max);
                    }
                }
            }
        }
    }
}
