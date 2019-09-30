using System;
namespace WpfApp1
{
    class program
    {
        static int Max(int a,int b)
        {
            if (a <= b) return b;
            else return a;
        }
        static void Main(string[] args)
        {
            string[] a = Console.ReadLine().Split(' ');
            int n = int.Parse(a[0]);
            int m = int.Parse(a[1]);
            Console.WriteLine(m + " " + n);
        }
    }
}