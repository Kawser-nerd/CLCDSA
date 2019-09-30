using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = File.ReadAllLines("input.txt");
            //solveA(input);
            //solveB(input);
            solveC(input);
        }

        #region A
        static void solveA(String[] inp)
        {
            List<String> ans = new List<string>();
            int n = int.Parse(inp[0]);
            int num = 1;
            for (int i = 0; i < n; i++)
            {
                int teams = int.Parse(inp[num].Split(' ')[0]);
                int teams1 = int.Parse(inp[num].Split(' ')[1]);
                num++;
                List<List<int>> teamGames = new List<List<int>>();
                for (int j = 0; j < teams; j++)
                {
                    teamGames.Add(new List<int>());
                    for (int k = 0; k < teams1; k++)
                    {
                        if (inp[num][k] == '#')
                            teamGames[j].Add(1);
                        else
                           teamGames[j].Add(0);
                    }
                    num++;
                }
                ans.Add("Case #" + (i + 1).ToString() + ":");
                ans.AddRange(solveOneA(teamGames));
            }
            saveAnswers(ans);
        }

        private static List<String> solveOneA(List<List<int>> inp)
        {
            List<String>ans = new List<string>();
            for (int i = 0; i < inp.Count -1; i++)
            {
                for (int j = 0; j < inp[i].Count - 1; j++)
                {
                    if (inp[i][j] == 1)
                    {
                        if (inp[i + 1][j] == 1 && inp[i][j + 1] == 1 && inp[i + 1][j + 1] == 1)
                        {
                            inp[i][j] = -1;
                            inp[i + 1][j] = -2;
                            inp[i][j + 1] = -3;
                            inp[i + 1][j + 1] = -4;
                        }
                        else
                        {
                            ans.Add("Impossible");
                            return ans;
                        }
                    }
                }
            }

            for (int i = 0; i < inp.Count; i++)
            {
                ans.Add("");
                for (int j = 0; j < inp[i].Count; j++)
                {
                    switch (inp[i][j])
                    {
                        case 0:
                            ans[i] += '.';
                        break;
                        case -1:
                            ans[i] += '/';
                        break;
                        case -2:
                            ans[i] += '\\';
                        break;
                        case -3:
                            ans[i] += '\\';
                        break;
                        case -4:
                            ans[i] += '/';
                        break;
                        case 1:
                            ans.Clear();
                            ans.Add("Impossible");
                            return ans;
                        //break;
                    }
                }
            }
            return ans;
        }
        #endregion
        #region B
        static void solveB(String[] inp)
        {
            List<String> ans = new List<string>();
            int n = int.Parse(inp[0]);
            int num = 1;
            for (int i = 0; i < n; i++)
            {
                //L, t, N and C
                int L = int.Parse(inp[num].Split(' ')[0]);
                long t = long.Parse(inp[num].Split(' ')[1]);
                int N = int.Parse(inp[num].Split(' ')[2]);
                int C = int.Parse(inp[num].Split(' ')[3]);
                List<long> input = new List<long>();
                for (int j = 0; j < C; j++)
                {
                    input.Add(int.Parse(inp[num].Split(' ')[4 + j]));
                }
                int nn = C;
                while (input.Count < N)
                {
                    input.Add(input[nn % C]);
                    nn++;
                }
                num++;
                
                ans.Add(solveOneB(input, L, t, N));
            }
            saveAnswer(ans);
        }

        private static String solveOneB(List<long> inp, int count, long time, int starsCount)
        {
            String ans = "";
            long sum = 0;
            int index = 0;
            bool flag = false;
            for (int i = 0; i < starsCount; i++)
            {
                sum += inp[i] * 2;
                if (sum == time)
                {
                    index = i;
                    flag = true;
                    break;
                }
                if (sum > time)
                {
                    index = i;
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                long ssum = 0;
                List<long> maxs = new List<long>();
                for (int i = index + 1; i < starsCount; i++)
                {
                    maxs.Add(inp[i]);
                }
                maxs.Sort();
                List<long> realmaxs = new List<long>();
                for (int i = Math.Max(maxs.Count - count, 0); i < maxs.Count; i++)
                {
                    realmaxs.Add(maxs[i]);
                }
                for (int i = 0; i < starsCount; i++)
                {
                    ssum += inp[i] * 2;
                }
                for (int i = 0; i < realmaxs.Count; i++)
                {
                    ssum -= realmaxs[i];
                }
                return ssum.ToString();
            }
            else
            {
                long ssum = 0;
                List<long> maxs = new List<long>();
                for (int i = index + 1; i < starsCount; i++)
                {
                    maxs.Add(inp[i] * 2);
                }
                maxs.Add((sum - time));
                maxs.Sort();
                List<long> realmaxs = new List<long>();
                for (int i = Math.Max(maxs.Count - count, 0); i < maxs.Count; i++)
                {
                    realmaxs.Add(maxs[i] / 2);
                }
                for (int i = 0; i < starsCount; i++)
                {
                    ssum += inp[i] * 2;
                }
                for (int i = 0; i < realmaxs.Count; i++)
                {
                    ssum -= realmaxs[i];
                }
                return ssum.ToString();
            }
            
        }

        #endregion
        #region C
        static void solveC(String[] inp)
        {
            List<String> ans = new List<string>();
            int n = int.Parse(inp[0]);
            int num = 1;
            for (int i = 0; i < n; i++)
            {
                //L, t, N and C
                int count = int.Parse(inp[num].Split(' ')[0]);
                long l = long.Parse(inp[num].Split(' ')[1]);
                long h = long.Parse(inp[num].Split(' ')[2]);
                num++;
                List<long> input = new List<long>();
                for (int j = 0; j < count; j++)
                {
                    input.Add(int.Parse(inp[num].Split(' ')[j]));
                }
                num++;

                ans.Add(solveOneC(input, l, h));
            }
            saveAnswer(ans);
        }

        private static String solveOneC(List<long> inp, long low, long high)
        {
            String ans = "NO";
            List<List<long>> del = new List<List<long>>();
            for (long k = low; k <= high; k++)
            {
                bool flag = true;
                for (int i = 0; i < inp.Count; i++)
                {
                    if (k > inp[i])
                    {
                        if (k % inp[i] != 0)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (k < inp[i])
                    {
                        if (inp[i] % k != 0)
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag)
                {
                    ans = k.ToString();
                    break;
                }
            }
            return ans;
        }

        #endregion
        static void saveAnswers(List<String> ans)
        {
            for (int i = 0; i < ans.Count; i++)
            {
                ans[i] = ans[i];
            }
            File.WriteAllLines("output.txt", ans.ToArray());
        }
        static void saveAnswer(List<String> ans)
        {
            for (int i = 0; i < ans.Count; i++)
            {
                ans[i] = "Case #" + (i + 1).ToString() + ": " + ans[i];
            }
            File.WriteAllLines("output.txt", ans.ToArray());
        }
    }
}
