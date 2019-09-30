using System;

    class Program
    {
        static void Main(string[] args)
        {
            var O = Console.ReadLine();
            var E = Console.ReadLine();

            var pass = string.Empty;
            for(var i = 0;i<O.Length;i++)
            {
                pass += O[i];
                if(i<E.Length) pass += E[i];
            }
            Console.WriteLine(pass);
        }
    }