using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


class B
{
    static void Main(string[] args)
    {
        Stopwatch watch = new Stopwatch();
        watch.Start();

        StreamReader sr = null;
        StreamWriter sw = null;

        if (args.Length > 0)
        {
            FileInfo info = new FileInfo(args[0]);
            sr = new StreamReader(info.FullName);
            sw = new StreamWriter(info.FullName.Replace(".in", ".out"));
        }
        else
        {
            //sr = new StreamReader("c:\\codejam\\B-tiny.in");
            //sw = new StreamWriter("c:\\codejam\\B-tiny.out");
            //sr = new StreamReader("c:\\codejam\\B-small-attempt0.in");
            //sw = new StreamWriter("c:\\codejam\\B-small-attempt0.out");
            sr = new StreamReader("c:\\codejam\\B-large.in");
            sw = new StreamWriter("c:\\codejam\\B-large.out");
        }

        int T = Int32.Parse(sr.ReadLine());
        foreach (int caseN in Enumerable.Range(1, T))
        {
            int N = int.Parse(sr.ReadLine());

            List<Tuple<int,int,int>> req = new List<Tuple<int,int,int>>();
            for (int i = 0; i < N; i++)
            {
                int[] tmp = sr.ReadLine().Split(' ').Select(int.Parse).ToArray();
                req.Add(Tuple.Create(i, tmp[0], tmp[1]));
            }

            int stars = 0;
            int levels = 0;

            int[] levelDone = new int[N];

            while (true)
            {
                if (stars == N * 2)
                    break;

                int star2 = -1;
                for (int l = 0; l < N; l++)
                {
                    if (levelDone[l] < 2 && req[l].Item3 <= stars)
                    {
                        star2 = l;
                        break;
                    }
                }
                if (star2 != -1)
                {
                    stars += levelDone[star2] == 1 ? 1 : 2;
                    levelDone[star2] = 2;
                    levels++;
                    continue;
                }

                var highest = req.Where(tp => levelDone[tp.Item1] == 0 && tp.Item2 <= stars).OrderBy(tp => -tp.Item3).ToArray();
                if (highest.Length == 0)
                {
                    goto impossible;
                }

                stars += 1;
                levelDone[highest.First().Item1] = 1;
                levels++;
            }
            sw.WriteLine(String.Format("Case #{0}: {1}", caseN,levels));

            goto skip;

        impossible:
            sw.WriteLine(String.Format("Case #{0}: {1}", caseN,"Too Bad"));

        skip:
            sw.Flush();

            Console.WriteLine(String.Format("Case #{0}: {1}ms", caseN, watch.ElapsedMilliseconds));
        }

        sr.Close();
        sw.Close();
    }
}
