using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace GCJ0_2
{

	class Problem
	{

		public Problem(int turnaroundTimeInMinutes, IEnumerable<Trip> tripsFromAToB, IEnumerable<Trip> tripsFromBToA)
		{
			TurnaroundTimeInMinutes = turnaroundTimeInMinutes;
			TripsFromAToB = new List<Trip>(tripsFromAToB);
			TripsFromBToA = new List<Trip>(tripsFromBToA);
		}


		public int TurnaroundTimeInMinutes { get; private set; }

		public IList<Trip> TripsFromAToB { get; private set; }

		public IList<Trip> TripsFromBToA { get; private set; }


		public Solution Solve()
		{
			int trainCountAtA = GetTrainCount(TripsFromAToB, TripsFromBToA);
			int trainCountAtB = GetTrainCount(TripsFromBToA, TripsFromAToB);

			return new Solution(trainCountAtA, trainCountAtB);
		}


		private int GetTrainCount(IList<Trip> outgoingTrips, IList<Trip> incomingTrips)
		{
			SortedList<Time, int> freeTrainCountChanges = new SortedList<Time, int>();

			foreach (var outgoingTrip in outgoingTrips)
				AddFreeTrainCountChange(freeTrainCountChanges, outgoingTrip.StartTime, -1);

			foreach (var incomingTrip in incomingTrips)
				AddFreeTrainCountChange(freeTrainCountChanges, incomingTrip.EndTime + TurnaroundTimeInMinutes, 1);

			int result = 0;
			int cumulativeChange = 0;
			foreach (var freeTrainCountChange in freeTrainCountChanges.Values)
			{
				cumulativeChange += freeTrainCountChange;
				var candidateResult = -cumulativeChange;

				if (candidateResult > result)
					result = candidateResult;
			}

			return result;
		}

		private void AddFreeTrainCountChange(IDictionary<Time, int> freeCountChanges, Time time, int changeAmount)
		{
			int currentValue;
			if (freeCountChanges.TryGetValue(time, out currentValue))
				freeCountChanges[time] = currentValue + changeAmount;
			else
				freeCountChanges.Add(time, changeAmount);
		}

	}

	struct Solution
	{

		public Solution(int trainCountAtA, int trainCountAtB)
			: this()
		{
			TrainCountAtA = trainCountAtA;
			TrainCountAtB = trainCountAtB;
		}


		public int TrainCountAtA { get; private set; }

		public int TrainCountAtB { get; private set; }

	}

	struct Time : IComparable<Time>
	{

		private const int MinutesPerHour = 60;


		public static Time operator +(Time time, int offset)
		{
			return new Time { MinutesFromMidnight = time.MinutesFromMidnight + offset };
		}


		public Time(string value)
			: this()
		{
			var parts = value.Split(':');
			int hours = int.Parse(parts[0], CultureInfo.InvariantCulture);
			int minutes = int.Parse(parts[1], CultureInfo.InvariantCulture);

			MinutesFromMidnight = hours * MinutesPerHour + minutes;
		}


		public int MinutesFromMidnight { get; private set; }


		public int CompareTo(Time other)
		{
			return MinutesFromMidnight.CompareTo(other.MinutesFromMidnight);
		}

	}

	struct Trip
	{

		public Trip(string value)
			: this()
		{
			var times = value.Split(' ');

			StartTime = new Time(times[0]);
			EndTime = new Time(times[1]);
		}


		public Time StartTime { get; private set; }

		public Time EndTime { get; private set; }

	}

	class Program
	{
		static void Main(string[] args)
		{
			int testCaseCount = int.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);

			for (int testCaseNumber = 1; testCaseNumber <= testCaseCount; testCaseNumber++)
			{
				int turnaroundTimeInMinutes = int.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);
				var tripCounts = Console.ReadLine().Split(' ');
				int tripFromAToBCount = int.Parse(tripCounts[0], CultureInfo.InvariantCulture);
				int tripFromBToACount = int.Parse(tripCounts[1], CultureInfo.InvariantCulture);

				var tripsFromAToB = new List<Trip>(tripFromAToBCount);
				for (int tripIndex = 0; tripIndex < tripFromAToBCount; tripIndex++)
					tripsFromAToB.Add(new Trip(Console.ReadLine()));

				var tripsFromBToA = new List<Trip>(tripFromBToACount);
				for (int tripIndex = 0; tripIndex < tripFromBToACount; tripIndex++)
					tripsFromBToA.Add(new Trip(Console.ReadLine()));

				var problem = new Problem(turnaroundTimeInMinutes, tripsFromAToB, tripsFromBToA);
				var result = problem.Solve();

				Console.WriteLine(string.Format(CultureInfo.InvariantCulture, "Case #{0}: {1} {2}",
					testCaseNumber, result.TrainCountAtA, result.TrainCountAtB));
			}

		}
	}
}
