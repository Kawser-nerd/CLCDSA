using System.IO;
using System.Linq;

namespace Round1BProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            var testName = args[0];

            using (var reader = new StreamReader($"{testName}.in"))
            using (var writer = new StreamWriter($"{testName}.out"))
            {
                var count = int.Parse(reader.ReadLine());
                for (var caseId = 1; caseId <= count; caseId++)
                {
                    var line = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();

                    var d = line[0];
                    var numHorses = line[1];

                    var horsePositions = new int[numHorses];
                    var horseSpeed = new int[numHorses];

                    for (var i = 0; i < numHorses; i++)
                    {
                        var horseLine = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                        horsePositions[i] = horseLine[0];
                        horseSpeed[i] = horseLine[1];
                    }

                    var speed = GetMaxSpeed(d, horsePositions, horseSpeed);

                    writer.WriteLine("Case #{0}: {1}", caseId, speed);
                    writer.Flush();
                }
            }
        }

        private static double GetMaxSpeed(int d, int[] horsePositions, int[] horseSpeed)
        {
            var time = horsePositions.Zip(horseSpeed, (p, v) => (double)(d - p) / (double)v).Max();

            return d / time;
        }
    }
}
