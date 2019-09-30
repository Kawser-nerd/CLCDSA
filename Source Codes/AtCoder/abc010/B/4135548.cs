using System;
using System.Linq;

namespace Beginner010B
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            Console.WriteLine(Console.ReadLine()
                                     .Split(' ')
                                     .Select(petalCount =>
                                     {
                                         switch (int.Parse(petalCount))
                                         {
                                             case 9:
                                             case 7:
                                             case 3:
                                             case 1:
                                                 return 0;
                                             case 8:
                                             case 4:
                                             case 2:
                                                 return 1;
                                             case 6:
                                                 return 3;
                                             case 5:
                                                 return 2;
                                             default:
                                                 throw new ArgumentException();
                                         }
                                     })
                                     .Sum());
        }
    }
}