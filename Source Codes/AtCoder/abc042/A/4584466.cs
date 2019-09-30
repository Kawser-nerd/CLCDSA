using System;
class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');

            int countFive = 0;
            int countSeven = 0;

            foreach(string valStr in input)
            {
                int val = int.Parse(valStr);
                if(val == 5)
                {
                    countFive++;
                }else if(val == 7)
                {
                    countSeven++;
                }
            }

            if(countFive == 2 & countSeven == 1)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }
    }