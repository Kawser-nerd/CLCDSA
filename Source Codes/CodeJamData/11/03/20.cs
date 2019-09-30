using System.IO;
using GCJ_base;
using System.Linq;

namespace GCJ_Candy
{
    class Program
    {
        static void Main()
        {
            new GcjCandy().Run();
        }
    }

    class GcjCandy : Gcj
    {
        public GcjCandy()
        {
            Problem = 'C';
            Small = false;
        }

        protected override string ComputeCase(TextReader reader)
        {
            reader.ReadLine();
            int[] numbers = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();

            if (numbers.Aggregate((i, j) => i ^ j) != 0)
                return "NO";

            return (numbers.Sum() - numbers.Min()).ToString();
        }
    }
}
