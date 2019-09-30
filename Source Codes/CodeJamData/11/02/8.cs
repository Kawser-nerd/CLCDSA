using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

static class ProgramB
{
    static void Main(string[] args)
    {
        using (var prob = new CodeJamProblem('b', ProblemType.Large, 0))
        {
            int t = prob.ReadLineInt32();
            for (int cases = 0; cases < t; cases++)
            {
                int[,] combine = new int[26, 26];
                for (int i = 0; i < 26; i++)
                    for (int j = 0; j < 26; j++)
                        combine[i,j] = -1;

                bool[,] oppo = new bool[26, 26];

                string[] cur = prob.ReadParts();
                int ncombine = int.Parse(cur[0]);
                int ind = 1;
                for (int i = 0; i < ncombine; i++)
                {
                    int x = cur[ind][0] - 'A';
                    int y = cur[ind][1] - 'A';
                    int z = cur[ind][2] - 'A';
                    combine[x, y] = combine[y, x] = z;
                    ind++;
                }
                int noppo = int.Parse(cur[ind++]);
                for (int i = 0; i < noppo; i++)
                {
                    int x = cur[ind][0] - 'A';
                    int y = cur[ind][1] - 'A';
                    oppo[x, y] = oppo[y, x] = true;
                    ind++;
                }
                int len = int.Parse(cur[ind++]);
                Stack<int> stack = new Stack<int>();
                foreach (char c in cur[ind])
                {
                    int x = c - 'A';
                    if (stack.Count == 0)
                    {
                        stack.Push(x);
                        continue;
                    }
                    if (combine[x, stack.Peek()] != -1)
                    {
                        int y = stack.Pop();
                        stack.Push(combine[x, y]);
                        continue;
                    }

                    bool found = false;
                    for (int i = 0; i < 26; i++)
                    {
                        if (oppo[x,i] && stack.Contains(i))
                        {
                            found = true;
                            stack.Clear();
                            break;
                        }
                    }
                    if (!found)
                        stack.Push(x);
                }
                string ans = "[";
                int[] s = stack.ToArray();
                for (int i = s.Length - 1; i >= 0; i--)
                {
                    ans += (char)(s[i] + 'A');
                    if (i > 0)
                        ans += ", ";
                }
                ans += "]";
                prob.OutputCase(ans);
            }
        }
    }
}
