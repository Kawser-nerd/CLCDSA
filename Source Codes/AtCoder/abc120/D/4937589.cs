using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC120D
{
    class MainClass
    {

        static int[] nm;
       
        public static void Main(string[] args)
        {
            nm = Array.ConvertAll(Console.ReadLine().Split().ToArray(), int.Parse);
            var ablst = new List<int[]>();
            for(int i = 0; i < nm[1]; i++)
            {
                int[] ab = Array.ConvertAll(Console.ReadLine().Split().ToArray(), int.Parse);
                ablst.Add(ab);
            }

            UnionFind uni = new UnionFind(nm[0]);

            long fuben = ((long)nm[0] * ((long)nm[0] - 1)) / 2;
            var anslst = new List<long>();
            for(int i = ablst.Count - 1; i >= 0; i--)
            {
                anslst.Add(fuben);
                int a = ablst[i][0]-1;
                int b = ablst[i][1]-1;
                long asize = uni.Size(a);
                long bsize = uni.Size(b);
                if (uni.Connect(a, b))
                {
                    //Console.WriteLine("a " + a + " b " + b +" size(a) : " + uni.Size(a) + " size(b) : " + uni.Size(b));
                    fuben -= asize * bsize;
                }
            }

            anslst.Reverse();
            anslst.ForEach(Console.WriteLine);

        }
    }

    class UnionFind
    {
        public List<int> Parent;
        public UnionFind(int n)
        {
            //?????????????????????-(???)
            this.Parent = Enumerable.Repeat(-1, n).ToList();
        }

        public int Size(int a)
        {
            if (Parent[a] < 0)return -Parent[a];
            else return -Parent[Root(a)];
        }

        public int Root(int a)
        {
            if (Parent[a] < 0) return a;
            else
            {
                int root = Root(Parent[a]);
                Parent[a] = root;
                return root;
            }
        }

        public bool Connect(int a, int b)
        {
            a = Root(a);
            b = Root(b);
            if (a == b) return false;
            else
            {
                //a > b???
                if (a < b)
                {
                    int tmp = a;
                    a = b;
                    b = tmp;
                }
                //b???a????a?size?b??????
                Parent[a] += Parent[b];
                Parent[b] = a;
                return true;
            }
        }
    }
}