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
                string[] spl = line.Split(' ');
                double L = double.Parse(spl[0]);
                double P = double.Parse(spl[1]);
                double C = double.Parse(spl[2]);
                int ans = 0;

                //solve

                while (P / L > C)
                {
                    double X = Math.Sqrt(P * L);
                    double difA = X / L;
                    double difB = P / X;
                    if (difA > difB)
                    {
                        P = X;
                    }
                    else
                    {
                        L = X;
                    }
                    ans++;
                }
                // /solve



                mego.Add(ans.ToString());

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
