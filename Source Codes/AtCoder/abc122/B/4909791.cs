using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();
            string[] word = new string[] { "A", "C", "T", "G" };
            int length = 0;


            for (int i = 0; i < s.Length; i++)
            {
                int wordlength = 0;

                if (word.Any(s[i].ToString().Contains))
                {
                    wordlength++;

                    for (int j = i+1; j < s.Length; j++)
                    {
                        if (word.Any(s[j].ToString().Contains))
                        {
                            wordlength++;
                        }
                        else
                        {
                            break;
                        }
                    }

                }

                if (wordlength > length)
                {
                    length = wordlength;
                }
            }

            Console.WriteLine(length);
           

        }
    }
}