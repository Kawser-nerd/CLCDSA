using System;
using System.IO;
using System.Linq;

namespace Round2ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            var inFile = args[0];
            var outFile = Path.ChangeExtension(inFile, ".out");

            using (var reader = new StreamReader(inFile))
            using (var writer = new StreamWriter(outFile))
            {
                var count = int.Parse(reader.ReadLine());
                for (var caseId = 1; caseId <= count; caseId++)
                {
                    var line = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();

                    var seats = line[0];
                    var customers = line[1];
                    var ticketCount = line[2];

                    var tickets = new int[ticketCount];
                    var ticketCustomers = new int[ticketCount];

                    for (int i=0; i<ticketCount; i++)
                    {
                        var ticketLine = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                        tickets[i] = ticketLine[0] - 1;
                        ticketCustomers[i] = ticketLine[1] - 1;
                    }


                    int upgrades;
                    var rides = MinRides(seats, customers, tickets, ticketCustomers, out upgrades);

                    writer.WriteLine("Case #{0}: {1} {2}", caseId, rides, upgrades);
                    writer.Flush();
                }
            }
        }

        private static int MinRides(int seats, int customers, int[] tickets, int[] ticketCustomers, out int upgrades)
        {
            int[] ticketCounts = new int[seats];
            foreach (var ticket in tickets)
            {
                ticketCounts[ticket]++;
            }

            int[] promotableTickets = new int[seats];
            for (var i = 0; i < seats; i++)
            {
                for (var j = i; j < seats; j++)
                {
                    promotableTickets[j] += ticketCounts[i];
                }
            }

            int minRides = 0;
            for (var i = 0; i < seats; i++)
            {
                var seatCount = i + 1;
                var seatRides = (promotableTickets[i] + seatCount - 1) / seatCount;
                if (seatRides > minRides)
                    minRides = seatRides;
            }

            int[] customerTickets = new int[customers];
            foreach (var customer in ticketCustomers)
            {
                customerTickets[customer]++;
            }

            foreach (var count in customerTickets)
            {
                if (count > minRides)
                    minRides = count;
            }

            upgrades = 0;
            foreach (var count in ticketCounts)
            {
                if (count > minRides)
                {
                    upgrades += count - minRides;
                }
            }

            return minRides;
        }
    }
}
