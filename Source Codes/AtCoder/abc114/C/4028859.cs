using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BC114
{
    class Program
    {
        static void Main(string[] args)
        {
            var obj = new Q1();
            obj.Solver();

        }
    }
    class Q1
    {
        static void Search(int n, string s, ref List<int> list)
        {
            if (n + 1 == s.Length) return;
            else if (s.Distinct().Count() == 3) list.Add(int.Parse(s));
            Search(n, "3" + s, ref list);
            Search(n, "5" + s, ref list);
            Search(n, "7" + s, ref list);
        }

        public void Solver()
        {
            int n = int.Parse(Console.ReadLine());
            var list = new List<int>();
            Search(9, "", ref list);
            list = list.OrderBy(f => f).ToList();
            int ans = 0;
            for (int i = 0; i < list.Count(); i++)
            {
                if (list[i] <= n) ans++;
                else break;
            }
            Console.WriteLine(ans);
        }
    }
    //class Q1
    //{

    //    public void Solver()
    //    {
    //        long amswer = 753;
    //        var s = Console.ReadLine().Select(x => long.Parse(x.ToString())).ToArray();
    //        long diff = 1000;

    //        for (int i = 0; i < s.Count() - 2; i++)
    //        {
    //            long temp = s[i] * 100 + s[i + 1] * 10 + s[i + 2];
    //            diff = Math.Min(diff, Math.Abs(amswer - temp));
    //        }

    //        Console.WriteLine(diff);

    //    }
    //}

    //class Q1
    //{
    //    public void Solver()
    //    {
    //        var age = int.Parse(Console.ReadLine());

    //        Console.WriteLine((age == 3 || age == 5 || age == 7) ? "YES" : "NO");

    //    }
    //}
}