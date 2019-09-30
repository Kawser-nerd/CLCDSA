using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading.Tasks;



class Program
{

    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader("D:\\in.in");
        StreamWriter sw = new StreamWriter("D:\\out.out");
        sw.AutoFlush = true;
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);

        List<G> lv = new List<G>();
        for (int i = 0; i < n; i++)
        {
            lv.Add(new G(sr));
        }
        List<Task> tl = new List<Task>();
        for (int i = 0; i < n; i++)
        {
            tl.Add(Task.Factory.StartNew(lv[i].Calc));
        }
        for (int i = 0; i < n; i++)
        {
            tl[i].Wait();
            Console.WriteLine(i);
        }

        for (int i = 0; i < n; i++)
        {
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + lv[i].r.ToString());
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }



    class G
    {
        static int MIN(int[][] d, int v, int N)
        {
            Dictionary<int, int> f = new Dictionary<int, int>();


            for (int i = 0; i < N; i++)
            {
                int x = 1;
                if ((v & 1) == 1)
                {
                    x = 2;
                }
                v >>= 1;

                foreach (var item in d[i])
                {
                    int val;
                    if (f.TryGetValue(item, out val))
                    {
                        if ((val & x) == 0)
                            f[item] |= x;
                    }
                    else
                        f.Add(item, x);
                }
            }

            int r = 0;
            foreach (var item in f.Values)
            {
                if (item == 3)
                    r++;
            }
            return r;

        }


        int[][] d;


        int N;

        public int r;
        public G(StreamReader sr)
        {
            N = int.Parse(sr.ReadLine());

            string[][] ds = new string[N][];
            for (int i = 0; i < N; i++)
            {
                ds[i] = sr.ReadLine().Split(' ');
            }

            Dictionary<string, int> f = new Dictionary<string, int>();
            int ccc = 0;
            d = new int[N][];

            for (int i = 0; i < N; i++)
            {
                d[i] = new int[ds[i].Length];
                for (int j = 0; j < ds[i].Length; j++)
                {
                    string s = ds[i][j];
                    if (!f.ContainsKey(s))
                    {
                        f.Add(s, ccc++);
                    }
                    d[i][j] = f[s];
                }
            }

        }

        public void Calc()
        {
            r = MIN(d, 1, N);

            int g = 1 << (N - 2);
            if (N > 2)
                for (int i = 0; i < g; i++)
                {
                    r = Math.Min(r, MIN(d, (i << 2) + 1, N));
                }
        }
    }
}