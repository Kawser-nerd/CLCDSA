using System.Collections.Generic;

using System.Linq;
using System;

namespace Application
{
	class Solution
	{
		static void Main(string[] args)
		{
			var inputWords = Console.ReadLine().Split(' ');

			var inputDegree = decimal.Parse(inputWords[0]) / 10m;
			var inputWindMeter = decimal.Parse(inputWords[1]);

			string result = "";
			var outputWindPower = GetWindPower(inputWindMeter);
			// ???0????????
			if (outputWindPower == 0)
			{
				result = $"C {outputWindPower}";
			}else
			{
				result = $"{GetWindDirection(inputDegree)} {outputWindPower}";
			}

			Console.WriteLine(result);
		}

		static string GetWindDirection(decimal windDegree)
		{
			var unitDegree = 360 / 16.0m;

			// N? -11.25°?11.25°???-11.25°?360+11.25°???????????
			var startDegree = unitDegree * (-0.5m);

			var directionList = new List<string>()
			{
				"N",
				"NNE",
				"NE",
				"ENE",
				"E",
				"ESE",
				"SE",
				"SSE",
				"S",
				"SSW",
				"SW",
				"WSW",
				"W",
				"WNW",
				"NW",
				"NNW",
				"N"
			};

			for (var i = 0; i < directionList.Count; i++)
			{
				if (windDegree < startDegree + unitDegree * (i + 1))
				{
					return directionList[i];
				}
			}

			throw new ArgumentOutOfRangeException();

		}

		static int GetWindPower(decimal windMeterPerMinute)
		{
			var windSpeedPerSecond = Math.Round(windMeterPerMinute / 60m, 1, MidpointRounding.AwayFromZero);

			var windPowerList = new List<decimal>()
			{
				0.2m,
				1.5m,
				3.3m,
				5.4m,
				7.9m,
				10.7m,
				13.8m,
				17.1m,
				20.7m,
				24.4m,
				28.4m,
				32.6m,
				decimal.MaxValue
			};

			for(var i = 0; i < windPowerList.Count; i++)
			{
				if (windSpeedPerSecond <= windPowerList[i])
					return i;
			}

			throw new ArgumentOutOfRangeException();
		}
	}
}