using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class C
{
    static void Main()
    {
        int T = ReadInt();
        for (int t = 1; t <= T; t++)
        {
            long[] ls = ReadLongs();
            if (ls[0] == 20)
            {
                long[] found = new long[2000001];
                List<long> nums = new List<long>();
                nums.Add(0);
                bool finish = false;
                for (int i = 1; !finish && i < ls.Length; i++)
                {
                    List<long> tn = new List<long>();
                    foreach (long l in nums)
                    {
                        if (found[l + ls[i]] != 0)
                        {
                            Console.WriteLine("Case #{0}:", t);
                            Console.WriteLine((ls[i] + " " + get(found, l)).Trim());
                            Console.WriteLine(get(found, l + ls[i]));
                            finish = true;
                            break;
                        }
                        found[l + ls[i]] = ls[i];
                        tn.Add(l + ls[i]);
                    }
                    nums.AddRange(tn);
                    tn.Clear();
                }
            }
            else
            {
                long[] tmp = new long[500];
                Array.Copy(ls, 1, tmp, 0, 500);
                ls = tmp;
                // TODO: Large solution
            }
        }
    }

    private static string get(long[] found, long p)
    {
        if (p == 0) return "";
        if (found[p] == p) return p.ToString();
        return found[p] + " " + get(found, p - found[p]);
    }

    #region Library

    static string ReadLine()
    {
        return Console.ReadLine();
    }

    static string[] ReadWords()
    {
        return ReadLine().Split();
    }

    static int ReadInt()
    {
        return int.Parse(ReadLine());
    }

    static int[] ReadInts()
    {
        return Array.ConvertAll(ReadWords(), int.Parse);
    }

    static long ReadLong()
    {
        return long.Parse(ReadLine());
    }

    static long[] ReadLongs()
    {
        return Array.ConvertAll(ReadWords(), long.Parse);
    }

    static decimal ReadDecimal()
    {
        return decimal.Parse(ReadLine());
    }

    static decimal[] ReadDecimals()
    {
        return Array.ConvertAll(ReadWords(), decimal.Parse);
    }

    #endregion
}
