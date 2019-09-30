using System;

namespace AtCoder.ABC115
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);

            string output;
            switch (a)
            {
                case 25:
                    output = "Christmas";
                    break;
                case 24:
                    output = "Christmas Eve";
                    break;
                case 23:
                    output = "Christmas Eve Eve";    
                    break;
                case 22:
                    output = "Christmas Eve Eve Eve";
                    break;
                default:
                    output = "";
                    break;
            }
            
            Console.WriteLine(output);
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC115.A.Solve();
        }
    }
}