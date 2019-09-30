using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

namespace Round1CProblemA
{
    class R1C_ProblemB
    {
        static int[][] cls;
        static int[][] basecls;
        static bool bHasDiamond;
        static int[] getBaseClasses(int clsid)
        {
            if (basecls[clsid] != null)
                return basecls[clsid];
            int[] inh = cls[clsid];
            List<int> bs = new List<int>(inh);
            for (int i = 0; i < inh.Length; ++i)
            {
                int[] cbs = getBaseClasses(inh[i]);
                for (int j = 0; j < cbs.Length; ++j)
                {
                    if (bs.IndexOf(cbs[j]) >= 0)
                        bHasDiamond = true;
                    else
                        bs.Add(cbs[j]);
                }
            }
            basecls[clsid] = bs.ToArray();
            return basecls[clsid];
        }
        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "A-small-attempt0";
            const string fileName = "A-large";

            string DataFolder = @"D:\Projects\CSharp\CodeJam2012\Round1CProblemA\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    int N = int.Parse(sr.ReadLine());
                    cls = new int[N][];
                    basecls = new int[N][];
                    for (int i = 0; i < N; ++i)
                    {
                        string[] ss = sr.ReadLine().Split();
                        int M = int.Parse(ss[0]);
                        int[] inh = new int[M];
                        Debug.Assert(M + 1 == ss.Length);
                        for (int j = 0; j < M; ++j)
                        {
                            inh[j] = int.Parse(ss[j + 1]) - 1;
                        }
                        cls[i] = inh;
                    }
                    bHasDiamond = false;
                    for (int i = 0; i < N; ++i)
                        getBaseClasses(i);
                    string res = (bHasDiamond)? "Yes": "No";
                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res.ToString());
                }
            }
        }
    }
}
