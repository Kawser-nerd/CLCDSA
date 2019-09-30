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
            solveA(input);
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
                        break;
                    }
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
