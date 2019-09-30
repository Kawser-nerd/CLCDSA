using System;
using System.Collections;
using System.Collections.Specialized;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJ
{
    class Program
    {

        static int K, ret;
        static string s;

        static void Main(string[] args)
        {
            TextWriter tw = new StreamWriter("C:\\GCJ\\Data\\D-small.out");
            TextReader tr = new StreamReader("C:\\GCJ\\Data\\D-small-attempt0.in");

            int N = int.Parse(tr.ReadLine());

            for (int i = 1; i <= N; i++)
            {
                
                K = int.Parse(tr.ReadLine());
                s = tr.ReadLine();

                int[] par = new int[K];
                ret = int.MaxValue;
                for (int j = 0; j < par.Length; j++)
                    par[j] = j;

                perm(par, 0);

                tw.WriteLine("Case #" + i + ": " + ret);
            }
            tw.Flush();
            tw.Close();
        }

        static void perm(int[] ar, int index)
        {
            if (index == ar.Length - 1)
            {
                string ps = "";
                for (int ii = 0; ii < ar.Length; ii++)
                    ps = ps + " , " + ar[ii];
                Console.WriteLine("  perm - " + ps);
                string t="";
                int it;
                for (int i = 0; i < s.Length; i++)
                {
                    it = i / K;
                    t = t + s[it * K + ar[i % K]];
                }
                int cnt = 1;
                for (int j = 1; j < t.Length; j++)
                    if (!t[j].Equals(t[j - 1]))
                        cnt++;
                if (ret > cnt)
                    ret = cnt;
                return;
            }
            for (int i = index; i < ar.Length; i++)
            {
                int t = ar[index];
                ar[index] = ar[i];
                ar[i] = t;

                perm(ar, index +1);

                t = ar[index];
                ar[index] = ar[i];
                ar[i] = t;

            }
            return;
        }


    }
}