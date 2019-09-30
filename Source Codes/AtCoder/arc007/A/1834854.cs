using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ForRecords
{
    class Program
    {
        static void Main(string[] args)
        {
            Practice practice = new Practice();
            Console.WriteLine(practice.GetResult());
        }
        
    }

    class Practice
    {
        private string broken;
        private string input;
        private string result;
        public Practice()
        {
            broken = Console.ReadLine();
            input = Console.ReadLine();
            result = "";
        }

        public string GetResult()
        {
            for(int i =0; i < input.Length; i++)
            {
                if(input[i] != broken[0])
                {
                    result += input[i];
                }
            }
            return result;
        }

    }
}