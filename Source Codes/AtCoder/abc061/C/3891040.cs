using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C061
    {
        static void Main(string[] args)
        {
            string[] s1 = Console.ReadLine().Split(' ');
            int N = int.Parse(s1[0]);
            long K = long.Parse(s1[1]);

            SortedDictionary<int, long> dic = new SortedDictionary<int, long>();
            List<int> list = new List<int>();
            for (int i = 0; i < N; i++)
            {
                string[] s = Console.ReadLine().Split(' ');
                int a = int.Parse(s[0]);
                int b = int.Parse(s[1]);

                if (!dic.ContainsKey(a)) dic.Add(a, 0);
                dic[a] += b;
            }

            long counter = 0;
            int index = 0;
            List<long> v = dic.Values.ToList();
            while (true)
            {
                counter += v[index];
                if (counter >= K) break;
                index++;
            }
            int x = dic.Keys.ToList()[index];
            Console.WriteLine(x);

        }
    }
}