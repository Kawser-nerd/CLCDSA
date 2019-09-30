using System;
using System.Collections.Generic;

namespace ABC091_A_Two_Colors_Card_Game
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			List<string> sList = new List<string>();
			for (int i = 0; i < n; i++) {
				sList.Add(Console.ReadLine());
			}

			int m = int.Parse(Console.ReadLine());
			List<string> tList = new List<string>();
			for (int i = 0; i < m; i++) {
				tList.Add(Console.ReadLine());
			}

			int money = 0;

			for (int i = 0; i < n; i++)
			{
				int moneyValue = 0;
				for (int j = 0; j < n; j++) {
					if (sList[i] == sList[j])
					{
						moneyValue++;
					}
				}

				for (int j = 0; j < m; j++) {
					if(sList[i] == tList[j])
					{
						moneyValue--;
					}
				}

				if (moneyValue > money)
				{
					money = moneyValue;
				}
			}
			
			Console.WriteLine(money);
		}
	}
}