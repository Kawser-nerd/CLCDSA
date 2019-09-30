// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Program.cs" company="">
//   
// </copyright>
// --------------------------------------------------------------------------------------------------------------------

namespace Google_Code_Jam_C_Sharp
{
    using System;
    using System.Collections.Generic;
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
            var ints = this.ReadIntegers();
            var n = ints.First();
            var nums = ints.Skip(1).ToArray();
            var dict = new Dictionary<long, List<long>>();
            foreach (var num in nums)
            {
                var modified = new Dictionary<long, List<long>>(dict);
                foreach (var val in dict)
                {
                    var total = val.Key + num;
                    var combined = val.Value.ToList();
                    combined.Add(num);
                    if (dict.ContainsKey(total))
                    {
                        var one = dict[total];
                        AssertValid(one, combined);
                        return "\n" + Print(one) + "\n" + Print(combined);
                    }
                    else
                    {
                        modified[total] = combined;
                    }
                }

                if (dict.ContainsKey(num))
                {
                    AssertValid(dict[num], new List<long>() { num});
                    return "\n" + Print(dict[num]) + "\n" + num;
                }

                dict = modified;
                dict[num] = new List<long>() { num };
            }
            return "Impossible";
        }

        private void AssertValid(List<long> p0, List<long> p1)
        {
            var res = p0.Aggregate(0L, (a, b) => a + b);
            Debug.Assert(res ==
                p1.Aggregate(0L, (a, b) => a + b));
        }

        private object Print(List<long> one)
        {
            var stringBuilder = new StringBuilder();
            var isFirst = true;
            foreach (var l in one)
            {
                if (!isFirst) stringBuilder.Append(" ");
                isFirst = false;
                stringBuilder.Append(l);
            }
            return stringBuilder.ToString();
        }

        #endregion
    }
}