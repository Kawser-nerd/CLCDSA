using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1???
            string input = Console.ReadLine();

            // ???+???????
            int count = 0;
            for(int i = 0; i < input.Length; i++)
            {
                if(input[i] == '+')
                {
                    count++;
                }
            }

            // ???+?????
            string[] spl = input.Split('+');

            // ???0???????????? ????
            int output = 0;
            for(int i = 0; i < count+1; i++)
            {
                if (!spl[i].Contains("0"))
                {
                    output++;
                }
            }

            // ???????
            Console.WriteLine(output);
        }
    }
}