using System;
using System.Globalization;

namespace ABC011B
{
    class Program
    {
        static void Main(string[] args)
        {
            string S = Console.ReadLine();
            TextInfo ti = CultureInfo.CurrentCulture.TextInfo;
            Console.WriteLine(ti.ToTitleCase(S));
        }
    }
}