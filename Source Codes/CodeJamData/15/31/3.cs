using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj15r1c
{
    class Program
    {
        static void Main(string[] args)
        {
            {
                string root = @"C:\Users\Josiah\Downloads\";
                string problem = "A";
                //string ptype = "small-attempt0";
                string ptype = "Large";

                string[] lines = System.IO.File.ReadAllLines(string.Format("{0}{1}-{2}.in", root, problem, ptype));
                TextWriter tw = new StreamWriter(string.Format("{0}{1}-{2}.out", root, problem, ptype));

                int idx = 0;
                int t = int.Parse(lines[idx++]);
                for (int a = 0; a < t; a++)
                {
                    string[] line = lines[idx++].Split(' ');
                    int R = int.Parse(line[0]);
                    int C = int.Parse(line[1]);
                    int W = int.Parse(line[2]);

                    int nC = C / W;
                    int count1 = -1;
                    int count2 = -1;
                    int ans = nC* R + W;
                    if (C % W == 0)
                    {
                        if (nC != 1)
                        {
                            count1 = (nC - 1) * R + W;
                        }
                        count2 = nC * R + W - 1;
                        ans = Math.Max(count1, count2);
                    }

                    tw.WriteLine("Case #{0}: {1}", a + 1, ans);
                }

                tw.Close();
            }
        }
    }
}
