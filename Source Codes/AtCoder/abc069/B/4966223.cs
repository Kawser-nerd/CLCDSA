using System;

namespace B___i18n
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();
            
            Console.WriteLine(s[0] + (s.Length - 2).ToString() + s[s.Length - 1]);
        }
    }
}