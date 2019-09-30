using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_2010
{
    class A
    {
        static string[] tab = new string[200];
        static void gen()
        {
            Console.WriteLine("1");
            Console.WriteLine("51");
            int K=51;
            for (int i = 0; i < K; i++)
            {
                spaces(K - i - 1);
                numbers(i + 1,2);
                Console.WriteLine();
            }
            for (int i = K; i < 2*K-1; i++)
            {
                spaces(i+1-K);
                numbers(2*K-i-1, 2);
                Console.WriteLine();
            }
        }
        static void spaces(int x){
            for (int i = 0; i < x; i++)
                Console.Write(" ");
        }
        static void numbers(int x, int num)
        {
            for(int i=0; i<x; i++)
                Console.Write(num + " ");
        }

        static void Main(string[] args)
        {
           int T, K;
            T = int.Parse(Console.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                K = int.Parse(Console.ReadLine());
                for (int j = 0; j < 2 * K - 1; j++)
                {
                    tab[j] = Console.ReadLine();
                }
                int poz_s = 0;

                for (int j = 0; j < K; j++)
                {
                    int start=K-j-1, end=2 * j;
                    bool symetry=true;
                    for (int idx = 0; idx <= end; idx ++)
                    {
                        int len = (idx <= end / 2) ? idx : end - idx;
                        if(idx%2==0){
                            for(int k=2; k<=len; k+=2){
                                if(tab[j-len][start+ idx]!=tab[j+len][start+idx]){
                                    symetry=false;
                                    break;
                                }
                            }

                        }else{
                            for (int k = 1; k <= len; k += 2)
                            {
                                if (tab[j - len][start + idx] != tab[j + len][start + idx])
                                {
                                    symetry = false;
                                    break;
                                }
                            }
                        }
                        if(!symetry) break;
                    }
                    if (symetry)
                    {
                        poz_s = (K - 1 - j);
                    }
                }

                for (int j = K; j < 2*K-1; j++)
                {
                    int start = j-K+1, end = 2*(2 * (K-1)-j);
                    bool symetry = true;
                    for (int idx = 0; idx <= end; idx++)
                    {
                        int len = (idx <= end / 2) ? idx : end - idx;
                        if (idx % 2 == 0)
                        {
                            for (int k = 2; k <= len; k += 2)
                            {
                                if (tab[j - len][start + idx] != tab[j + len][start + idx])
                                {
                                    symetry = false;
                                    break;
                                }
                            }

                        }
                        else
                        {
                            for (int k = 1; k <= len; k += 2)
                            {
                                if (tab[j - len][start + idx] != tab[j + len][start + idx])
                                {
                                    symetry = false;
                                    break;
                                }
                            }
                        }
                        if (!symetry) break;
                    }
                    if (symetry)
                    {
                        poz_s = poz_s > (j - K+1) ? (j - K+1) : poz_s;
                    }
                }

                int poz_p = 0;

                for (int j = 0; j < K; j++)
                {
                    int start = K - j - 1, end = 2 * j;
                    bool symetry = true;
                    for (int idx = 0; idx <= end; idx++)
                    {
                        int len = (idx <= end / 2) ? idx : end - idx;
                        if (idx % 2 == 0)
                        {
                            for (int k = 2; k <= len; k += 2)
                            {
                                if (tab[start + idx][j - len] != tab[start + idx][j + len])
                                {
                                    symetry = false;
                                    break;
                                }
                            }

                        }
                        else
                        {
                            for (int k = 1; k <= len; k += 2)
                            {
                                if (tab[start + idx][j - len] != tab[start + idx][j + len])
                                {
                                    symetry = false;
                                    break;
                                }
                            }
                        }
                        if (!symetry) break;
                    }
                    if (symetry)
                    {
                        poz_p = (K - 1 - j);
                    }
                }

                for (int j = K; j < 2 * K - 1; j++)
                {
                    int start = j - K + 1, end = 2 * (2 * (K - 1) - j);
                    bool symetry = true;
                    for (int idx = 0; idx <= end; idx++)
                    {
                        int len = (idx <= end / 2) ? idx : end - idx;
                        if (idx % 2 == 0)
                        {
                            for (int k = 2; k <= len; k += 2)
                            {
                                if (tab[start + idx][j - len] != tab[start + idx][j + len])
                                {
                                    symetry = false;
                                    break;
                                }
                            }

                        }
                        else
                        {
                            for (int k = 1; k <= len; k += 2)
                            {
                                if (tab[start + idx][j - len] != tab[start + idx][j + len])
                                {
                                    symetry = false;
                                    break;
                                }
                            }
                        }
                        if (!symetry) break;
                    }
                    if (symetry)
                    {
                        poz_p = poz_p > (j - K + 1) ? (j - K + 1) : poz_p;
                    }
                }
                Console.WriteLine("Case #" + i + ": " + calc(K, poz_s + poz_p));
                /*
                if (poz_s < poz_p)
                {
                    Console.WriteLine("Case #" + i + ": " + calc(K, poz_p));
                }
                else
                {

                    Console.WriteLine("Case #" + i + ": " + calc(K,poz_s));
                }*/
                
            }
        }

        static int calc(int k, int poz)
        {
            return (k + poz) * (k + poz) - k * k;
        }
    }
}
