using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace r1apb
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader("../../input.txt"))
            using (var outputStream = new StreamWriter("../../output.txt", false, Encoding.Default))
            {
                var caseCount = int.Parse(inputStream.ReadLine());

                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    var myPlace = inputStream.ReadLine().Split().Select(s => long.Parse(s)).Skip(1).ToArray()[0];
                    var barberTimes = inputStream.ReadLine().Split().Select(s => long.Parse(s)).ToArray();

                    var maxServingTime = 100000000000000L;
                    var startTime = FindServingTime(0L, maxServingTime, barberTimes, myPlace - barberTimes.Length * 2) - 1;
                    if (startTime < 0)
                        startTime = 0;

                    var barbers = barberTimes.Select(bt => bt - (startTime % bt)).ToArray();
                    var consumedPlaces = barberTimes.Select(bt => startTime / bt).Sum();
                    consumedPlaces += barbers.Where(bt => bt > 0).Count();
                    if (consumedPlaces >= myPlace && startTime == 0)
                    {
                        outputStream.WriteLine("Case #{0}: {1}", caseNumber, myPlace);
                    }
                    else
                    {

                        while (true)
                        {
                            var zeroBarbers = barbers.Where(bt => bt == 0).Count();
                            if (zeroBarbers + consumedPlaces >= myPlace)
                                break;

                            consumedPlaces += zeroBarbers;
                            for (var i = 0; i < barbers.Length; i++)
                                if (barbers[i] == 0)
                                    barbers[i] = barberTimes[i];

                            var toConsume = barbers.Min();
                            for (var i = 0; i < barbers.Length; i++)
                                barbers[i] -= toConsume;
                        }

                        var myBarber = -1;
                        for (var i = 0; i < barbers.Length; i++)
                        {
                            if (barbers[i] == 0)
                            {
                                consumedPlaces++;
                                if (consumedPlaces == myPlace)
                                    myBarber = i;
                            }
                        }
                        outputStream.WriteLine("Case #{0}: {1}", caseNumber, myBarber + 1);
                    }
                }
            }
        }

        private static long FindServingTime(long min, long max, long[] barberTimes, long finishedUp)
        {
            while (true)
            {
                if (min >= max)
                    return min;
                var middle = (min + max) / 2;
                var customersFullyServed = 0L;
                foreach (var barberTime in barberTimes)
                {
                    customersFullyServed += middle / barberTime;
                }
                if (customersFullyServed > finishedUp)
                    max = middle - 1;
                else if (customersFullyServed < finishedUp)
                    min = middle + 1;
                else
                    return middle;
            }
        }
    }
}
