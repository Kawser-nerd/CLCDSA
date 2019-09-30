using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A
{
    class Program
    {
        static ArrayList[] pion;
        static ArrayList[] poziom;
        static int x, y, kier;
        
        public static void go(string s)
        {
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == 'L') kier = (kier + 3) % 4;
                if (s[i] == 'R') kier = (kier + 1) % 4;
                if (s[i] == 'F')
                {
                    if (kier == 0)
                    {
                        pion[y].Add(x);
                        y++;
                    }
                    if (kier == 1)
                    {
                        poziom[x].Add(y);
                        x++;
                    }
                    if (kier == 2)
                    {
                        y--;
                        pion[y].Add(x);
                    }
                    if (kier == 3)
                    {
                        x--;
                        poziom[x].Add(y);
                    }

                }
            }

        }

        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            pion = new ArrayList[6002];
            poziom = new ArrayList[6002];
            for (int j = 0; j < 6002; j++)
            {
                pion[j]=new ArrayList();
                poziom[j]=new ArrayList();
            };
            for (int i = 1; i <= N; i++)
            {
                int wyn = 0;
                for (int j = 0; j < 6002; j++)
                {
                    pion[j].Clear();
                    poziom[j].Clear();
                };
                int count = int.Parse(Console.ReadLine());
                string s = Console.ReadLine();
                x = 3000;
                y = 3000;
                kier = 0;
                bool[,] odw=new bool[6002,6002];
                string[] tab = s.Split(' ');
                while (tab.Length < count*2)
                {
                    string w = Console.ReadLine();
                    s = s +' '+ w;
                    tab = s.Split(' ');
                }
                for (int j = 0; j < count; j++)
                {
                    int e = int.Parse(tab[2 * j + 1]);
                    while (e > 0)
                    {
                        go(tab[2 * j]);
                        e--;
                    }
                }
                for (int j = 0; j < 6002; j++)
                {
                    if (pion[j].Count > 2)
                    {
                        pion[j].Sort();
                        for (int q = 0; q < pion[j].Count - 2; q++)
                        {
                            if (q % 2 == 1)
                            {
                                for(int e=(int)pion[j][q]; e<(int)pion[j][q + 1]; e++)
                                {
                                    if(!odw[j,e])
                                    {
                                        odw[j,e]=true;
                                        wyn++;
                                    }
                                }
                            }
                        }
                    }
                    if (poziom[j].Count > 2)
                    {
                        poziom[j].Sort();
                        for (int q = 0; q < poziom[j].Count - 2; q++)
                        {
                            if (q % 2 == 1)
                            {
                                for(int e=(int)poziom[j][q]; e<(int)poziom[j][q + 1]; e++)
                                {
                                    if(!odw[e,j])
                                    {
                                        odw[e,j]=true;
                                        wyn++;
                                    }
                                }
                            }
                        }
                    }
                }
                Console.WriteLine("Case #" + i.ToString() + ": " + wyn.ToString());
            }
        }
    }
}
