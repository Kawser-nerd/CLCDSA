using System;
using System.Linq;

namespace arc051_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] b = Console.ReadLine().Split().Select(int.Parse).ToArray();
            bool red = true;
            if (b[0] <= a[0] - a[2] && a[0] + a[2] <= b[2])
            {
                if (b[1] <= a[1] - a[2] && a[1] + a[2] <= b[3])
                {
                    red = false;
                }
            }
            bool blue = true;
            double left = Math.Pow(b[0] - a[0],2);
            double down = Math.Pow(b[1] - a[1],2);
            double right = Math.Pow(b[2] - a[0],2);
            double up = Math.Pow(b[3] - a[1],2);
            double leftdown = Math.Sqrt(left + down);
            double leftup = Math.Sqrt(left + up);
            double rightup = Math.Sqrt(right + up);
            double rightdown = Math.Sqrt(right + down);
            if (Math.Max(Math.Max(leftdown,leftup),Math.Max(rightdown,rightup)) <= a[2]) blue = false;
            Console.WriteLine(red ? "YES" : "NO");
            Console.WriteLine(blue ? "YES" : "NO");
        }
    }
}