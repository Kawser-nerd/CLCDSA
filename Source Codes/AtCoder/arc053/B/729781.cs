using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        string inpt = Reader.ReadLine();
        this.TotalCount = inpt.Length;
        for (int i = 0; i < inpt.Length; i++)
        {
            if (dic.ContainsKey(inpt[i]))
            {
                dic[inpt[i]]++;
            }
            else
            {
                dic.Add(inpt[i], 1);
            }
        }


        if (dic.Count(a => a.Value % 2 == 1) <= 1)
        {
            Console.WriteLine(TotalCount);
            return;
        }
        int ans = this.CanCreate(1, TotalCount);
        Console.WriteLine(ans);

    }

    private int CanCreate(int min, int max)
    {
        List<int> target = this.dic.Values.ToList();
        target.Sort();
        int mid = (max + min) / 2;
        bool can = this.CanCreateSub(target, mid);
        if (can && max - mid <= 1)
        {
            if (this.CanCreateSub(target, max))
            {
                return max;
            }
            else
            {
                return mid;
            }
        }
        if (can)
        {
            return CanCreate(mid, max);
        }
        else
        {
            return CanCreate(min, mid);
        }
    }

    Dictionary<string, Dictionary<int, bool>> CanDic = new Dictionary<string, Dictionary<int, bool>>();
    private bool CanCreateSub(List<int> target, int num)
    {
        if (num == 1)
        {
            return true;
        }
        string key = string.Join("#", target);
        if (!CanDic.ContainsKey(key))
        {
            CanDic.Add(key, new Dictionary<int, bool>());

        }
        if (CanDic[key].ContainsKey(num))
        {
            return CanDic[key][num];
        }
        bool ans = false;
        int total = target.Sum();
        if (total < num)
        {
            ans = false;
            CanDic[key].Add(num, ans);
            return ans;
        }
        if (total >= num)
        {
            if (target.Count(a => a % 2 == 1) <= 1)
            {
                ans = true;
                CanDic[key].Add(num, ans);
                return ans;
            }
        }
        if (target.Count(a => a % 2 != 0) <= 1)
        {
            ans = true;
        }
        else
        {
            List<int> subTarget = new List<int>(target);
            int idx = target.IndexOf(target.Where(a => a % 2 != 0).First());
            int must = num;
            if (must % 2 == 0)
            {
                must++;
            }
            subTarget[idx] -= must;

            if (subTarget[idx] == 0)
            {
                subTarget.RemoveAt(idx);
            }
            else if (subTarget[idx] < 0)
            {
                int submust = subTarget[idx];
                subTarget.RemoveAt(idx);
                for (int i = target.Count - 2; i >= 0; i--)
                {
                    int mov = Math.Min(Math.Abs(submust), (subTarget[i] / 2) * 2);
                    subTarget[i] -= mov;
                    if (subTarget[i] == 0)
                    {
                        subTarget.RemoveAt(i);
                    }
                    submust += mov;
                    if (submust >= 0)
                    {
                        break;
                    }
                }
                if (submust < 0)
                {
                    ans = false;
                    CanDic[key].Add(num, ans);
                    return ans;

                }
            }

            subTarget.Sort();
            ans = this.CanCreateSub(subTarget, num);

        }
        CanDic[key].Add(num, ans);
        return ans;
    }

    private int TotalCount = 0;


    private Dictionary<char, int> dic = new Dictionary<char, int>();


    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"
 
succeeded
 
 
";
        private static System.IO.StringReader Sr = null;
        public static string ReadLine()
        {
            if (IsDebug)
            {
                if (Sr == null)
                {
                    Sr = new System.IO.StringReader(PlainInput.Trim());
                }
                return Sr.ReadLine();
            }
            else
            {
                return Console.ReadLine();
            }
        }
        public static int[] GetInt(char delimiter = ' ', bool trim = false)
        {
            string inptStr = ReadLine();
            if (trim)
            {
                inptStr = inptStr.Trim();
            }
            string[] inpt = inptStr.Split(delimiter);
            int[] ret = new int[inpt.Length];
            for (int i = 0; i < inpt.Length; i++)
            {
                ret[i] = int.Parse(inpt[i]);
            }
            return ret;
        }
    }
    static void Main()
    {
        Program prg = new Program();
        prg.Proc();
    }
}