using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    void solve()
    {
        int n = int.Parse(Console.ReadLine());
        int[] min = new int[26];

        for (int i = 0; i < 26; ++i)
        {
            min[i] = 100;
        }

        for (int i = 0; i < n; ++i)
        {
            string str = Console.ReadLine();
            int[] cnt = new int[26];

            for (int j = 0; j < str.Length; ++j)
            {
                cnt[str[j] - 'a']++;
            }
            for (int j = 0; j < 26; ++j)
            {
                if (cnt[j] < min[j])
                {
                    min[j] = cnt[j];
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 26; ++i)
        {
            sb.Append((char)('a' + (char)i), min[i]);
        }
        Console.WriteLine(sb.ToString());
    }
    public static int Main()
    {
        bool loop = false;
#if ES_DEBUG
        loop = true;
#endif
        do
        {
            new Program().solve();
        } while (loop);
        return 0;
    }
}