using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC116
{
    class Sushi
    {
        public long d;
        public int t;
        public bool top;
    }

    class D
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int N = int.Parse(s[0]), K = int.Parse(s[1]);

            List<Sushi> list = new List<Sushi>();
            for (int i = 0; i < N; i++)
            {
                string[] s0 = Console.ReadLine().Split(' ');
                int t = int.Parse(s0[0]);
                long d = long.Parse(s0[1]);
                Sushi sushi = new Sushi();
                sushi.d = d; sushi.t = t;
                list.Add(sushi);
            }
            list = list.OrderByDescending(x => x.d).ToList();

            //?t?????d???Sushi?Top???????
            HashSet<int> tset = new HashSet<int>();
            for (int i = 0; i < N; i++)
            {
                Sushi sushi = list[i];
                if (!tset.Contains(sushi.t))
                {
                    sushi.top = true;
                    tset.Add(sushi.t);
                }
            }

            int indexA = K - 1;
            int indexB = K;
            var tlist = list.Take(K);
            long countType = tlist.GroupBy(x => x.t).Count();
            long sum = tlist.Sum(x => x.d);
            long sd = sum + countType * countType;
            long smax = sd;
            while (indexA >= 0 && indexB < N)
            {
                while (list[indexA].top)
                {
                    indexA--;
                    if (indexA < 0) goto Fin;
                }

                while (!list[indexB].top)
                {
                    indexB++;
                    if (indexB >= N) goto Fin;
                }

                sum += list[indexB].d - list[indexA].d;
                countType++;
                long sdn = sum + countType * countType;
                if (sdn > smax) smax = sdn;

                indexA--;
                indexB++;
            }

        Fin:
            Console.WriteLine(smax);
        }

    }
}