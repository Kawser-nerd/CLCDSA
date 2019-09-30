using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC103_A_Task_Scheduling_Problem
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] aArr = Console.ReadLine().Split(' ');
			List<int> aArrInt = new List<int>();

			for (int i = 0; i < aArr.Length; i++)
			{
				aArrInt.Add(int.Parse(aArr[i]));
			}

			aArrInt.Sort();
			aArrInt.Reverse();
			int result = 0;

			for (int i = 0; i < aArrInt.Count() - 1; i++)
			{
				result += aArrInt[i] - aArrInt[i + 1];
			}
			
			Console.WriteLine(result);
		}
	}
}