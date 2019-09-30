using System;
using System.Collections.Generic;
using System.Linq;

namespace _1CB
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			var line = Console.ReadLine();
			var testCount = int.Parse(line);
			for (var testNumber = 1; testNumber <= testCount; testNumber++)
			{
				var elements = Console.ReadLine().Split();
				var D = double.Parse(elements[0]);
				var N = int.Parse(elements[1]);
				var A = int.Parse(elements[2]);
				var otherCar = new List<Tuple<double, double>>(N);
				for (var i = 0; i < N; i++)
				{
					elements = Console.ReadLine().Split();
					otherCar.Add(new Tuple<double, double>(double.Parse(elements[0]), double.Parse(elements[1])));
				}
				var accels = new double[A];
				elements = Console.ReadLine().Split();
				for (var i = 0; i < A; i++)
					accels[i] = double.Parse(elements[i]);

				// Small Input!
				var bestTime = 0d;
				var obstructed = otherCar[0].Item2 < D;
				if (obstructed)
				{
					var speed = (otherCar[1].Item2 - otherCar[0].Item2) / (otherCar[1].Item1 - otherCar[0].Item1);
					bestTime = otherCar[0].Item1 + (D - otherCar[0].Item2) / speed;
				}

				var answers = new double[A];
				for (var i = 0; i < A; i++)
				{
					var t = Math.Sqrt(2d * D / accels[i]);
					answers[i] = obstructed ? Math.Max(t, bestTime) : t;
				}

				Console.WriteLine("Case #{0}:", testNumber);
				for (var i = 0; i < A; i++)
					Console.WriteLine(answers[i]);
			}
		}
	}
}
