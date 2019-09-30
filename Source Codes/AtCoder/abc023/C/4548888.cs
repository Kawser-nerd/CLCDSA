using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C023
    {
        static void Main(string[] args)
        {
            int[] b1 = Console.ReadLine().Split(' ').Select(z => int.Parse(z)).ToArray();
            int R = b1[0], C = b1[1], K = b1[2];
            int N = int.Parse(Console.ReadLine());
            List<int[]> list = new List<int[]>();
            for(int i = 0; i < N; i++)
            {
                int[] cd = Console.ReadLine().Split(' ').Select(z => int.Parse(z)).ToArray();
                list.Add(cd);
            }

            //???????
            HashSet<int>[] candies = new HashSet<int>[C];
            for(int j = 0; j < C; j++)
            {
                candies[j] = new HashSet<int>();
            }
            //??????????????
            SortedDictionary<int, int> dic = new SortedDictionary<int, int>();

            int[] Sc = new int[R];
            int[] Sr = new int[C];
            foreach (int[] cd in list)
            {
                int r = cd[0] - 1, c = cd[1] - 1;
                Sc[r]++; Sr[c]++;

                HashSet<int> set = new HashSet<int>();
                candies[c].Add(r);
            }

            for(int j = 0; j < R; j++)
            {
                if (!dic.ContainsKey(Sc[j])) dic.Add(Sc[j],0);
                dic[Sc[j]]++;
            }

            long counter = 0;
            for (int i = 0; i < C; i++)
            {
                int k0 = K - Sr[i];
                long cnt = 0;
                if (dic.ContainsKey(k0)) cnt = dic[k0];
                //??
                foreach (int r in candies[i])
                {
                    if (Sc[r] == K - Sr[i] + 1) cnt++;
                    else if (Sc[r] == K - Sr[i]) cnt--;
                }
                counter += cnt;
            }
            Console.WriteLine(counter);

        }

    }
}