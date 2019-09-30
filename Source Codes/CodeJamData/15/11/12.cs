using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace R1_A
{
    class Program
    {

        static void Main(string[] args)
        {
            string fin = "A-large.in"; 
                //"A-small-attempt0.in";
                //"input.txt";
            string fout = "A.out";
            StreamReader sr = new StreamReader(fin);
            StreamWriter sw = new StreamWriter(fout);
            int T = Int32.Parse(sr.ReadLine());
            
            for (int i = 1; i <= T; i++)
            {
                int[] a = new int[10000];
                int n = Int32.Parse(sr.ReadLine());
                string[] txt = sr.ReadLine().Split(' ');
                for (int j = 0; j < n; j++)
                {
                    a[j] = Int32.Parse(txt[j]);
                }

                int a1 = 0; 
                int a2 = 0;
                int gap = 0;
                for (int j = 1; j < n; j++)
                {
                    if (a[j] < a[j - 1]) a1 += (a[j - 1] - a[j]);
                    if (a[j - 1] - a[j] > gap) gap = a[j - 1] - a[j];
                }
                for (int j = 0; j < n - 1; j++)
                    if (a[j] > gap) a2 += gap;
                    else a2 += a[j];
                sw.WriteLine(string.Format("Case #{0}: {1} {2}", i, a1, a2));
            }
            sr.Close();
            sw.Close();
        }
    }
}
