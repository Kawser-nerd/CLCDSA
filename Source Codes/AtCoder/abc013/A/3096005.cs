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
            char a = char.Parse(Console.ReadLine());
            Console.WriteLine(a - 'A' + 1);
        }
    }
}