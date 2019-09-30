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
            string[] b = Console.ReadLine().Split(' ');
            string[] c = Console.ReadLine().Split(' ');
            int ans = 0;
            ans += int.Parse(a[0]) / 10 * int.Parse(a[1]);
            ans += int.Parse(b[0]) / 10 * int.Parse(b[1]);
            ans += int.Parse(c[0]) / 10 * int.Parse(c[1]);
            Console.WriteLine(ans);
            return;
        }
    }
}