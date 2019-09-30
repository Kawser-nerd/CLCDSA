#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
// Do not use: System.Numerics;

public class Test
{
    public static void Main()
    {
        int n = Int32.Parse(Console.ReadLine());

        KeyValuePair<char, int>[] dictmax = null;

        for (int i = 0; i < n; i++)
        {
            var line1 = Console.ReadLine();

            var dict = new Dictionary<char, int>();

            foreach (var c in line1)
            {
                if (!dict.ContainsKey(c))
                {
                    dict[c] = 0;
                }

                dict[c]++;
            }

            if (dictmax == null)
            {
                dictmax = dict.OrderBy(x => x.Key).ToArray();
            }
            else
            {
                for (int j = 0; j < dictmax.Length; j++)
                {
                    var kvpair = dictmax[j];

                    if (dict.ContainsKey(kvpair.Key))
                    {
                        dictmax[j] = new KeyValuePair<char, int>(kvpair.Key, Math.Min(kvpair.Value, dict[kvpair.Key]));
                    }
                    else
                    {
                        dictmax[j] = new KeyValuePair<char, int>(kvpair.Key, 0);
                    }
                }
            }

        }

        for (int j = 0; j < dictmax.Length; j++)
        {
            var kvpair = dictmax[j];

            for (int k = 0; k < kvpair.Value; k++)
            {
                Console.Write(kvpair.Key);
            }
        }

        Console.WriteLine();
    }
}