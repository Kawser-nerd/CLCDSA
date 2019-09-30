using System;
using System.Linq;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] numbers = Console.ReadLine().Split(new Char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(item => int.Parse(item)).ToArray();
            int now_temp = numbers[0];
            int target_temp = numbers[1];

            int diff_temp = target_temp - now_temp;
            int push_count = 0;

            while (diff_temp != 0)
            {
                int take10_result;
                int take5_result;
                int take1_result;
                
                take10_result = diff_temp + 10;
                if (Math.Abs(take10_result) > Math.Abs(diff_temp - 10))
                {
                    take10_result = diff_temp - 10;
                }

                take5_result = diff_temp + 5;
                if (Math.Abs(take5_result) > Math.Abs(diff_temp - 5))
                {
                    take5_result = diff_temp - 5;
                }

                take1_result = diff_temp + 1;
                if (Math.Abs(take1_result) > Math.Abs(diff_temp - 1))
                {
                    take1_result = diff_temp - 1;
                }


                if (Math.Abs(take10_result) < Math.Abs(take5_result))
                {
                    if (Math.Abs(take10_result) < Math.Abs(take1_result))
                    {
                        diff_temp = take10_result;
                    }
                }
                else if (Math.Abs(take5_result) < Math.Abs(take1_result))
                {
                    diff_temp = take5_result;
                }
                else
                {
                    diff_temp = take1_result;
                }


                push_count += 1;
            }


            Console.WriteLine(push_count);

        }
    }
}