using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class A : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string[] s = Console.ReadLine().Split();
                int R = int.Parse(s[0]);
                int C = int.Parse(s[1]);
                string[] map = new string[R];
                for (int i = 0; i < R; i++)
                {
                    map[i] = Console.ReadLine();
                }
                string ret = minChanges(map,R,C);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //System.Diagnostics.Debug.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //    System.Diagnostics.Debug.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string minChanges(string[] map, int R, int C)
        {
            int[] aDirI = new int[] { 1, 0, -1, 0 };
            int[] aDirJ = new int[] { 0, 1, 0, -1 };
            int ret = 0;
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (map[i][j] != '.')
                    {
                        char c = map[i][j];
                        int diri = 0;
                        int dirj = 0;
                        switch (c)
                        {
                            case '>':
                                diri=0;
                                dirj=1;
                                break;
                            case '<':
                                diri = 0;
                                dirj = -1;
                                break;
                            case '^':
                                diri = -1;
                                dirj = 0;
                                break;
                            case 'v':
                                diri = 1;
                                dirj = 0;
                                break;
                            default:
                                throw new Exception("wtf");
                        }

                        int i2 = i+diri;
                        int j2 = j+dirj;
                        bool found = false;
                        while (i2 >= 0 && i2 < R && j2 >= 0 && j2 < C)
                        {
                            if (map[i2][j2] != '.')
                            {
                                found = true;
                                break;
                            }
                            i2 += diri;
                            j2 += dirj;
                        }

                        if (!found)
                        {
                            ret++;
                            bool saved = false;
                            for (int k = 0; k < 4; k++)
                            {
                                i2 = i + aDirI[k];
                                j2 = j + aDirJ[k];
                                found = false;
                                while (i2 >= 0 && i2 < R && j2 >= 0 && j2 < C)
                                {
                                    if (map[i2][j2] != '.')
                                    {
                                        found = true;
                                        break;
                                    }
                                    i2 += aDirI[k];
                                    j2 += aDirJ[k];
                                }
                                if (found) saved = true;
                            }
                            if (!saved) return "IMPOSSIBLE";
                        }
                    }
                }
            }
            return ret.ToString();
        }
    }
}
