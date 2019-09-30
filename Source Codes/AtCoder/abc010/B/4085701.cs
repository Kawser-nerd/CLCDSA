using System;
using System.Collections.Generic;
using System.Linq;
 
namespace at
{
    class Program
    {
        static void Main(string[] args)
        {
            var anw = 0;
            var n = int.Parse(Console.ReadLine());
            var a = Console.ReadLine().Split(' ');
            foreach (var item in a)
            {
                int x = int.Parse(item);
                
                switch (x)
                {
                    case 1: //0
                    case 3: //0
                    case 7: //0
                    case 9: //0
                        break;

                    case 2: //1
                    case 4: //1
                    case 8: //1
                        anw = anw + 1;
                        break;

                    case 5: //2
                        anw = anw + 2;
                        break;

                    default:
                        anw = anw + 3;
                        break;
                }
                
            }
            Console.WriteLine(anw);
        }
        
    }
}