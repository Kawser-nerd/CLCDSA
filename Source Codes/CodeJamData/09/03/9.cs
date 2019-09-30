using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace test.Google
{
    public class gcj2009
    {
        public static void Main(string[] arg)
        {
            try
            {
                using (StreamReader sr = new StreamReader(arg[0]))
                using (StreamWriter sw = new StreamWriter(arg[1]))
                {
                    int NUM = int.Parse(sr.ReadLine());
                    for (int i = 0; i < NUM; ++i)
                    {
                        int res = 0;
                        string str = sr.ReadLine();
                        string pattern = "welcome to code jam";
                        int len = pattern.Length;
                        int[] nums = new int[len + 1];
                        nums[0] = 1;
                        foreach (char ch in str)
                        {
                            nums[len] = 0;
                            for (int j = 0; j < len; ++j)
                            {
                                if (ch == pattern[j]) nums[j + 1] += nums[j];
                                nums[j + 1] %= 10000;
                            }
                            res += nums[len];
                            res %= 10000;
                        }

                        sw.WriteLine("Case #" + (i + 1) + ": " + res.ToString("D4"));
                    }
                }
            }
            catch (Exception e) { Console.WriteLine(e.Message + e.StackTrace); }
            Console.ReadKey();
        }
    }
}
