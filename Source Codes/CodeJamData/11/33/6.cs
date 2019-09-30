using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace Bsp3
{
    class Program
    {
        private const string _fileIn = @"C:\Users\Peter\Documents\Google Code Jam\2011\Round1c\Bsp3\Bsp3\C-small-attempt0.in";
        private const string _fileOut = @"C:\Users\Peter\Documents\Google Code Jam\2011\Round1c\Bsp3\Bsp3\C-small-attempt0.out";

        static void Main(string[] args)
        {
            int caseCount = 1;
            StreamReader sr = new StreamReader(_fileIn);
            StreamWriter sw = new StreamWriter(_fileOut);

            sr.ReadLine();

            string line;
            string[] lineParts;

            long low, high, note;
            List<long> otherNotes = new List<long>();

            while (!sr.EndOfStream)
            {
                note = -1;
                line = sr.ReadLine();
                lineParts = line.Split(' ');

                otherNotes.Clear();
                low = long.Parse(lineParts[1]);
                high = long.Parse(lineParts[2]);

                line = sr.ReadLine();
                lineParts = line.Split(' ');

                for (int i = 0; i < lineParts.Length; i++)
                    otherNotes.Add(long.Parse(lineParts[i]));

                otherNotes.Sort();

                for (int i = otherNotes.Count - 1; i > 0; i--)
                {
                    if (otherNotes[i] == otherNotes[i - 1])
                        otherNotes.RemoveAt(i);
                }

                for (long i = low; i <= high && note == -1; i++)
                {
                    note = i;

                    Parallel.ForEach(otherNotes, (l, state) =>
                    {
                        if (i < l)
                        {
                            if (l % i != 0)
                                note = -1;
                        }
                        else
                        {
                            if (i % l != 0)
                                note = -1;
                        }

                        if (note == -1)
                            state.Break();
                    });
                }

                sw.WriteLine("Case #{0}: {1}", caseCount++, ((note == -1) ? "NO" : note.ToString()));
            }

            sw.Close();
        }

        private static bool ContainsInRoom(IEnumerable<int> room, int val, int[] wholeRoom)
        {
            foreach (var item in room)
            {
                if (wholeRoom[item] == val)
                    return true;
            }

            return false;
        }
    }
}
