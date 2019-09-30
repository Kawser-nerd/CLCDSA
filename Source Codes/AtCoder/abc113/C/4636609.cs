using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace AtCoderABC113
{
    class City
    {
        public int num;
        public long id;
        public City(int n, long i)
        {
            num = n;
            id = i;
        }
    }
    class Program
    {
        public static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int N = int.Parse(s[0]);
            int M = int.Parse(s[1]);
            List<City>[] P = new List<City>[N];
            for (int i = 0; i < N; i++) P[i] = new List<City>();
            for (int i = 0; i < M; i++)
            {
                s = Console.ReadLine().Split(' ');
                int p = int.Parse(s[0]);
                int y = int.Parse(s[1]);
                P[p - 1].Add(new City(i + 1, (long)y));
            }
            List<City> reslist = new List<City>();
            for (int i = 0; i < N; i++)
            {
                P[i] = P[i].OrderBy(x => x.id).ToList();
                for (int j = 0; j < P[i].Count; j++)
                {
                    P[i][j].id = (long)(i + 1) * 1000000 + j + 1;
                    reslist.Add(P[i][j]);
                }
            }
            reslist = reslist.OrderBy(x => x.num).ToList();
            for (int i = 0; i < M; i++)
            {
                Console.WriteLine(Convert.ToString(reslist[i].id, 10).PadLeft(12, '0'));
            }
        }
    }
}