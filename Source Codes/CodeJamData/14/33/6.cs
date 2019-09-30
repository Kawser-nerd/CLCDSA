using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemC
{
    public class Combination
    {
        private long n = 0;
        private long k = 0;
        public long[] data = null;

        public Combination(long n, long k)
        {
            if (n < 0 || k < 0) // normally n >= k
                throw new Exception("Negative parameter in constructor");

            this.n = n;
            this.k = k;
            this.data = new long[k];
            for (long i = 0; i < k; ++i)
                this.data[i] = i;
        } // Combination(n,k)

        public Combination(long n, long k, long[] a) // Combination from a[]
        {
            if (k != a.Length)
                throw new Exception("Array length does not equal k");

            this.n = n;
            this.k = k;
            this.data = new long[k];
            for (long i = 0; i < a.Length; ++i)
                this.data[i] = a[i];

            if (!this.IsValid())
                throw new Exception("Bad value from array");
        } // Combination(n,k,a)

        public bool IsValid()
        {
            if (this.data.Length != this.k)
                return false; // corrupted

            for (long i = 0; i < this.k; ++i)
            {
                if (this.data[i] < 0 || this.data[i] > this.n - 1)
                    return false; // value out of range

                for (long j = i + 1; j < this.k; ++j)
                    if (this.data[i] >= this.data[j])
                        return false; // duplicate or not lexicographic
            }

            return true;
        } // IsValid()

        public override string ToString()
        {
            string s = "{ ";
            for (long i = 0; i < this.k; ++i)
                s += this.data[i].ToString() + " ";
            s += "}";
            return s;
        } // ToString()

        public Combination Successor()
        {
            if (this.data[0] == this.n - this.k)
                return null;

            var i = 0L;
            for (i = this.k - 1; i > 0 && data[i] == this.n - this.k + i; --i)
                ;

            ++data[i];

            for (long j = i; j < this.k - 1; ++j)
                data[j + 1] = data[j] + 1;

            return this;
        } // Successor()

        public static long Choose(long n, long k)
        {
            if (n < 0 || k < 0)
                throw new Exception("Invalid negative parameter in Choose()");
            if (n < k)
                return 0; // special case
            if (n == k)
                return 1;

            long delta, iMax;

            if (k < n - k) // ex: Choose(100,3)
            {
                delta = n - k;
                iMax = k;
            }
            else // ex: Choose(100,97)
            {
                delta = k;
                iMax = n - k;
            }

            long ans = delta + 1;

            for (long i = 2; i <= iMax; ++i)
            {
                checked
                {
                    ans = (ans*(delta + i))/i;
                }
            }

            return ans;
        } // Choose()

    } // Combination class
    class Program
    {
        static IEnumerable<string> Combinations(List<string> characters, int length)
        {
            for (int i = 0; i < characters.Count; i++)
            {
                // only want 1 character, just return this one
                if (length == 1)
                    yield return characters[i];

                // want more than one character, return this one plus all combinations one shorter
                // only use characters after the current one for the rest of the combinations
                else
                    foreach (string next in Combinations(characters.GetRange(i + 1, characters.Count - (i + 1)), length - 1))
                        yield return characters[i] + next;
            }
        }

        class TableCell
        {
            public int X;
            public int Y;

            public bool HasStone;
            public bool HasX;

            public bool IsFillChecked;
            public int Partition;
        }

        static string TableToString(TableCell[][] table)
        {
            return String.Join("\r\n", table.Select(x => String.Join("", x.Select(y => y.HasX && y.HasStone ? "O" : y.HasX ? "X" : "."))));
        }

        static int Fill(TableCell[][] table, int n, int m)
        {
            int partition = 0;

            Action<TableCell> fillCell = null;
            fillCell = tc =>
            {
                if (tc.IsFillChecked)
                    return;

                tc.Partition = partition;
                tc.IsFillChecked = true;

                if (!tc.HasX)
                    return;

                if (tc.Y < m - 1)
                    fillCell(table[tc.X][tc.Y + 1]);

                if (tc.Y > 0)
                    fillCell(table[tc.X][tc.Y - 1]);

                if (tc.X < n - 1)
                    fillCell(table[tc.X + 1][tc.Y]);

                if (tc.X > 0)
                    fillCell(table[tc.X - 1][tc.Y]);
            };

            while (true)
            {
                var currCell = table.SelectMany(x => x).FirstOrDefault(x => x.HasX && !x.IsFillChecked);
                if (currCell == null)
                    break;
                if (partition == 1)
                    return 0;
                fillCell(currCell);
                partition++;
            }

            return partition;
        }

        static void Main(string[] args)
        {
            using (var sr = new StreamReader("input.txt"))
            using (var sw = new StreamWriter("output.txt") { AutoFlush = true })
            {
                Func<long[]> readIntArrLine = () => sr.ReadLine().Split(' ').Select(long.Parse).ToArray();

                var testCaseCount = readIntArrLine()[0];
                for (int iCase = 1; iCase <= testCaseCount; iCase++)
                {
                    var tcParams = readIntArrLine();
                    var n = (int)tcParams[0];
                    var m = (int)tcParams[1];
                    var k = (int)tcParams[2];

                    var stones = Enumerable.Range(0, n).Select(i => Enumerable.Range(0, m).Select(j => new TableCell(){ X = i, Y = j }).ToArray()).ToArray();

                    var result = long.MaxValue;

                    var c = new Combination(n * m, k);
                    while (c != null)
                    {
                        for (int i = 0; i < n*m; i++)
                        {
                            var cell = stones[i / m][i % m];
                            cell.HasX = false;
                            cell.IsFillChecked = false;
                            cell.HasStone = false;
                        }

                        foreach (var i in c.data)
                            stones[i / m][i % m].HasX = true;
                        c = c.Successor();

                        var partCount = Fill(stones, n, m);
                        if(partCount == 0)
                            continue;

                        for (int iPart = 0; iPart < partCount; iPart++)
                        {
                            for (int i = 0; i < n; i++)
                            {
                                for (int j = 0; j < m; j++)
                                    if (stones[i][j].HasX && stones[i][j].Partition == iPart)
                                    {
                                        stones[i][j].HasStone = true;
                                        break;
                                    }

                                for (int j = m - 1; j >= 0; j--)
                                    if (stones[i][j].HasX && stones[i][j].Partition == iPart)
                                    {
                                        stones[i][j].HasStone = true;
                                        break;
                                    }
                            }

                            for (int j = 0; j < m; j++)
                            {
                                for (int i = 0; i < n; i++)
                                    if (stones[i][j].HasX && stones[i][j].Partition == iPart)
                                    {
                                        stones[i][j].HasStone = true;
                                        break;
                                    }

                                for (int i = n - 1; i >= 0; i--)
                                    if (stones[i][j].HasX && stones[i][j].Partition == iPart)
                                    {
                                        stones[i][j].HasStone = true;
                                        break;
                                    }
                            }
                        }

                        var t = TableToString(stones);

                        var currRes = stones.SelectMany(x => x).Count(x => x.HasStone);
                        if (currRes < result)
                            result = currRes;
                    }

                    sw.WriteLine(String.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", iCase, result));
                }
            }
        }
    }
}
