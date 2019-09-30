using System;

namespace CSharp_Study
{
    class Program
    {
        static void Main(string[] args)
        {


            int n = int.Parse(Console.ReadLine());
            string[] line = Console.ReadLine().Split(' ');
            int[] nums = Array.ConvertAll(line, int.Parse);

            int m = int.Parse(Console.ReadLine());
            int sum;
            for (int i = 0; i < m; i++)
            {
                sum = 0;
                line = Console.ReadLine().Split(' ');
                int a = int.Parse(line[0]);
                int b = int.Parse(line[1]);

                for (int j = 0; j < n; j++)
                {
                    if (j == a - 1) sum += b;
                    else sum += nums[j];
                }
                Console.WriteLine(sum + "\n");
            }
        }
    }
}