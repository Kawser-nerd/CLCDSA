using System;
using System.Collections;
using System.IO;
public class GG
{  
    public void processing()
    {
        StreamReader SR;
        StreamWriter SW;
        SR = File.OpenText("B-large.in");
        SW = File.CreateText("B.out");

        int NN = int.Parse(SR.ReadLine());

        for (int cc = 1; cc <= NN; cc++)
        {
           
            int n = int.Parse(SR.ReadLine());
           double[] a = new double[6];
            for (int i = 0; i < n; i++)
            {
                string[] ss = SR.ReadLine().Split();
                for (int j = 0; j < 6; j++)
                {
                    a[j] += int.Parse(ss[j]);
                }
            }
            for (int i = 0; i < 6; i++)
            {
                a[i] /= (double)n;
            }
            double A = a[3] * a[3] + a[4] * a[4] + a[5] * a[5];
            double B = 2.0 * (a[0] * a[3] + a[1] * a[4] + a[2] * a[5]);
            double C = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
            if (A == 0.0)
            {
               
                double res = Math.Sqrt(C);
                SW.WriteLine("Case #" + cc + ": " + res + " " + 0);
                Console.WriteLine("Case #" + cc + ": " + res + " " + 0);

            }
            else
            {
                double m = -B / (2.0 * A);
                double res = 0.0;
                if (m >= 0)
                {
                    res = C - B * B / (4 * A);
                }
                else
                {
                    m = 0.0;
                    res = C;
                }
                if (res < 0.0)
                    res = 0.0;
                res = Math.Sqrt(res);


                SW.WriteLine("Case #" + cc + ": " + res + " " + m);
                Console.WriteLine("Case #" + cc + ": " + res + " " + m);
            }
        }
        SR.Close();
        SW.Close();
    }
    public static void Main()
    {
        GG g = new GG();
        g.processing();
    }
}