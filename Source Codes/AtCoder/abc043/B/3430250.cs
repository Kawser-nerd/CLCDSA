using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace procon
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string result = "";

            for(int i = 0; i < input.Length; i++)
            {
                string target = input.Substring(i, 1);
                if(target == "B")
                {
                    if(result != "")
                    {
                        result = result.Substring(0, result.Length - 1);
                    }
                }
                else
                {
                    result = result + target;
                }
            }

            Console.WriteLine(result);
        }
    }
}