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
            int n = int.Parse(Console.ReadLine());
            int m = (n + 1) % 12;
            if (m == 0) m = 12;
            Console.WriteLine(m);
            Console.ReadLine();
        }
    }
}