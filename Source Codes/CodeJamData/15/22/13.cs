namespace CodeJamQualification
{
    using System;
    using System.Collections.Generic;
    using System.Linq;

    using BonMaman;
    using BonMaman.ProblemInfrastructure;
    using BonMaman.ProblemInfrastructure.FileLoaders;

    using CodeJamQualification.Cj2015Qual;

    internal class Program
    {
        private const string InputDataDirectory = @"C:\Users\Giles\Downloads";

        private static void Main(string[] args)
        {
            var problemSolver = new ProblemSolver<NoisyTestCase>(
                new NoisyTestCase.NoisyLoader(),
                new SimpleTestCaseSolverFactory<NoisyTestCase>(t => new NoisySolver(t)),
                new LoadLatestInputFile(InputDataDirectory));

            problemSolver.Solve();

            Console.WriteLine("Problem Solved!");
            Console.ReadLine();

            //var testCaseInput = new List<int>() { 10 };

            //foreach (
            //    var testCase in testCaseInput.Select(t => new NoisyTestCase() { X = 3, Y = 3, N = 8, TestCaseId = 1 }))
            //{
            //    var s = new NoisySolver(testCase);
            //    Console.WriteLine(string.Format("result for {0}: {1}", testCase.N, s.Solve().ResultText));
            //}

            //Console.ReadLine();
        }    
    }

    public class Grid
    {
        private readonly int x;

        private readonly int y;

        private readonly bool[] values;

        public Grid(int x, int y, bool[] values)
        {
            this.x = x;
            this.y = y;
            this.values = values;
        }

        public int FindNeighborCost()
        {
            var total = 0;
            for (int i = 0; i < values.Length; i++)
            {
                total += NeighborCount(i);
            }
            return total / 2;
        }

        private int NeighborCount(int index)
        {
            if (!values[index])
            {
                return 0;
            }

            var lx = index % this.x;
            var ly = index / this.x;

            var count = 0;

            if (lx > 0)
            {
                if (this.values[indexFromXY(lx - 1, ly)])
                {
                    count++;
                }
            }

            if (lx < this.x-1)
            {
                if (this.values[indexFromXY(lx + 1, ly)])
                {
                    count++;
                }
            }

            if (ly > 0)
            {
                if (this.values[indexFromXY(lx, ly - 1)])
                {
                    count++;
                }
            }

            if (ly < this.y -1)
            {
                if (this.values[indexFromXY(lx, ly + 1)])
                {
                    count++;
                }
            }

            return count;
        }

        private int indexFromXY(int x,int y)
        {
            return y * this.x + x;
        }
    }

    internal class NoisySolver : ITestCaseSolver<NoisyTestCase>
    {
        private readonly NoisyTestCase noisyTestCase;

        public NoisySolver(NoisyTestCase noisyTestCase)
        {
            this.noisyTestCase = noisyTestCase;
        }

        public IResult Solve()
        {
            var min = 1000000;
            foreach (Grid grid in BuildGrids())
            {
                var count = grid.FindNeighborCost();
                if (min > count)
                {
                    min = count;
                }
            }
            
            return new Result(string.Format("Case #{0}: {1}", this.noisyTestCase.TestCaseId, min), this.noisyTestCase.TestCaseId);
        }

        private IEnumerable<Grid> BuildGrids()
        {
            foreach (List<bool> gridInfo in BuildGridInfos(this.noisyTestCase.X * this.noisyTestCase.Y, this.noisyTestCase.N))
            {
                yield return new Grid(this.noisyTestCase.X, this.noisyTestCase.Y, gridInfo.ToArray());
            }
        }

        private IEnumerable<List<bool>> BuildGridInfos(int length, int n)
        {
            
            if (n == length)
            {
                yield return Enumerable.Repeat(true, n).ToList();
                yield break;
            }

            if (length == 1)
            {
                yield return Enumerable.Repeat(false, 1).ToList();
                yield break;
            }

            foreach (var subList in this.BuildGridInfos(length - 1, n - 1))
            {
                var updated = subList.Select(b => b).ToList();
                updated.Add(true);
                yield return updated;
            }

            foreach (var subList in this.BuildGridInfos(length - 1, n))
            {
                var updated = subList.Select(b => b).ToList();
                updated.Add(false);
                yield return updated;
            }
        }
    }

    public class NoisyTestCase
        {
            public int X { get;  set; }

            public int Y { get;  set; }

            public int N { get;  set; }

            public int TestCaseId { get; set; }

            public class NoisyLoader:ITestCaseLoader<NoisyTestCase>
            {
                public NoisyTestCase LoadTestCase(int testCaseNumber, Input inputData)
                {
                    var a = new NoisyTestCase(){TestCaseId = testCaseNumber};
                    inputData.NextLine()
                        .ReadNextItemAsInt(i => a.X = i)
                        .ReadNextItemAsInt(i => a.Y = i)
                        .ReadNextItemAsInt(i => a.N = i);
                    return a;
                }
            }
    }
}