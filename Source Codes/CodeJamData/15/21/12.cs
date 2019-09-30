namespace CodeJamQualification
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Numerics;

    using BonMaman;
    using BonMaman.ProblemInfrastructure;
    using BonMaman.ProblemInfrastructure.FileLoaders;

    using CodeJamQualification.Cj2015Qual;

    internal class Program
    {
        private const string InputDataDirectory = @"C:\Users\Giles\Downloads";

        private static void Main(string[] args)
        {
            var problemSolver = new ProblemSolver<PoetrySlamTestCase>(
                new PoetrySlamTestCaseLoader(),
                new SimpleTestCaseSolverFactory<PoetrySlamTestCase>(t => new PoetrySlamTestCaseSolver(t)),
                new LoadLatestInputFile(InputDataDirectory));

            problemSolver.Solve();

            Console.WriteLine("Problem Solved!");
            Console.ReadLine();

            //var testCaseInput = new List<int>() { 10, 100, 1000, 10000, 100000 };

            //foreach (var testCase in testCaseInput.Select(t => new PoetrySlamTestCase(1, t)))
            //{
            //    var s = new PoetrySlamTestCaseSolver(testCase);
            //    Console.WriteLine(string.Format("result for {0}: {1}", testCase.N, s.Solve().ResultText));
            //}

            //Console.ReadLine();
        }    
    }

    public class PoetrySlamTestCaseSolver : ITestCaseSolver<PoetrySlamTestCase>
    {
        private readonly PoetrySlamTestCase testCase;

        private static Dictionary<int, BigInteger> cache = new Dictionary<int,BigInteger>();

        public PoetrySlamTestCaseSolver(PoetrySlamTestCase testCase)
        {
            this.testCase = testCase;
        }

        public IResult Solve()
        {
            var n = this.testCase.N;

            if (n < 21)
            {
                return new Result(string.Format("Case #{0}: {1}", this.testCase.TestCaseId, n), this.testCase.TestCaseId);
            }

            var numberChars = n.ToString().ToCharArray();
            var numberLength = numberChars.Length;
            BigInteger countToGetToCorrectLength = this.FindCyclesToGetToCorrectLength(numberLength);

            if (new BigInteger(Math.Pow(10, numberLength-1)) == n)
            {
                return new Result(string.Format("Case #{0}: {1}", this.testCase.TestCaseId, countToGetToCorrectLength), this.testCase.TestCaseId);
            }

            BigInteger countToCorrectPattern = 0;

            if (numberChars.Last() == '0')
            {
                countToCorrectPattern = this.CountToCorrectPattern(numberLength, (n-1).ToString().ToCharArray()) +1;

            }
            else
            {
                countToCorrectPattern = this.CountToCorrectPattern(numberLength, numberChars);
            }

            var finalCount = countToGetToCorrectLength + countToCorrectPattern;
            return new Result(string.Format("Case #{0}: {1}", this.testCase.TestCaseId, finalCount), this.testCase.TestCaseId);
        }

        private BigInteger CountToCorrectPattern(int numberLength, char[] numberChars)
        {
            int s = this.StingyMidPoint(numberLength);
            var largeHalfCount = BigInteger.Parse(string.Join("", numberChars.Take(s).Reverse()));

            var swap = 0;

            if (largeHalfCount != 1)
            {
                swap = 1;
            }

            var smallHalf = BigInteger.Parse(string.Join("", numberChars.Skip(s).Take(numberLength - s))) - 1;
            var temp = smallHalf + swap + largeHalfCount;
            return temp;
        }

        private int GreedyMidPoint(int numberLength)
        {
            return (int)Math.Ceiling(numberLength / 2.0);
        }

        private int StingyMidPoint(int numberLength)
        {
            return numberLength / 2;
        }

        private BigInteger FindCyclesToGetToCorrectLength(int numberLength)
        {
            if (cache.ContainsKey(numberLength))
            {
                return cache[numberLength];
            }

            BigInteger ret;
            if (numberLength == 1)
            {
                return 1;
            }

            if (numberLength == 2)
            {
                return 10;
            }

            var amountToPreceedingOne = FindCyclesToGetToCorrectLength(numberLength - 1);
            var s = this.StingyMidPoint(numberLength-1);
            var firstHalf = new BigInteger(Math.Pow(10, s));
            var secondHalf = new BigInteger(Math.Pow(10, numberLength - s -1)) - 1;

            ret = amountToPreceedingOne + firstHalf +secondHalf;
            cache.Add(numberLength, ret);
            return ret;
        }
    }

    public class PoetrySlamTestCaseLoader : ITestCaseLoader<PoetrySlamTestCase>
    {
        public PoetrySlamTestCase LoadTestCase(int testCaseNumber, Input inputData)
        {
            return new PoetrySlamTestCase(testCaseNumber, inputData.NextLine().ReadStringAtIndexAsBigInt(0));
        }
    }

    public class PoetrySlamTestCase
    {
        public BigInteger N { get; set; }

        public int TestCaseId { get; set; }

        public PoetrySlamTestCase(int testCaseId, BigInteger n)
        {
            this.N = n;
            this.TestCaseId = testCaseId;
        }
    }
}