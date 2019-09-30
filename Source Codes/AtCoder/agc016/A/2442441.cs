using System;
using System.Collections;
using System.Linq;
namespace AGC016A
{
    class Program
    {
        private static string alp = "abcdefghijklmnopqrstuvwxyz";
        static int GetIdx(char c)
        {
            for (int i = 0; i < alp.Length; i++)
                if (c == alp[i])
                    return i;
            return -1;
        }
        static void Main()
        {
            string s = Console.ReadLine();
            bool f = true;
            for (int i = 0; i < s.Length - 1; i++)
                f = f && s[i] == s[i + 1];
            if (f)
            {
                Console.WriteLine(0);
                Environment.Exit(0);
            }
            int[] nums = new int[s.Length];
            bool[] exist = new bool[alp.Length];
            for (int i = 0; i < s.Length; i++)
            {
                nums[i] = GetIdx(s[i]);
                exist[nums[i]] = true;
            }
            int[] num2 = new int[s.Length];
            ArrayList al = new ArrayList();
            int j;
            for (int i = 0; i < alp.Length; i++)
            {
                if (exist[i])
                {
                    for (j = 0; j < s.Length; j++)
                        num2[j] = (nums[j] == i) ? 1 : 0;
                    for (j = 0; ; j++)
                    {
                        for (int k = 0; k < s.Length - j - 1; k++)
                            num2[k] = (num2[k] == 1 || num2[k + 1] == 1) ? 1 : 0;
                        for (int k = s.Length - j - 1; k < s.Length; k++)
                            num2[k] = 1;
                        if (num2.Sum() == s.Length)
                        {
                            al.Add(j + 1);
                            break;
                        }
                    }
                }
            }
            int[] ans = (int[])al.ToArray(typeof(int));
            Console.WriteLine(ans.Min());
        }
    }
}