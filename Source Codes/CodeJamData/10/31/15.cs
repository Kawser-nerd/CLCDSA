using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Code2010a
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> mego = new List<string>();

            StreamReader sr1 = new StreamReader("a.txt");
            int T = int.Parse(sr1.ReadLine());
            string line;
            while ((line = sr1.ReadLine()) != null)
            {
                int N = int.Parse(line);
                int[] x = new int[N];
                int[] y = new int[N];
                for (int i = 0; i < N; i++)
                {
                    line=sr1.ReadLine();
                    string[] spl = line.Split(' ');
                    x[i] = int.Parse(spl[0]);
                    y[i] = int.Parse(spl[1]);
                }
                
                //solve
                int ans = 0;
                for (int i = 0; i < x.Length; i++)
                {
                    for (int j = 0; j < x.Length; j++)
                    {
                        if (i == j) { continue; }
                        if (x[i] < x[j] && y[i] > y[j])
                        {
                            //felfele meredekebb keresztez
                            ans++;
                        }
                        else if (x[i] > x[j] && y[i] < y[j])
                        {
                            //laposabb felfele
                            ans++;
                        }
                    }
                }


                mego.Add((ans / 2).ToString());


                // /solve
            }
            sr1.Close();







            StreamWriter sr2 = new StreamWriter("m.txt");
            for (int i = 0; i < mego.Count; i++)
            {
                sr2.WriteLine("Case #" + (i + 1).ToString() + ": " + mego[i]);
            }
            sr2.Close();
        }
    }
}
