// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Program.cs" company="">
//   
// </copyright>
// --------------------------------------------------------------------------------------------------------------------

namespace Google_Code_Jam_C_Sharp
{
    using System;
    using System.Drawing;
    using System.IO;
    using System.Linq;

    public class Program : IDisposable
    {
        #region Constants and Fields

        private readonly StreamReader Reader = new StreamReader("../../in.in");

        private readonly StreamWriter Writer = new StreamWriter("../../out.txt");

        int CANT_REACH = int.MinValue;

        private int yCount;

        private int xCount;

        private int[,] ceiling;

        private int[,] floor;

        private int[,] best;

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

        private int ReadCasesCount()
        {
            return int.Parse(this.Reader.ReadLine());
        }

        private int ReadInteger()
        {
            return int.Parse(this.Reader.ReadLine());
        }

        private int[] ReadIntegers()
        {
            var readStrings = this.ReadStrings();
            return readStrings.Select(readString => int.Parse(readString)).ToArray();
        }

        private string[] ReadStrings()
        {
            return this.Reader.ReadLine().Split(' ');
        }

        private void Run()
        {
            var casesCount = this.ReadCasesCount();
            for (int caseIndex = 1; caseIndex <= casesCount; ++caseIndex)
            {
                var result = this.SolveCase(caseIndex);
                this.Writer.WriteLine("Case #{0}: {1}", caseIndex.ToString(), result);
                this.Writer.Flush();
            }
        }

        bool canFitIn(Point source)
        {
            return ceiling[source.X, source.Y] - floor[source.X, source.Y] >= 50;
        }

        bool canEverMove(Point source, Point target)
        {
            return canFitIn(target)
                && ceiling[target.X, target.Y] - floor[source.X, source.Y] >= 50
                && ceiling[source.X, source.Y] - floor[target.X, target.Y] >= 50;
        }

        int whenCanFirstMoveFrom(Point source, Point target)
        {
            if (canEverMove(source, target))
            {
                return ceiling[target.X, target.Y] - 50;
            }
            else
            {
                return CANT_REACH;
            }
        }

        private string SolveCase(int caseIndex)
        {
            var ints = this.ReadIntegers();
            var currentWaterLevel = ints[0];
            yCount = ints[1];
            xCount = ints[2];
            ceiling = new int[xCount, yCount];
            floor = new int[xCount, yCount];
            best = new int[xCount, yCount];
            for (int yi = 0; yi < yCount; ++yi)
            {
                ints = this.ReadIntegers();
                for (int xi = 0; xi < xCount; ++xi)
                {
                    ceiling[xi, yi] = ints[xi];
                }
            }

            for (int yi = 0; yi < yCount; ++yi)
            {
                ints = this.ReadIntegers();
                for (int xi = 0; xi < xCount; ++xi)
                {
                    floor[xi, yi] = ints[xi];
                }
            }

            for (int yi = 0; yi < yCount; ++yi)
            {
                for (int xi = 0; xi < xCount; ++xi)
                {
                    best[xi, yi] = CANT_REACH;
                }
            }

            var changes = new[] { new[] { -1, 0 }, new[] { 0, -1 }, new[] { 1, 0 }, new[] { 0, 1 } };
            var isThereChange = true;
            var dropDownRate = 10;
            this.best[0, 0] = currentWaterLevel;
            while (isThereChange)
            {
                isThereChange = false;
                for (int yi = 0; yi < yCount; ++yi)
                {
                    for (int xi = 0; xi < xCount; ++xi)
                    {
                        var targetPoint = new Point(xi, yi);
                        foreach (var change in changes)
                        {
                            var sourcePoint = new Point(xi + change[0], yi + change[1]);
                            if (sourcePoint.X >= 0 && sourcePoint.X < xCount
                                && sourcePoint.Y >= 0 && sourcePoint.Y < yCount
                                && best[sourcePoint.X, sourcePoint.Y] != CANT_REACH)
                            {
                                var moveInitialTime = Math.Min(
                                    this.whenCanFirstMoveFrom(sourcePoint, targetPoint), this.best[sourcePoint.X, sourcePoint.Y]);
                                if (moveInitialTime != CANT_REACH)
                                {

                                    var timeTaken = moveInitialTime == currentWaterLevel ? 0 :
                                        ((moveInitialTime - this.floor[sourcePoint.X, sourcePoint.Y] >= 20) ? 10 : 100);
                                    var potentialTime = moveInitialTime - timeTaken;
                                    if (potentialTime > this.best[targetPoint.X, targetPoint.Y])
                                    {

                                        this.best[targetPoint.X, targetPoint.Y] = potentialTime;
                                        isThereChange = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            var answ = (currentWaterLevel - this.best[this.xCount - 1, this.yCount - 1]) / 10.0;
            return answ.ToString().Replace(",", ".");
        }

        #endregion
    }
}