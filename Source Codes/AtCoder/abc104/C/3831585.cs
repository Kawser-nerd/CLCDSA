using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        string[] s = Console.ReadLine().Split().ToArray();
        int d = int.Parse(s[0]);
        int g = int.Parse(s[1]);

        int[] p = new int[d];
        int[] c = new int[d];
        int[] all_AC_sum = new int[d];

        for (int i = 0; i < d; i++)
        {
            s = Console.ReadLine().Split().ToArray();
            p[i] = int.Parse(s[0]);
            c[i] = int.Parse(s[1]);
            all_AC_sum[i] = p[i] * (i + 1) * 100 + c[i];
        }

        int AC_n = int.MaxValue;
        
        // Math.Pow(2, d)?1 << d???
        for (int i = 0; i < Math.Pow(2, d); i++)
        {
            bool[] bits = new bool[d];
            for (int j = 0; j < d; j++)
            {
                if ((1 & i >> j) == 1) bits[j] = true;
            }
            int sum = 0;
            int tmp_AC_n = 0;
            for (int j = 0; j < bits.Length; j++)
            {
                if (bits[j])
                {
                    sum += all_AC_sum[j];
                    tmp_AC_n += p[j];
                    Debug.Write(all_AC_sum[j]);
                }
                else Debug.Write('-');
            }
            if (sum >= g)
            {
                Debug.Write("=" + sum + "?\n");
                AC_n = Math.Min(AC_n, tmp_AC_n);
            }
            else
            {
                Debug.Write("=" + sum + "\n");
                for (int t = bits.Length - 1; 0 <= t; t--)
                {
                    if (!bits[t])
                    {
                        for (int part_AC_n = 1; part_AC_n <= p[t]; part_AC_n++)
                        {
                            sum += 100 * (t + 1);
                            if (sum >= g)
                            {
                                Debug.WriteLine("=" + sum + "(" + (t + 1) * 100 + "????" + part_AC_n + "?)?\n");
                                AC_n = Math.Min(AC_n, tmp_AC_n + part_AC_n);
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
        Console.WriteLine(AC_n);
    }
}