using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace b
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] hwn = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long h = hwn[0];
            long w = hwn[1];
            long n = hwn[2];

            long[] ans = new long[10];

            HashMap<long, int> map = new HashMap<long, int>();

            for (int i = 0; i < n; i++)
            {
                string[] abstr = Console.ReadLine().Split(' ');
                long x = long.Parse(abstr[0]) - 1;
                long y = long.Parse(abstr[1]) - 1;

                for (int dx = 0; dx < 3; dx++)
                {
                    for (int dy = 0; dy < 3; dy++)
                    {
                        long px = x - dx;
                        long py = y - dy;
                        if (px < 0 || py < 0) continue;
                        if (px + 3 > h || py + 3 > w) continue;
                        map[px * 10000000000 + py]++;
                    }
                }


            }
            foreach (var d in map)
            {
                ans[d.Value]++;
            }

            ans[0] = (h - 2) * (w - 2) - map.Count;

            for (int i = 0; i < ans.Length; i++)
            {
                Console.WriteLine(ans[i]);
            }
        }
    }
}
#region HashMap
public class HashMap<K, V> : Dictionary<K, V>
//where V : new()
{
    public HashMap() : base() { }
    public HashMap(int cap) : base(cap) { }
    new public V this[K i]
    {
        get
        {
            V v;
            return TryGetValue(i, out v) ? v :
                base[i] = default(V);
            //base[i] = new V();
        }
        set { base[i] = value; }
    }
}
#endregion