using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A.AtCoder_Beginner_Contest_999
{
    class Program
    {
        static void Main(string[] args)
        {
            var num = Console.ReadLine().ToCharArray();

            for (int i = 0; i < num.Length; i++)
            {
                switch (num[i])
                {
                    case '1':
                        num[i] = '9';
                        break;
                    case '9':
                        num[i] = '1';
                        break;
                    default:
                        break;
                }
            }

            Console.Write(new string(num));
        }
    }
}