using System;
using System.Collections.Generic;
using System.Text;

namespace atcoder_ARC061C
{
    class MainClass
    {
		static char[] numbers = new char[20];
		static int[] plusArray = new int[20];
		static long sum = 0;
		static List<int[]> AllplusList = new List<int[]>();
		//static bool[] plusArray = new bool[20];
        public static void Main(string[] args)
        {
			numbers = Console.ReadLine().ToCharArray();
			for (int i = 0; i < numbers.Length - 1; i++)
			{
				plusArray[i] = 0;
			}
			Adder(0);

			Console.WriteLine(sum);
		}
        
		private static void Adder(int currentIndex)
		{
			if (currentIndex >= numbers.Length - 1)
			{
				StringBuilder numberString = new StringBuilder();
				for (int i = 0; i < numbers.Length; i++)
				{
					numberString.Append(numbers[i]);
					if (plusArray[i] == 1 || i == numbers.Length - 1)
					{
						sum += long.Parse(numberString.ToString());
						numberString.Clear();
					}
				}

				return;
			}

			Adder(currentIndex + 1);
			plusArray[currentIndex] = 1;
			Adder(currentIndex + 1);
			plusArray[currentIndex] = 0;

			return;
		}
    }
}