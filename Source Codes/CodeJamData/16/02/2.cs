using System.IO;
using System.Linq;

namespace RevengeOfThePancakes
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
                for (var caseID = 1; caseID <= count; caseID++)
                {
                    var pancakeOrientations = reader.ReadLine().Select(c => c == '+').ToArray();

                    var flips = GetFlips(pancakeOrientations);

                    writer.WriteLine("Case #{0}: {1}", caseID, flips);
                    writer.Flush();
                }
            }
        }

        private static int GetFlips(bool[] pancakeOrientations)
        {
            var flips = 0;
            for (int i = 0; i < pancakeOrientations.Length - 1; i++)
            {
                if (pancakeOrientations[i] != pancakeOrientations[i + 1])
                {
                    flips++;
                }
            }

            if (!pancakeOrientations.Last())
            {
                flips++;
            }

            return flips;
        }
    }
}
