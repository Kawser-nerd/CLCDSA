using System;
namespace AtCoder
{
    class Program
    {
        public static void Main()
        {
            string[] Input = Console.ReadLine().Split(' ');
            int Month = int.Parse(Input[0]);
            int Day = int.Parse(Input[1]);

            if(Month % Day == 0)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }
    }
}