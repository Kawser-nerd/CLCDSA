using System;
namespace HelloCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] vs = Console.ReadLine().Split();
            var xa = double.Parse(vs[0]);
            var ya = double.Parse(vs[1]);
            var xb = double.Parse(vs[2]);
            var yb = double.Parse(vs[3]);
            var xc = double.Parse(vs[4]);
            var yc = double.Parse(vs[5]);
            
            double area =Math.Abs( ((xa-xc)*(yb-yc)-(xb-xc)*(ya-yc))/2);
            Console.WriteLine("{0:0.0}",area);
            //Console.ReadLine();

        }
    }
}