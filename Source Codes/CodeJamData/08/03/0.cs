using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace GCJ0_3
{

	struct Point
	{

		public Point(double x, double y)
			: this()
		{
			X = x;
			Y = y;
		}


		public double X { get; private set; }

		public double Y { get; private set; }


		public double GetDistanceFromCenter()
		{
			return Math.Sqrt(X * X + Y * Y);
		}

	}


	class PointFlyProblem
	{

		public PointFlyProblem() { }


		public double RacquetRadius { get; set; }

		public double RacquetThickness { get; set; }

		public double StringRadius { get; set; }

		public double StringGap { get; set; }


		private IList<double> GapStartCoordinates { get; set; }

		private double RacquetInnerRadius
		{
			get { return RacquetRadius - RacquetThickness; }
		}

		private double FullGapSquare
		{
			get { return StringGap * StringGap; }
		}


		public double Solve()
		{
			CalculateGapStartCoordinates();

			return 1 - GetGapsSquare() / GetRacquetSquare();
		}


		private void CalculateGapStartCoordinates()
		{
			GapStartCoordinates = new List<double>();

			double coordinate = StringRadius;

			while (coordinate < RacquetInnerRadius)
			{
				GapStartCoordinates.Add(coordinate);

				coordinate += StringGap + 2 * StringRadius;
			}
		}

		private double GetGapsSquare()
		{
			return 4 * GetRacquetQuarterGapsSquare();
		}

		private double GetRacquetQuarterGapsSquare()
		{
			double result = 0.0;

			foreach (double gapStartX in GapStartCoordinates)
			{
				double maxInnerYAtGapStartX = GetOtherMaxRacquetInnerCoordinate(gapStartX);

				foreach (double gapStartY in GapStartCoordinates)
				{
					if (gapStartY >= maxInnerYAtGapStartX)
						break;

					result += GetGapSquare(gapStartX, gapStartY);
				}
			}

			return result;
		}

		private double GetGapSquare(double gapStartX, double gapStartY)
		{
			if (gapStartY < gapStartX)
				return GetGapSquare(gapStartY, gapStartX);

			double gapEndX = gapStartX + StringGap;
			double gapEndY = gapStartY + StringGap;

			var maxGapXStartY = GetOtherMaxRacquetInnerCoordinate(gapStartX);
			var maxGapXEndY = GetOtherMaxRacquetInnerCoordinate(gapEndX);
			var maxGapYStartX = GetOtherMaxRacquetInnerCoordinate(gapStartY);
			var maxGapYEndX = GetOtherMaxRacquetInnerCoordinate(gapEndY);

			bool isLeftSideFull = maxGapXStartY >= gapEndY;
			bool isRightSideFull = maxGapXEndY >= gapEndY;
			bool isBottomSideFull = maxGapYStartX >= gapEndX;
			bool isTopSideFull = maxGapYEndX >= gapEndX;

			if (isRightSideFull)
				return FullGapSquare;

			if (isLeftSideFull)
			{
				if (isBottomSideFull)
				{
					var topBarHeight = gapEndY - maxGapXEndY;
					var bottomBarsHeight = StringGap - topBarHeight;
					var rightBarWidth = gapEndX - maxGapYEndX;
					var leftBarsWidth = StringGap - rightBarWidth;

					var topLeftBarSquare = topBarHeight * leftBarsWidth;
					var bottomLeftBarSquare = bottomBarsHeight * leftBarsWidth;
					var bottomRightBarSquare = bottomBarsHeight * rightBarWidth;
					var triangleSquare = topBarHeight * rightBarWidth / 2;
					var segmentSquare = GetSegmentSquare(maxGapYEndX, maxGapXEndY);

					return topLeftBarSquare + bottomLeftBarSquare + bottomRightBarSquare + triangleSquare + segmentSquare;
				}
				else
				{
					var barWidth = maxGapYEndX - gapStartX;
					var barSquare = StringGap * barWidth;
					var triangleWidth = maxGapYStartX - maxGapYEndX;
					var triangleSquare = StringGap * triangleWidth / 2;
					var segmentSquare = GetSegmentSquare(maxGapYEndX, gapStartY);

					return barSquare + triangleSquare + segmentSquare;
				}
			}
			else if (isBottomSideFull)
			{
				var barHeight = maxGapXEndY - gapStartY;
				var barSquare = StringGap * barHeight;
				var triangleHeight = maxGapXStartY - maxGapXEndY;
				var triangleSquare = StringGap * triangleHeight / 2;
				var segmentSquare = GetSegmentSquare(gapStartX, maxGapXEndY);

				return barSquare + triangleSquare + segmentSquare;
			}
			else
			{
				var triangleHeight = maxGapXStartY - gapStartY;
				var triangleWidth = maxGapYStartX - gapStartX;
				var triangleSquare = triangleHeight * triangleWidth / 2;
				var segmentSquare = GetSegmentSquare(gapStartX, gapStartY);

				return triangleSquare + segmentSquare;
			}
		}

		private double GetSegmentSquare(double x, double y)
		{
			double segmentStartAngle = Math.Asin(y / RacquetInnerRadius);
			double segmentEndAngle = Math.Acos(x / RacquetInnerRadius);
			double segmentAngle = segmentEndAngle - segmentStartAngle;
			return RacquetInnerRadius * RacquetInnerRadius / 2 * (segmentAngle - Math.Sin(segmentAngle));
		}

		private double GetOtherMaxRacquetInnerCoordinate(double coordinate)
		{
			if (coordinate >= RacquetInnerRadius)
				return 0.0;

			return Math.Sqrt(RacquetInnerRadius * RacquetInnerRadius - coordinate * coordinate);
		}

		private double GetRacquetSquare()
		{
			return Math.PI * RacquetRadius * RacquetRadius;
		}

	}


	class SphericalFlyProblem
	{

		public SphericalFlyProblem() { }


		public double FlyRadius { get; set; }

		public double RacquetRadius { get; set; }

		public double RacquetThickness { get; set; }

		public double StringRadius { get; set; }

		public double StringGap { get; set; }


		public double Solve()
		{
			if ((StringGap <= 2 * FlyRadius) || (RacquetThickness + FlyRadius >= RacquetRadius))
				return 1.0;

			var pointFlyProblem = new PointFlyProblem
			{
				RacquetRadius = RacquetRadius,
				RacquetThickness = RacquetThickness + FlyRadius,
				StringRadius = StringRadius + FlyRadius,
				StringGap = StringGap - 2 * FlyRadius
			};

			return pointFlyProblem.Solve();
		}

	}

	class Program
	{
		static void Main(string[] args)
		{
			int testCaseCount = int.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);

			for (int testCaseNumber = 1; testCaseNumber <= testCaseCount; testCaseNumber++)
			{
				var parameters = Console.ReadLine().Split(' ');

				var problem = new SphericalFlyProblem();
				problem.FlyRadius = double.Parse(parameters[0], CultureInfo.InvariantCulture);
				problem.RacquetRadius = double.Parse(parameters[1], CultureInfo.InvariantCulture);
				problem.RacquetThickness = double.Parse(parameters[2], CultureInfo.InvariantCulture);
				problem.StringRadius = double.Parse(parameters[3], CultureInfo.InvariantCulture);
				problem.StringGap = double.Parse(parameters[4], CultureInfo.InvariantCulture);

				var result = problem.Solve();

				Console.WriteLine(string.Format(CultureInfo.InvariantCulture, "Case #{0}: {1:F6}",
					testCaseNumber, result));
			}

		}
	}
}
