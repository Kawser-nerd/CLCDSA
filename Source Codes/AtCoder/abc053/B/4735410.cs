using System;

    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine();
            var length = S.Substring(S.IndexOf('A'), S.LastIndexOf('Z')- S.IndexOf('A')+1).Length;
            Console.WriteLine(length);
        }
    }