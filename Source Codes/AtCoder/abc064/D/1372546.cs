using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ProCon
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(Console.ReadLine());
            string input = Console.ReadLine();
            int leftStock = 0;
            int tooManyRight = 0;
            for(int i = 0; i < num; ++i)
            {
                if(input[i] == '(')
                {
                    leftStock++;
                }
                else
                {
                    if(leftStock > 0)
                    {
                        leftStock--;
                    }
                    else
                    {
                        tooManyRight++;
                    }
                }
            }
            string result = "";
            for(int i = 0; i < tooManyRight; ++i)
            {
                result += "(";
            }
            result += input;
            for (int i = 0; i < leftStock; ++i)
            {
                result += ")";
            }
            Console.WriteLine(result);
        }
    }
}