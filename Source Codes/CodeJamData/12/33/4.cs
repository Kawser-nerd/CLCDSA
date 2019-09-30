using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BoxFactory
{
    class Program
    {
        static void Main(string[] args)
        {
            var cases = int.Parse(Console.ReadLine());

            for (int i = 1; i <= cases; i++)
            {
                var counts = Console.ReadLine(); //I ignore this
                var toys = new Seq(Console.ReadLine());
                var boxes = new Seq(Console.ReadLine());
                var result = LCS(toys, boxes);

                Console.WriteLine("Case #{0}: {1}", i, result);
            }
        }



        //This is basically just the longest-common-subsequence problem
        // except the strings are potentially *very* long

        //We can repurpose the general LCS algorithm by operating on groups
        // of identical characters rather than just individual chars
        static long LCS(Seq X, Seq Y)
        {
            if (X.IsEmpty() || Y.IsEmpty())
            {
                return 0;
            }

            long result;
            if (memo.TryGetValue(new Tuple<Seq, Seq>(X, Y), out result))
                return result;

            if (X.Last().Item2 == Y.Last().Item2)
            {
                //chop off the common tail, check from there
                long commonLength = Math.Min(X.Last().Item1, Y.Last().Item1);
                var X1 = X.RemoveLast(commonLength);
                var Y1 = Y.RemoveLast(commonLength);

                result = LCS(X1, Y1) + commonLength;
            }
            else
            {

                //chop off either one or the other until it changes, then choose the highest
                //should consider memoizing this in the dynamic programming fashion, but CBF
                // E: Okay looking at the size limits on the large problem I will memoize it
                var X1 = X.RemoveLast(X.Last().Item1);
                var Y1 = Y.RemoveLast(Y.Last().Item1);

                result = Math.Max(
                    LCS(X1, Y),
                    LCS(X, Y1));
            }
            memo.Add(new Tuple<Seq, Seq>(X, Y), result);
            return result;
        }

        static Dictionary<Tuple<Seq, Seq>, long> memo = new Dictionary<Tuple<Seq, Seq>, long>();
    }

    class Seq
    {
        List<Tuple<long, long>> elements;

        public Seq(String line)
        {
            var tokes = line.Split(' ');
            elements = new List<Tuple<long, long>>(tokes.Length / 2);
            for (int i = 0; i < (tokes.Length / 2); i++)
            {
                elements.Add(new Tuple<long,long>(long.Parse(tokes[2 * i]), long.Parse(tokes[2 * i + 1])));
            }
        }

        // override object.Equals
        public override bool Equals(object obj)
        {
            //       
            // See the full list of guidelines at
            //   http://go.microsoft.com/fwlink/?LinkID=85237  
            // and also the guidance for operator== at
            //   http://go.microsoft.com/fwlink/?LinkId=85238
            //

            Seq other = obj as Seq;
            if (other == null)
                return false;
            if (elements.Count != other.elements.Count)
                return false;

            for (int i = 0; i < elements.Count; i++)
            {
                if (elements[i] != other.elements[i])
                    return false;
            }
            return true;
        }

        // override object.GetHashCode
        public override int GetHashCode()
        {
            var hash = 0;
            foreach(var t in elements)
            {
                hash ^= t.GetHashCode();
            }
            return hash;
        }

        private Seq(Seq s)
        {
            elements = s.elements.ToList();
        }

        public bool IsEmpty()
        {
            return !elements.Any();
        }

        public long Length()
        {
            return elements.Select(t => t.Item1).Aggregate((a, b) => a + b);
        }

        public Tuple<long, long> Last()
        {
            return elements[elements.Count - 1];
        }

        public Seq RemoveLast(long n)
        {
            Seq result = new Seq(this);
            var last = elements[elements.Count - 1];
            result.elements[elements.Count - 1] = new Tuple<long, long>(last.Item1 - n, last.Item2);
            if (result.elements[elements.Count - 1].Item1 == 0)
            {
                result.elements.RemoveAt(elements.Count - 1);
            }
            return result;
        }
    }
}
