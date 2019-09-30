using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJApp
{
    class Program
    {
        

        static void Main(string[] args)
        {
            TextWriter tw = new StreamWriter("C:\\myStuff\\GCJ\\Data\\A-large.out");

            TextReader tr = new StreamReader("C:\\myStuff\\GCJ\\Data\\A-large.in");

            int N = Int32.Parse(tr.ReadLine());

            int P,K,L;

            int[] freq;

            long[,] dp;

            for (int i = 1; i <= N; i++)
            {

                string[] tar = tr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                P = int.Parse(tar[0]);
                K = int.Parse(tar[1]);
                L = int.Parse(tar[2]);

                tar = tr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                freq = new int[L];
               // dp = new long[K,L];
                for (int j = 0; j < L; j++)
                {
                    freq[j] = int.Parse(tar[j]);
                    
                }

                Array.Sort(freq);
                Array.Reverse(freq);
                long ret=0L;
                for (int j = 0; j < freq.Length; j++)
                {
                    ret += ((long)((j / K) + 1)) * freq[j];
                }

                
                
                tw.WriteLine("Case #" + (i) + ": " + ret);
                //tw.WriteLine("Case #" + (i) + ": " + r2);
            }
            tw.Flush();
            tw.Close();

        }


    }
}
