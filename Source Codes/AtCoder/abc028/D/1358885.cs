using System;
 

    class Program
    {
        static void Main()
        {
            string[] a = Console.ReadLine().Split(' ');
            double n = int.Parse(a[0]);
            double k = int.Parse(a[1]);
            Console.WriteLine(((n - k) * (k - 1) * 6 + (n - 1) * 3 + 1) / (n * n * n));
        }
    }