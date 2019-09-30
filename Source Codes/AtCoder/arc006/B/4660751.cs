using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        int N, L;
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        L = int.Parse(str[1]);
        string s;
        int[] T = new int[N];
        for (int i = 0; i < N; i++)
            T[i] = i + 1;
        for(int i = 0; i < L; i++)
        {
            s = Console.ReadLine();
            for(int j = 1; j < s.Length; j += 2)
            {
                if (s[j] == '-')
                {
                    int tmp = T[j / 2];
                    T[j / 2] = T[j / 2 + 1];
                    T[j / 2 + 1] = tmp;
                }
            }
        }
        s = Console.ReadLine();
        for (int i = 0; i < s.Length; i += 2)
        {
            if (s[i] == 'o')
                Console.WriteLine(T[i / 2]);
        }
    }
}