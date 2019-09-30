// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Program.cs" company="">
//   
// </copyright>
// --------------------------------------------------------------------------------------------------------------------

namespace Google_Code_Jam_C_Sharp
{
    using System;
    using System.Diagnostics;
    using System.IO;
    using System.Linq;
    using System.Text;

    public class Program : IDisposable
    {
        #region Constants and Fields

        private readonly StreamReader Reader = new StreamReader("../../in.in");

        private readonly StreamWriter Writer = new StreamWriter("../../out.txt");

        #endregion

        #region Public Methods and Operators

        public static void Main()
        {
            using (var program = new Program())
            {
                program.Run();
            }
        }

        public void Dispose()
        {
            this.Reader.Dispose();
            this.Writer.Dispose();
        }

        #endregion

        #region Methods

        private long ReadCasesCount()
        {
            return long.Parse(this.Reader.ReadLine());
        }

        private long ReadInteger()
        {
            return long.Parse(this.Reader.ReadLine());
        }

        private long[] ReadIntegers()
        {
            var readStrings = this.ReadStrings();
            return readStrings.Select(readString => long.Parse(readString)).ToArray();
        }

        private string[] ReadStrings()
        {
            return this.Reader.ReadLine().Split(' ');
        }

        private void Run()
        {
            var casesCount = this.ReadCasesCount();
            for (long caseIndex = 1; caseIndex <= casesCount; ++caseIndex)
            {
                var result = this.SolveCase(caseIndex);
                this.Writer.WriteLine("Case #{0}: {1}", caseIndex.ToString(), result);
                this.Writer.Flush();
            }
        }

        private string SolveCase(long caseIndex)
        {
            var integers = this.ReadIntegers();
            var contestantsCount = integers.First();
            var points = integers.Skip(1).ToArray();
            var totalPoints = points.Aggregate(0, (a, b) => (int)(a + b));
            var constant = (2.0 * totalPoints) / contestantsCount;
            var securedContestantsCount = points.Count(num => num >= constant);
            var nonSecuredContestants = points.Where(point => point < constant);
            var newTotal = nonSecuredContestants.Aggregate(0, (a, b) => (int)(a + b)) + totalPoints;
            var newConstant = newTotal / (double) nonSecuredContestants.Count();
            var results = points.Select(point => 100 * Math.Max(0, newConstant - point) / Convert.ToDouble(totalPoints)).ToArray();

            var totalPercentage = results.Aggregate(0.0, (a, b) => a + b);
            var condition1 = Math.Abs(100 - totalPercentage) <= 0.0000001;
            if (!condition1)
            {
                Debug.Assert(condition1);
            }

            for (int i = 0; i < results.Count(); ++i)
            {
                var sum = results[i] * totalPoints + points[i];
                var diff = constant - sum;
                var condition = diff <= 0.0000001;
                if (!condition)
                {
                    Debug.Assert(condition);
                }
            }

            var stringBuilder = new StringBuilder();

            bool isFirst = true;
            foreach (var result in results)
            {
                if (!isFirst)
                {
                    stringBuilder.Append(" ");
                }

                isFirst = false;
                stringBuilder.Append(result.ToString().Replace(",", "."));
            }
            return stringBuilder.ToString();
        }

        #endregion
    }
}