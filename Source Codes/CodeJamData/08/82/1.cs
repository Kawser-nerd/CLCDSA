using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A
{
    class Program
    {

        class Painter : IComparable
        {
            public int start, end;
            public int col;
            public Painter(int s, int e, int a)
            {
                start = s;
                end = e;
                col = a;
            }
            public int CompareTo(Object o)
            {
                Painter k = (Painter)o;
                if (start < k.start) return -1;
                else if (start > k.start) return 1;
                else return 0;
            }
        }
        public static int work()
        {
            int N = int.Parse(Console.ReadLine());
            ArrayList tab = new ArrayList();
            String[] colours = new String[N];
            int idx = 0;
            for (int j = 0; j < N; j++)
            {
                String[] s = Console.ReadLine().Split(' ');
                int id = -1;
                for (int k = 0; k < idx; k++)
                    if (colours[k] == s[0])
                    {
                        id = k;
                        break;
                    }
                if (id == -1)
                {
                    colours[idx] = s[0];
                    id = idx;
                    idx++;
                }
                int A, B;
                A = int.Parse(s[1]) - 1;
                B = int.Parse(s[2]);
                tab.Add(new Painter(A, B, id));

            }
            tab.Sort();
            int min=1000000;
            int[] wyniki = new int[10001];
            for (int a = 0; a < idx; a++)
                for (int b = a; b < idx; b++)
                    for (int c = b; c < idx; c++)
                    {
                        for (int k = 0; k < 10001; k++) wyniki[k] = 1000000;
                        wyniki[0] = 0;
                        bool isok=true;
                        for (int k = 0; k < N; k++)
                        {
                            Painter p = (Painter)tab[k];
                            if (p.col == a || p.col == b || p.col == c)
                            {
                                if (wyniki[p.start] == 1000000)
                                {
                                    isok=false;
                                    break;
                                }
                                for (int w = p.start + 1; w <= p.end; w++ )
                                    if (wyniki[p.start] + 1 < wyniki[w])
                                        wyniki[w] = wyniki[p.start] + 1;

                            }
                        }
                        if(!isok)continue;
                        if(wyniki[10000]<min)min=wyniki[10000];
                    }
            if(min==1000000)min=-1;
            return min;

        }

        static void Main(string[] args)
        {

            int T= int.Parse(Console.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                int wyn = work();
                if (wyn < 0) Console.WriteLine("Case #" + i.ToString() + ": IMPOSSIBLE");
                else Console.WriteLine("Case #" + i.ToString() + ": " + wyn.ToString());
            }
        }
    }
}
