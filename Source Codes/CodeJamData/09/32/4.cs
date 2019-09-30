using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemB
{
	class Program
	{
		private const string InputFile = "Input.txt";
		private const string OutputFile = "Output.txt";

		class Firefly
		{
			public double X, Y, Z, VX, VY, VZ;
		}
		
		static void Main(string[] args)
		{
			string[] lines = File.ReadAllLines(InputFile);
			int testCaseCount = Int32.Parse(lines[0]);
			int currentLine = 1;
			File.WriteAllText(OutputFile, String.Empty);
			for (int i = 0; i < testCaseCount; ++i)
			{
				int fireflyCount = Int32.Parse(lines[currentLine++]);
				List<Firefly> fireflies = new List<Firefly>();
				for (int j = 0; j < fireflyCount; ++j)
				{
					string[] split = lines[currentLine++].Split();
					Firefly firefly = new Firefly();
					firefly.X = Int32.Parse(split[0]);
					firefly.Y = Int32.Parse(split[1]);
					firefly.Z = Int32.Parse(split[2]);
					firefly.VX = Int32.Parse(split[3]);
					firefly.VY = Int32.Parse(split[4]);
					firefly.VZ = Int32.Parse(split[5]);
					fireflies.Add(firefly);
				}

				double distance, time;
				FindDistanceAndTime(fireflies, out distance, out time);
				File.AppendAllText(
					OutputFile,
					String.Format(CultureInfo.InvariantCulture, "Case #{0}: {1:0.00000000} {2:0.00000000}\n", i + 1, distance, time));
			}
		}

		private static void FindDistanceAndTime(List<Firefly> fireflies, out double distance, out double time)
		{
			double sumX = 0, sumY = 0, sumZ = 0, sumVX = 0, sumVY = 0, sumVZ = 0;
			foreach (Firefly firefly in fireflies)
			{
				sumX += firefly.X;
				sumY += firefly.Y;
				sumZ += firefly.Z;
				sumVX += firefly.VX;
				sumVY += firefly.VY;
				sumVZ += firefly.VZ;
			}

			double speedSqr = sumVX * sumVX + sumVY * sumVY + sumVZ * sumVZ;
			if (speedSqr < 1e-6)
				time = 0;
			else
				time = -(sumX * sumVX + sumY * sumVY + sumZ * sumVZ) / speedSqr;
			time = Math.Max(time, 0);

			double n2 = fireflies.Count * fireflies.Count;
			distance =
				(sumX + sumVX * time) * (sumX + sumVX * time) +
				(sumY + sumVY * time) * (sumY + sumVY * time) +
				(sumZ + sumVZ * time) * (sumZ + sumVZ * time);
			distance = Math.Sqrt(distance / n2);
		}
	}
}
