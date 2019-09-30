using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

static class ProgramA
{
    static void Main(string[] args)
    {
        using (var prob = new CodeJamProblem('a', ProblemType.Large, 0))
        {
            int tcase = prob.ReadLineInt32();
            for (int cases = 0; cases < tcase; cases++)
            {
                int[] a = prob.ReadInt32Array();
                int r = a[0];
                int c = a[1];
                string[] ss = prob.ReadLines(r);
                char[,] s = new char[r,c];
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        s[i, j] = ss[i][j];
                bool ok = true;
                for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                        if (s[i, j] == '#')
                        {
                            if (i == r - 1 || j == c - 1)
                            {
                                ok = false;
                                break;
                            }
                            if (s[i + 1, j] != '#' || s[i, j + 1] != '#' || s[i + 1, j + 1] != '#')
                            {
                                ok = false;
                                break;
                            }
                            s[i, j] = '/';
                            s[i, j+1] = '\\';
                            s[i + 1, j] = '\\';
                            s[i + 1, j + 1] = '/';
                        }
                        if (!ok)
                            break;
                    }
                    if (!ok)
                        break;
                }
                prob.OutputCase();
                if (!ok)
                    prob.WriteLine("Impossible");
                else
                {
                    for (int i = 0; i < r; i++)
                    {
                        string ans = "";
                        for (int k = 0; k < c; k++)
                            ans += s[i, k];
                        prob.WriteLine(ans);
                    }
                }
            }
        }
    }
}
