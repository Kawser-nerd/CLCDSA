using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
    {
        static void Main(string[] args)
        {
            var line = Console.ReadLine();

            switch (line)
            {
                case "A":
                    Console.WriteLine("T");
                    break;

                case "C":
                    Console.WriteLine("G");
                    break;

                case "G":
                    Console.WriteLine("C");
                    break;

                case "T":
                    Console.WriteLine("A");
                    break;

                default:
                    break;
            }

        }
    }