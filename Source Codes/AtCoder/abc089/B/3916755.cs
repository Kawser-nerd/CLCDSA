using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{


    class Program
    {
        
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] str = Console.ReadLine().Split(' ');

            bool[] iro =new bool[4];
            for(int i = 0; i < n; i++)
            {
                if (str[i] == "P") iro[0] = true;
                else if (str[i] == "W") iro[1] = true;
                else if (str[i] == "G") iro[2] = true;
                else iro[3] = true;
            }

            int cnt = 0;
            for(int i = 0; i < iro.Length; i++)
            {
                if (iro[i]) cnt++;
            }

            if (cnt == 3) Console.WriteLine("Three");
            else if (cnt == 4) Console.WriteLine("Four");
        }
    }
}