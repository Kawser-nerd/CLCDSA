using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Jam
{
    class Program
    {
        string run(double[] a, double[] b)
        {
            int len = b.Length;
            bool[] used = new bool[b.Length];

            int opt = 0;
            for (int n = 0; n < len; n++)
            {
                for(int m=0; m<len; m++)
                    if (!used[m] && b[m] > a[n])
                    {
                        used[m] = true;
                        opt++;
                        break;
                    }
            }

            HashSet<double> naomi = new HashSet<double>(a);
            HashSet<double> ken = new HashSet<double>(b);
            int dec = 0;


            while (naomi.Count > 0)
            {
                double kmin = ken.Min();
                double nmin = naomi.Min();
                double kmax = ken.Max();

                if (kmin < nmin)
                {
                    ken.Remove(kmin);
                    naomi.Remove(nmin);
                    dec++;
                }
                else
                {
                    ken.Remove(kmax);
                    naomi.Remove(nmin);
                }
            }

            return dec.ToString() + " " + (len - opt).ToString();
        }
        static void Main(string[] args)
        {
            using (StreamReader f = new StreamReader("D-large.in"))
            {
                using (StreamWriter sw = new StreamWriter("D-large.out"))
                {
                    int cases = Int32.Parse(f.ReadLine());
                    for(int z=0; z<cases; z++){
                        int len = Int32.Parse(f.ReadLine());
                        string tmp = f.ReadLine();
                        string[] a = tmp.Split(' ');
                    string[] b = f.ReadLine().Split(' ');
                    
                    double[] p1 = new double[len];
                    double[] p2 = new double[len];
                    for(int n=0; n<len; n++){
                        p1[n]=double.Parse(a[n]);
                        p2[n]=double.Parse(b[n]);
                    }
                    Array.Sort(p1);
                    Array.Sort(p2);
                        Program p = new Program();
                        string output = p.run(p1, p2);

                        sw.WriteLine("Case #" + (z + 1).ToString() + ": " + output);
                    }
                    
                }
            }

        }
    }
}
