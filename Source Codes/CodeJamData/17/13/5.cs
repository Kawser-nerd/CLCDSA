using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    public class CodeJam
    {
        static Random random = new Random();
        static StringBuilder sb = new StringBuilder();
        static int Hd, Ad, Hk, Ak, B, D;
        public static void Start() {
            Console.SetIn(new StreamReader("C:\\codejam\\input.sublime"));

            int TC = int.Parse(Console.ReadLine());
            for (int tc = 0; tc < TC; tc++) {
                var tmp = Console.ReadLine().Split(' ');
                Hd = int.Parse(tmp[0]);
                Ad = int.Parse(tmp[1]);
                Hk = int.Parse(tmp[2]);
                Ak = int.Parse(tmp[3]);
                B = int.Parse(tmp[4]);
                D = int.Parse(tmp[5]);

                string ans = solve().ToString();
                Console.WriteLine(ans);
                sb.Append(string.Format("Case #{0}: {1}\n", tc + 1, ans));
            }
            --sb.Length;
            Console.WriteLine(sb.ToString());
            Console.SetOut(new StreamWriter("C:\\codejam\\output.sublime"));
            Console.Write(sb.ToString());
            Console.Out.Close();
        }

        static int min;
        static object solve() {
            map = new Dictionary<long, int>();
            min = 10000;
            rec(Hd + Ak, Ad, Hk, Ak, 0);
            if (min == 10000) return "IMPOSSIBLE";
            return min;
        }
        static Dictionary<long, int> map = new Dictionary<long, int>(); 
        static void rec(int hd, int ad, int hk, int ak, int cur) {
            if (cur >= min) return;
            if (hk < 1) {
                min = cur; return;
            }
            hd -= ak;
            if (hd < 1) return;
            long key = hd + ad * 1000 + hk * 1000000 + ak * 1000000000L;
            if (map.ContainsKey(key) && map[key] <= cur) return;
            map[key] = cur;

            cur++;
            rec(hd, ad, hk - ad, ak, cur);
            rec(hd, ad + B, hk, ak, cur);
            rec(Hd, ad, hk, ak, cur);
            rec(hd, ad, hk, Math.Max(0, ak - D), cur);

        }
    }
}