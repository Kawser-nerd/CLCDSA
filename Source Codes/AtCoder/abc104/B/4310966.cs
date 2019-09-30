using System;
using System.Linq;

namespace B.AcCepted
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();
            bool flg1, flg2, flg3;

            flg1 = str[0] == 'A';
            flg2 = str.Skip(2).Take(str.Length - 3).Contains('C');
            flg3 = str.Count(x => char.IsUpper(x)) == 2;
            
            if (flg1 && flg2 && flg3)
                Console.WriteLine("AC");
            else
                Console.WriteLine("WA");
        }
    }
}