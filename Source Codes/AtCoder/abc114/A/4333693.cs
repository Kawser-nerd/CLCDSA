using System;

namespace AtCoder.ABC114
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            string output;

            switch (n)
            {
                case 7:
                    output = "YES";
                    break;
                case 5:
                    output = "YES";
                    break;
                case 3:
                    output = "YES";
                    break;
                default:
                    output = "NO";
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
            ABC114.A.Solve();
        }
    }
}