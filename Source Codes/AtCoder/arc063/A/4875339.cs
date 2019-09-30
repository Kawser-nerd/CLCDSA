using System;
    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine();
            var count = 0;
            for(var i =1;i<S.Length;i++)
            {
                if (S[i - 1] != S[i]) count++;
            }
            Console.WriteLine(count);
        }
    }