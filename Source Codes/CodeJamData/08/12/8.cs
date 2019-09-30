using System;
using System.Collections.Generic;
using System.IO;

using System.Text;

public class Test
{
    public static void Main(string[] args)
    {
        using (StreamReader sr = new StreamReader("C:\\Users\\int\\Desktop\\test.in"))
        {
            int cs = int.Parse(sr.ReadLine());
            using (StreamWriter sw = new StreamWriter("C:\\Users\\int\\Desktop\\test.out"))
            {

                for (int c = 0; c < cs; c++)
                {
                    int n = int.Parse(sr.ReadLine());
                    int m = int.Parse(sr.ReadLine());
                    List<int>[] types = new List<int>[m];
                    List<bool>[] melted = new List<bool>[m];
                    for (int i = 0; i < m; i++)
                    {
                        types[i] = new List<int>();
                        melted[i] = new List<bool>();
                        string[] strs = sr.ReadLine().Split(' ');
                        int t = int.Parse(strs[0]);
                        for (int j = 0; j < t; j++)
                        {
                            types[i].Add(int.Parse(strs[2 * j + 1]) - 1);
                            melted[i].Add(int.Parse(strs[2 * j + 2]) == 1);
                        }
                    }
                    int min = int.MaxValue;
                    int mini = -1;
                    for (int i = 0; i < (1 << n); i++)
                    {
                        bool[] b = new bool[n];
                        for (int j = 0; j < n; j++)
                        {
                            b[j] = (((1 << j) & i) != 0);
                        }
                        bool ok = true;
                        for (int j = 0; j < m; j++)
                        {
                            bool ok1 = false;
                            for (int k = 0; k < types[j].Count; k++)
                            {
                                if (b[types[j][k]] == melted[j][k])
                                {
                                    ok1 = true;
                                    break;
                                }
                            }
                            if (!ok1)
                            {
                                ok = false;
                                break;
                            }
                        }
                        if (ok)
                        {
                            int v = 0;
                            for (int j = 0; j < n; j++)
                            {
                                if (b[j])
                                    v++;
                            }
                            if (v < min)
                            {
                                min = v;
                                mini = i;
                            }
                        }
                    }
                    if (mini == -1)
                    {
                        sw.WriteLine("Case #{0}: {1}", c + 1, "IMPOSSIBLE");
                    }
                    else
                    {
                        string str = "";
                        bool[] b = new bool[n];                        
                        for (int j = 0; j < n; j++)
                        {
                            b[j] = (((1 << j) & mini) != 0);
                            if (b[j])
                                str += " 1";
                            else
                                str += " 0";
                        }
                        sw.WriteLine("Case #{0}:{1}", c + 1, str);
                    }
                }
            }
        }
    }
}
