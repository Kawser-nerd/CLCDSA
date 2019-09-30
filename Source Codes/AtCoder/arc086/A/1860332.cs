using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    void solve()
    {
        string[] buf = Console.ReadLine().Split(' ');
        int n = int.Parse(buf[0]);
        int k = int.Parse(buf[1]);

        Dictionary<int, int> d = new Dictionary<int, int>();
        buf = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; ++i)
        {
            int A = int.Parse(buf[i]);
            if (d.ContainsKey(A))
            {
                d[A] = d[A] + 1;
            }
            else
            {
                d.Add(A, 1);
            }
        }

        int j = 0;
        int count = 0;
        var sorted = d.OrderBy((x) => x.Value);
        foreach (var x in sorted)
        {
            if (d.Count - k < ++j)
            {
                break;
            }
            count += x.Value;

        }
        Console.WriteLine(count);
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