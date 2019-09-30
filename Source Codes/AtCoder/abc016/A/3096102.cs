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
            int m = int.Parse(a[0]);
            int d = int.Parse(a[1]);
            if (m % d == 0) Console.WriteLine("YES");
            else Console.WriteLine("NO");
            return;
        }
    }
}