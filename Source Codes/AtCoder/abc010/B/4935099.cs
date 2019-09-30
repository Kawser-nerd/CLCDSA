using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp111 {
    class Program {
        static void Main(string[] args)
        {
            int inputNum = int.Parse(Console.ReadLine());
            string flower = Console.ReadLine();

            string[] flowerStr = flower.Split(' ');
            int[] flowerInt = new int[inputNum];

            int i = 0;
            foreach(string str in flowerStr)
            {
                flowerInt[i] = int.Parse(str);
                i += 1;
            }

            int sum = 0;

            foreach (var num in flowerInt)
            {
                int flowerNum = num;
                for (int j = 0; j < num; j++)
                {
                    if (flowerNum % 2 == 0)
                    {
                        sum += 1;
                        flowerNum -= 1;
                    }
                    else if (flowerNum % 3 == 2)
                    {
                        sum += 1;
                        flowerNum -= 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            Console.WriteLine(sum);
        }
    }
}