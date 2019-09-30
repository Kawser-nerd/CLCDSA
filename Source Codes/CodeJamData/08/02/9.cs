using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TrainTimetable
{
    public enum Direction
    {
        AToB,
        BToA
    }

    public class Program
    {
        public static void Main(string[] args)
        {
            string inputFile = args[0];
            string outputFile = args[1];

            (new TrainTimetable()).Solve(inputFile, outputFile);
        }
    }

    public class Trip
    {
        public Direction Direction { get; set; }
        public DateTime StartTime { get; set; }
        public DateTime EndTime { get; set; }
    }

    public class Train
    {
        public Direction Direction { get; set; }
        public DateTime ReadyToGoTime { get; set; }
    }

    class TrainTimetable
    {
        private StreamWriter sw;
        private StreamReader sr;
        int currentTestCase;

        public void Solve
            (
            string inputFile,
            string outputFile
            )
        {
            using (sw = new StreamWriter(outputFile))
            {
                using (sr = new StreamReader(inputFile))
                {
                    int numberOfTestCases = int.Parse(sr.ReadLine());

                    for (currentTestCase = 1; currentTestCase <= numberOfTestCases; currentTestCase++)
                    {
                        SolveTestCase();
                    }
                }
            }
        }

        private void SolveTestCase()
        {
            int turnaroundTimeInMinutes = int.Parse(sr.ReadLine());

            string[] numberOfTrips = sr.ReadLine().Split(' ');
            int numberOfTripsFromAToB = int.Parse(numberOfTrips[0]);
            int numberOfTripsFromBToA = int.Parse(numberOfTrips[1]);

            List<Trip> trips = new List<Trip>();

            for (int i = 0; i < (numberOfTripsFromAToB + numberOfTripsFromBToA); i++)
            {
                string tripString = sr.ReadLine();
                string[] tripTimes = tripString.Split(' ');

                Trip newTrip = new Trip()
                    {
                        Direction = (i < numberOfTripsFromAToB) ? Direction.AToB : Direction.BToA,
                        StartTime = DateTime.Parse(tripTimes[0]),
                        EndTime = DateTime.Parse(tripTimes[1])
                    };

                trips.Add(newTrip);
            }

            trips.Sort(CompareTripsByStartTime);

            int numberOfTrainsStartingAtA = 0;
            int numberOfTrainsStartingAtB = 0;

            List<Train> trains = new List<Train>();

            foreach (Trip currentTrip in trips)
            {
                Train foundTrain = null;

                foreach (Train train in trains)
                {
                    if ((train.Direction == currentTrip.Direction) && (train.ReadyToGoTime <= currentTrip.StartTime))
                    {
                        // We found an available train.  Use it.
                        foundTrain = train;
                        break;
                    }
                }

                if (foundTrain == null)
                {
                    // Couldn't find an available train.  Must create a new train.
                    if (currentTrip.Direction == Direction.AToB)
                    {
                        numberOfTrainsStartingAtA++;
                    }
                    else
                    {
                        numberOfTrainsStartingAtB++;
                    }

                    foundTrain = new Train();
                    trains.Add(foundTrain);
                }

                foundTrain.Direction = this.SwitchDirections(currentTrip.Direction);
                foundTrain.ReadyToGoTime = currentTrip.EndTime + TimeSpan.FromMinutes(turnaroundTimeInMinutes);
            }

            string answer = String.Format("Case #{0}: {1} {2}", currentTestCase, numberOfTrainsStartingAtA, numberOfTrainsStartingAtB);
            
            sw.WriteLine(answer);
            Console.WriteLine(answer);
        }

        private Direction SwitchDirections
            (
            Direction direction
            )
        {
            return (direction == Direction.BToA) ? Direction.AToB : Direction.BToA;
        }

        private int CompareTripsByStartTime
            (
            Trip trip1,
            Trip trip2
            )
        {
            return trip1.StartTime.CompareTo(trip2.StartTime);
        }
    }
}
