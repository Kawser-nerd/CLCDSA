using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(@"..\..\input.txt");
        StreamWriter sw = new StreamWriter(@"..\..\output.txt");
        int N = int.Parse(sr.ReadLine());
        for (int i = 0; i < N; i++)
        {
            string[] tmp = sr.ReadLine().Split(' ');
            int P = int.Parse(tmp[0]);
            int K = int.Parse(tmp[1]);
            int L = int.Parse(tmp[2]);
            tmp = sr.ReadLine().Split(' ');
            int[] freq = new int[L];
            for (int j = 0; j < L; j++)
            {
                freq[j] = int.Parse(tmp[j]);
            }

            long Y = work(P,K,L,freq);

            sw.WriteLine("Case #{0}: {1}", i + 1, Y);
        }
        sw.Close();
    }

    private static long work(int P, int K, int L, int[] freq)
    {
        checked
        {
            int j = 0;
            long res = 0;
            int[] letter = new int[L];
            for (int i = 0; i < L; i++)
            {
                letter[i] = 0;
            }
            Array.Sort(freq, letter);

            int[] placed = new int[K];
            for (int i = L - 1; ; i--)
            {
                placed[j]++;
                res += (long)freq[i] * placed[j];
                if (i == 0)
                    break;
                do
                {
                    j = (j + 1) % K;
                } while (placed[j] == P);
            }
            return res;
        }
    }
}