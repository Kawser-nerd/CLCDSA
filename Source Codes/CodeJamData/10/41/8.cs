using System;using System.Collections.Generic;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader fileIn = new StreamReader("input.txt");
            string[] mass=fileIn.ReadToEnd().Split(new string[] { Environment.NewLine }, StringSplitOptions.RemoveEmptyEntries);
            fileIn.Close();
            int t = int.Parse(mass[0]);
            int fr = 1;
            List<List<int>> lst = new List<List<int>>();
            List<List<int>> tmp;
            char[] splitter = new char[]{' '};
            StreamWriter wr = new StreamWriter("output.txt");
            int[] answers = new int[250];
            answers[0] = 0;
            int zz = 1;
            for (int i = 1; i != answers.Length; i++)
            {
                answers[i] = answers[i - 1] + zz;
                zz += 2;
            }
            for (int x = 0; x != t; x++)
            {
                int k = int.Parse(mass[fr++]);
                int k2 = (k << 1) - 1;
                int k3 = k2 - 1;
                lst.Clear();
                for (int i = 0; i != k2; i++)
                {
                    lst.Add(new List<int>());
                    string[] tmp2 = mass[fr++].Split(splitter, StringSplitOptions.RemoveEmptyEntries);
                    for (int j = 0; j != tmp2.Length; j++)
                    {
                        lst[i].Add(int.Parse(tmp2[j]));
                    }
                }
                if (k == 1)
                {
                    wr.WriteLine("Case #{0}: 0", x + 1);
                    continue;
                }
                int mn1 = k - 1, mn2 = k - 1;
                for (int i = 1; i != k3; i++)
                {
                    int mm = Math.Min(i + 1, k2 - i);
                    bool met = true;
                    for (int j = 1; j != mm; j++)
                    {
                        List<int> lst1 = lst[i - j];
                        List<int> lst2 = lst[i + j];
                        int it1 = 0;
                        int it2 = 0;
                        if (lst2.Count > lst1.Count) it2 += (lst2.Count - lst1.Count) >> 1;
                        else
                            if (lst1.Count > lst2.Count) it1 += (lst1.Count - lst2.Count) >> 1;
                        int mm2 = Math.Min(lst1.Count, lst2.Count);
                        for (int z = 0; z != mm2; z++)
                        {
                            if (lst1[it1] != lst2[it2])
                            {
                                met = false;
                                break;
                            }
                            it1++;
                            it2++;
                        }
                    }
                    if (met)
                    {
                        mn1 = Math.Min(mn1, Math.Abs(k - i - 1));
                    }
                }
                tmp = lst;
                lst = new List<List<int>>();
                for (int i = 0; i != k2; i++)
                {
                    int fr2 = Math.Abs(k - i - 1);
                    int t2 = k2 - fr2 + 1;
                    lst.Add(new List<int>());
                    for (int j = fr2; j != t2; j += 2)
                    {
                        lst[i].Add(tmp[j][0]);
                        tmp[j].RemoveAt(0);
                    }
                }

                for (int i = 1; i != k3; i++)
                {
                    int mm = Math.Min(i + 1, k2 - i);
                    bool met = true;
                    for (int j = 1; j != mm; j++)
                    {
                        List<int> lst1 = lst[i - j];
                        List<int> lst2 = lst[i + j];
                        int it1 = 0;
                        int it2 = 0;
                        if (lst2.Count > lst1.Count) it2 += (lst2.Count - lst1.Count) >> 1;
                        else
                            if (lst1.Count > lst2.Count) it1 += (lst1.Count - lst2.Count) >> 1;
                        int mm2 = Math.Min(lst1.Count, lst2.Count);
                        for (int z = 0; z != mm2; z++)
                        {
                            if (lst1[it1] != lst2[it2])
                            {
                                met = false;
                                break;
                            }
                            it1++;
                            it2++;
                        }
                    }
                    if (met)
                    {
                        mn2 = Math.Min(mn2, Math.Abs(k - i - 1));
                    }
                }

                wr.WriteLine("Case #{0}: {1}", x + 1, answers[k + mn1 + mn2] - answers[k]);


            }
            wr.Close();
        }
    }
}
