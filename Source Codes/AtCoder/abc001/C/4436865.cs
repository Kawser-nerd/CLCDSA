using System;
using static System.Console;

namespace C_
{
	class Program
	{
		static string GetDirection(float deg)
		{
			string dir = "";
			deg /= 10;

			if (11.25 <= deg && deg < 33.75)
				dir = "NNE";
			else if (33.75 <= deg && deg < 56.25)
				dir = "NE";
			else if (56.25 <= deg && deg < 78.75)
				dir = "ENE";
			else if (78.75 <= deg && deg < 101.25)
				dir = "E";
			else if (101.25 <= deg && deg < 123.75)
				dir = "ESE";
			else if (123.75 <= deg && deg < 146.25)
				dir = "SE";
			else if (146.25 <= deg && deg < 168.75)
				dir = "SSE";
			else if (168.75 <= deg && deg < 191.25)
				dir = "S";
			else if (191.25 <= deg && deg < 213.75)
				dir = "SSW";
			else if (213.75 <= deg && deg < 236.25)
				dir = "SW";
			else if (236.25 <= deg && deg < 258.75)
				dir = "WSW";
			else if (258.75 <= deg && deg < 281.25)
				dir = "W";
			else if (281.25 <= deg && deg < 303.75)
				dir = "WNW";
			else if (303.75 <= deg && deg < 326.25)
				dir = "NW";
			else if (326.25 <= deg && deg < 348.75)
				dir = "NNW";
			else
				dir = "N";

			return dir;
		}

		static int GetWindForce(float dis)
		{
			int wf = 0;
			const MidpointRounding away = MidpointRounding.AwayFromZero;
			double mps = Math.Round(dis / 60, 1, away);

			if (0.0 <= mps && mps <= 0.2)
				wf = 0;
			else if (0.3 <= mps && mps <= 1.5)
				wf = 1;
			else if (1.6 <= mps && mps <= 3.3)
				wf = 2;
			else if (3.4 <= mps && mps <= 5.4)
				wf = 3;
			else if (5.5 <= mps && mps <= 7.9)
				wf = 4;
			else if (8.0 <= mps && mps <= 10.7)
				wf = 5;
			else if (10.8 <= mps && mps <= 13.8)
				wf = 6;
			else if (13.9 <= mps && mps <= 17.1)
				wf = 7;
			else if (17.2 <= mps && mps <= 20.7)
				wf = 8;
			else if (20.8 <= mps && mps <= 24.4)
				wf = 9;
			else if (24.5 <= mps && mps <= 28.4)
				wf = 10;
			else if (28.5 <= mps && mps <= 32.6)
				wf = 11;
			else if (32.7 <= mps)
				wf = 12;

			return wf;
		}

		static void Main(string[] args)
		{
			string[] input = ReadLine().Split(' ');
			float deg = float.Parse(input[0]); // ??
			float dis = float.Parse(input[1]); // ??

			string dir = GetDirection(deg);
			int    wf  = GetWindForce(dis);

			if (wf == 0)
				dir = "C";

			WriteLine(dir + " " + wf);

			ReadKey();
		}
	}
}