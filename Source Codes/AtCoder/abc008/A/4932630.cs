using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp111 {
    class Program {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string[] inputNum = input.Split(' ');
            int[] inputIntNum = stringToInt(inputNum);

            

            int sum = 0;
            for(int i = inputIntNum[0]; i <= inputIntNum[1]; i++)
            {
                sum += 1;
            }
            Console.WriteLine(sum);
        }

        static int[] stringToInt(string[] inputNum)
        {
            int i = 0;
            int[] inputIntNum = new int[2];
            foreach(var s in inputNum)
            {
                inputIntNum[i] = int.Parse(s);
                i += 1;
            }
            return inputIntNum;
        }
    }
}