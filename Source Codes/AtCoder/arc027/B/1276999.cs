using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC027B
{
    class Program
    {
        static int N;
        static int[] uni;

        static bool[] used;
        static bool[] mostSignificant;
        static bool[] constant;

        static void init(int n)
        {
            N = n;
            uni = new int[n];
            for (int i = 0; i < n; i++)
                uni[i] = -1;

            used = new bool[n];
            mostSignificant = new bool[n];
            constant = new bool[n];
        }

        static int root(int a)
        {
            if (uni[a] < 0)
                return a;
            else
                return uni[a] = root(uni[a]);
        }

        static bool connect(int a, int b)
        {
            a = root(a);
            b = root(b);
            if (a == b) return false;
            if (uni[a] > uni[b]) swap(ref a, ref b);
            uni[a] += uni[b];
            uni[b] = a;
            return true;
        }

        static void swap<T>(ref T a, ref T b)
        {
            T c = a;
            a = b;
            b = c;
        }

        static  int conv(char c)
        {
            return c - 'A';
        }

        static bool isAlpha(char c)
        {
            return c >= 'A' && c <= 'Z';
        }

        static void Main(string[] args)
        {
            int l = int.Parse(Console.ReadLine());
            string s1 = Console.ReadLine();
            string s2 = Console.ReadLine();

            init(26);

            for (int i = 0; i < l; i++)
            {
                if (isAlpha(s1[i]))
                {
                    used[conv(s1[i])] = true;
                }
                if (isAlpha(s2[i]))
                {
                    used[conv(s2[i])] = true;
                    if (isAlpha(s1[i]))
                    {
                        connect(conv(s1[i]), conv(s2[i]));
                    }
                }
            }

            for(int i=0; i < l; i++)
            {
                if(isAlpha(s1[i]) && !isAlpha(s2[i]))
                {
                    constant[root(conv(s1[i]))] = true;
                }
                if (!isAlpha(s1[i]) && isAlpha(s2[i]))
                {
                    constant[root(conv(s2[i]))] = true;
                }
            }

            if(isAlpha(s1[0]))
            {
                mostSignificant[conv(s1[0])] = true;
            }
            if (isAlpha(s2[0]))
            {
                mostSignificant[conv(s2[0])] = true;
            }

            long count = 1;
            for(int c = 0; c < 26; c++)
            {
                if(used[c])
                {
                    if(root(c) == c)
                    {
                        if (constant[c])
                            continue;
                        else if (mostSignificant[c])
                            count *= 9;
                        else
                            count *= 10;
                    }
                }
            }

            Console.WriteLine(count);
        }
    }
}