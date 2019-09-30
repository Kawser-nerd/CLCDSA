using static System.Console;

namespace C_
{
	class Program
	{
		static void Main(string[] args)
		{
			float m = int.Parse(ReadLine());
			float km = m / 1000;

			if (km < 0.1) // case 1
			{
				WriteLine("00");
			}
			else if (km >= 0.1 && km <= 5) // case 2
			{
				float c2 = km * 10;
				WriteLine(c2.ToString("00"));
			}
			else if (km >= 6 && km <= 30) // case 3
			{
				WriteLine(km + 50);
			}
			else if (km >= 35 && km <= 70) // case 4
			{
				float c4 = (km - 30) / 5 + 80;
				WriteLine(c4);
			}
			else if (km > 70) // case 5
			{
				WriteLine(89);
			}
		}
	}
}