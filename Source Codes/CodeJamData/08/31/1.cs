using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
namespace Text_Message_Outrage
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("D:\\in.txt");
            StreamWriter sw = new StreamWriter("D:\\out.txt");
            int vv = int.Parse(sr.ReadLine());
            for (int w = 0; w < vv; )
            {
                w++;

                string[] g = sr.ReadLine().Split(' ');
                int P = int.Parse(g[0]);
                int K = int.Parse(g[1]);
                int L = int.Parse(g[2]);
                g = sr.ReadLine().Split(' ');
                int[] F = new int[L];
                for (int i = 0; i < L; i++)
                {
                    F[i] = int.Parse(g[i]);
                }
                Array.Sort(F);
                Array.Reverse(F);
                int h = 0;
                int n = 1;
                long r = 0;
                for (int i = 0; i < L; i++)
                {
                    r += n * F[i];
                    h++;
                    if (h == K)
                    {
                        h = 0;
                        n++;
                    }
                }


                string outs = "Case #" + w.ToString() + ": ";
                sw.WriteLine(outs + r.ToString());
            }
            sr.Close();
            sw.Close();
        }
    }
}
