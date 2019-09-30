using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016R1
{
    class R1B
    {
        public static object Solve()
        {
            var ar = Console.ReadLine().Split(' ');
            var C = ar[0];
            var J = ar[1];
            var len = C.Length;
            var min = long.MaxValue;
            var minC = long.MaxValue;
            var minJ = long.MaxValue;
            for (var i = 0; ; i++)
            {
                if (i == len)
                {
                    min = 0;
                    minC = long.Parse(C);
                    minJ = long.Parse(J);
                    break;
                }
                if (C[i] != '?' && J[i] != '?')
                {
                    long nC, nJ;
                    if (C[i] == J[i])
                        continue;
                    if (C[i] > J[i])
                    {
                        nC = long.Parse(C.Replace('?', '0'));
                        nJ = long.Parse(J.Replace('?', '9'));
                    }
                    else
                    {
                        nC = long.Parse(C.Replace('?', '9'));
                        nJ = long.Parse(J.Replace('?', '0'));
                    }
                    var d = Math.Abs(nC - nJ); if (d < min || (d == min && (nC < minC || (nC == minC && nJ < minJ))))
                    {
                        min = d;
                        minC = nC;
                        minJ = nJ;
                    }
                    break;
                }
                else
                {
                    if (C[i] != '0' && J[i] != '9')
                    {
                        var fC = C[i] == '?' ? (J[i] == '?' ? 1 : (J[i] - '0' + 1)) : (C[i] - '0');
                        var fJ = fC - 1;
                        var nC = long.Parse(Replece(C, i, fC).Replace('?', '0'));
                        var nJ = long.Parse(Replece(J, i, fJ).Replace('?', '9'));
                        var d = Math.Abs(nC - nJ);
                        if (d < min || (d == min && (nC < minC || (nC == minC && nJ < minJ))))
                        {
                            min = d;
                            minC = nC;
                            minJ = nJ;
                        }
                    }
                    if (C[i] != '9' && J[i] != '0')
                    {
                        var fC = C[i] == '?' ? (J[i] == '?' ? 0 : (J[i] - '0' - 1)) : (C[i] - '0');
                        var fJ = fC + 1;
                        var nC = long.Parse(Replece(C, i, fC).Replace('?', '9'));
                        var nJ = long.Parse(Replece(J, i, fJ).Replace('?', '0'));
                        var d = Math.Abs(nC - nJ);
                        if (d < min || (d == min && (nC < minC || (nC == minC && nJ < minJ))))
                        {
                            min = d;
                            minC = nC;
                            minJ = nJ;
                        }
                    }
                    var fCJ = C[i] == '?' ? (J[i] == '?' ? 0 : (J[i] - '0')) : (C[i] - '0');
                    C = Replece(C, i, fCJ);
                    J = Replece(J, i, fCJ);
                }
            }
            return string.Format("{0} {1}", minC.ToString().PadLeft(len, '0'), minJ.ToString().PadLeft(len, '0'));
        }

        static string Replece(string s, int idx, int c)
        {
            return s.Substring(0, idx) + (char)(c + '0') + s.Substring(idx + 1);
        }
    }
}