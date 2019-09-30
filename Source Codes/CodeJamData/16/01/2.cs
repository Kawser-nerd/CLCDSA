using System.IO;
using System.Linq;

namespace CountingSheep
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
                    var n = int.Parse(reader.ReadLine());

                    var lastNumber = LastNumber(n);

                    var result = lastNumber.HasValue ? lastNumber.Value.ToString() : "INSOMNIA";
                    writer.WriteLine("Case #{0}: {1}", caseID, result);
                    writer.Flush();
                }
            }
        }

        private static int? LastNumber(int n)
        {
            if (n == 0) return null;

            var seenDigits = new bool[10];
            int i = 0;
            while (!seenDigits.All(d => d))
            {
                i++;
                var m = i * n;
                while (m > 0)
                {
                    seenDigits[m % 10] = true;
                    m /= 10;
                }
            }

            return i * n;
        }
    }
}
