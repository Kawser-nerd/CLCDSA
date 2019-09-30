using System;
using System.Globalization;

public class starwars
{
    public const double Precision = 1E-6;

    public static void Main(string[] args)
    {
        long start = DateTime.Now.Ticks;
        int T = int.Parse(Console.ReadLine());

        for (int cs = 1; cs <= T; cs++)
        {
            int N = int.Parse(Console.ReadLine());
            double[] x = new double[N];
            double[] y = new double[N];
            double[] z = new double[N];
            double[] p = new double[N];
            for (int i = 0; i < N; i++)
            {
                string[] parts = Console.ReadLine().Split();
                x[i] = int.Parse(parts[0]);
                y[i] = int.Parse(parts[1]);
                z[i] = int.Parse(parts[2]);
                p[i] = int.Parse(parts[3]);
            }
            Console.WriteLine("Case #" + cs + ": " + search(x, y, z, p).ToString("0.000000", CultureInfo.InvariantCulture));
        }
        Console.Error.WriteLine("Time: " + (DateTime.Now.Ticks - start) / TimeSpan.TicksPerMillisecond + " ms");
    }

    static double search(double[] x, double[] y, double[] z, double[] p, double myy, double myz)
    {
        double low = 0;
        double up = 1000000;
        double ret = -1;
        while (up - low > Precision)
        {
            double left = (low + low + up) / 3d;
            double right = (low + up + up) / 3d;
            double leftval = val(x, y, z, p, left, myy, myz);
            double rightval = val(x, y, z, p, right, myy, myz);
            if (leftval <= rightval)
            {
                ret = leftval;
                up = right;
            }
            else
            {
                ret = rightval;
                low = left;
            }
        }
        return ret;
    }
    static double search(double[] x, double[] y, double[] z, double[] p, double myz)
    {
        double low = 0;
        double up = 1000000;
        double ret = -1;
        while (up - low > Precision)
        {
            double left = (low + low + up) / 3d;
            double right = (low + up + up) / 3d;
            double leftval = search(x, y, z, p, left, myz);
            double rightval = search(x, y, z, p, right, myz);
            if (leftval <= rightval)
            {
                up = right;
                ret = leftval;
            }
            else
            {
                ret = rightval;
                low = left;
            }
        }
        return ret;
    }

    static double search(double[] x, double[] y, double[] z, double[] p)
    {
        double low = 0;
        double up = 1000000;
        double ret = -1;
        while (up - low > Precision)
        {
            double left = (low + low + up) / 3d;
            double right = (low + up + up) / 3d;
            double leftval = search(x, y, z, p, left);
            double rightval = search(x, y, z, p, right);
            if (leftval <= rightval)
            {
                up = right;
                ret = leftval;
            }
            else
            {
                ret = rightval;
                low = left;
            }
        }
        return ret;
    }

    static double val(double[] x, double[] y, double[] z, double[] p, double myx, double myy, double myz)
    {
        double max = 0;
        for (int i = 0; i < x.Length; i++)
            max = Math.Max((Math.Abs(x[i] - myx) + Math.Abs(y[i] - myy) + Math.Abs(z[i] - myz)) / p[i], max);
        return max;
    }
}