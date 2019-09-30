using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;


class Program
{ 

    public void Slove()
    {
        var inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Func<double, double> dis = t => 
            t * inputs[0] + inputs[1] * Math.Sin(Math.PI * inputs[2] * t);
        double start = 0;
        double end = 100 * inputs[0] + inputs[1] + 1;
        while(true)
        {
            double mid = (start + end) / 2;
            double d = dis(mid);
            if(100 - d > 0.0000001)
                start = mid;
            else if(100 - d < -0.0000001)
                end = mid;
            else
            {
                Console.WriteLine(mid);
                break;
            }
        }
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}