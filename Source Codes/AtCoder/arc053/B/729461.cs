using System;
using System.Collections.Generic;

namespace Coder_practice
{
    class Program
    {
        class Data
        {
            public char moji { set; get; }
            public int cnt { set; get; }
        }

        static void Main(string[] args)
        {
            String S = Console.ReadLine();

            List<Data> list = new List<Data>();

            for (int i = 0; i < S.Length; i++)
            {
                if (list.Count == 0)
                {
                    list.Add(new Data() { moji = S[i], cnt = 1 });
                    continue;
                }
                else
                {
                    Data d = list.Find(delegate(Data a) { return a.moji == S[i];});
                    if (d == null)
                    {
                        list.Add(new Data() { moji = S[i], cnt = 1 });
                    }
                    else
                    {
                        d.cnt++;
                    }
                }
            }

            int sum = 0;
            int kisu = 0;

            foreach ( Data d in list) {
                if (d.cnt % 2 == 1) 
                {
                    kisu++;
                    sum += d.cnt - 1;
                }
                else
                {
                    sum += d.cnt;
                }
            }

            if (kisu == 0)
            {
                Console.WriteLine(sum);
            }
            else
            {
                int min = sum / kisu;
                if (min % 2 == 1)
                {
                    Console.WriteLine(min);
                }
                else
                {
                    Console.WriteLine(min + 1);
                }
            }
        }

    }
}