using System.IO;

namespace LastWord
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
                    var s = reader.ReadLine();

                    var lastWord = LastWord(s);

                    writer.WriteLine("Case #{0}: {1}", caseId, lastWord);
                    writer.Flush();
                }
            }
        }

        private static string LastWord(string s)
        {
            var result = "";

            foreach (var c in s)
            {
                if (result.Length == 0 || result[0] <= c) result = c + result;
                else result = result + c;
            }

            return result;
        }
    }
}
