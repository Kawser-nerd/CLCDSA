using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FlySwatter
{
    public class Program
    {
        public static void Main(string[] args)
        {
            string inputFile = args[0];
            string outputFile = args[1];

            (new FlySwatter()).Solve(inputFile, outputFile);
        }
    }

    class FlySwatter
    {
        private StreamWriter sw;
        private StreamReader sr;
        int currentTestCase;

        public void Solve
            (
            string inputFile,
            string outputFile
            )
        {
            using (sw = new StreamWriter(outputFile))
            {
                using (sr = new StreamReader(inputFile))
                {
                    int numberOfTestCases = int.Parse(sr.ReadLine());

                    for (currentTestCase = 1; currentTestCase <= numberOfTestCases; currentTestCase++)
                    {
                        SolveTestCase();
                    }
                }
            }
        }

        private void SolveTestCase()
        {
            string[] parameters = sr.ReadLine().Split(' ');

            FlySwatterTestCase testCase = new FlySwatterTestCase
                (
                double.Parse(parameters[0]),
                double.Parse(parameters[1]),
                double.Parse(parameters[2]),
                double.Parse(parameters[3]),
                double.Parse(parameters[4])
                );

            double probabilityOfHittingFly = testCase.ComputeProbabilityOfHittingFly();

            string answer = String.Format("Case #{0}: {1}", currentTestCase, probabilityOfHittingFly.ToString("F6"));
            
            sw.WriteLine(answer);
            Console.WriteLine(answer);
        }
    }

    class FlySwatterTestCase
    {
        double OuterRacketRadius { get; set; }
        double AdjustedStringRadius { get; set; }
        double AdjustedStringThickness { get; set; }
        double AdjustedStringGap { get; set; }
        double AdjustedInnerRacketRadius { get; set; }

        double AdjustedInnerRacketArea { get; set; }

        public FlySwatterTestCase
            (
            double flyRadius,
            double outerRacketRadius,
            double racketThickness,
            double stringRadius,
            double stringGap
            )
        {
            // Adjust parameters for a fly radius of zero, to eliminate one of 
            // the parameters from the equation.
            AdjustedStringRadius = stringRadius + flyRadius;
            AdjustedStringThickness = AdjustedStringRadius * 2.0D;
            AdjustedStringGap = stringGap - (flyRadius * 2.0D);
            double innerRacketRadius = outerRacketRadius - racketThickness;
            AdjustedInnerRacketRadius = innerRacketRadius - flyRadius;
            OuterRacketRadius = outerRacketRadius;

            AdjustedInnerRacketArea = Math.PI * AdjustedInnerRacketRadius * AdjustedInnerRacketRadius;
        }

        public double ComputeProbabilityOfHittingFly()
        {
            if (AdjustedStringGap <= 0.0D)
            {
                return 1.0D;
            }

            double areaOfOpenSquaresInTopRightQuadrant = ComputeAreaOfOpenSquaresInTopRightQuadrant();
            double areaOfWholeRacket = Math.PI * OuterRacketRadius * OuterRacketRadius;

            return 1.0D - ((areaOfOpenSquaresInTopRightQuadrant * 4.0D) / areaOfWholeRacket);
        }

        private double ComputeAreaOfOpenSquaresInTopRightQuadrant()
        {
            int numberOfSquaresCompletelyInRacket = 0;
            double areaOfPartialSquares = 0.0D;
            int x = 0;

            while (SquareIsAtLeastPartiallyInRacket(x, 0))
            {
                int y = 0;

                while (SquareIsAtLeastPartiallyInRacket(x, y))
                {
                    if (SquareIsCompletelyInRacket(x, y))
                    {
                        numberOfSquaresCompletelyInRacket++;
                    }
                    else
                    {
                        areaOfPartialSquares += ComputeAreaOfPartialSquare(x, y);
                    }

                    y++;
                }

                x++;
            }

            double areaOfWholeSquares = ((double) numberOfSquaresCompletelyInRacket) * AdjustedStringGap * AdjustedStringGap;
            return areaOfWholeSquares + areaOfPartialSquares;
        }

        private double ComputeAreaOfPartialSquare
            (
            int x,
            int y
            )
        {
            // Lower-left corner of square is inside the racket.
            // Upper-right corner of square is outside the racket.

            double leftEdge = AdjustedStringRadius + (((double)x) * (AdjustedStringGap + AdjustedStringThickness));
            double bottomEdge = AdjustedStringRadius + (((double)y) * (AdjustedStringGap + AdjustedStringThickness));
            double rightEdge = leftEdge + AdjustedStringGap;
            double topEdge = bottomEdge + AdjustedStringGap;

            bool topLeftCornerIsInsideRacket = (Hypotenuse(leftEdge, topEdge) <= AdjustedInnerRacketRadius);
            bool bottomRightCornerIsInsideRacket = (Hypotenuse(rightEdge, bottomEdge) <= AdjustedInnerRacketRadius);

            if (!topLeftCornerIsInsideRacket && !bottomRightCornerIsInsideRacket)
            {
                double topIntersectionPoint = GetThirdSideOfRightTriangle(AdjustedInnerRacketRadius, leftEdge);
                double rightIntersectionPoint = GetThirdSideOfRightTriangle(AdjustedInnerRacketRadius, bottomEdge);

                double angleOfTopIntersectionPoint = Math.Atan2(topIntersectionPoint, leftEdge);
                double angleOfRightIntersectionPoint = Math.Atan2(bottomEdge, rightIntersectionPoint);

                double areaOfArc = AreaOfArc(angleOfTopIntersectionPoint - angleOfRightIntersectionPoint);

                double areaOfTriangle1 = (topIntersectionPoint - bottomEdge) * leftEdge / 2.0D;
                double areaOfTriangle2 = (rightIntersectionPoint - leftEdge) * bottomEdge / 2.0D;

                return areaOfArc - areaOfTriangle1 - areaOfTriangle2;
            }
            else if (topLeftCornerIsInsideRacket && bottomRightCornerIsInsideRacket)
            {
                double leftIntersectionPoint = GetThirdSideOfRightTriangle(AdjustedInnerRacketRadius, topEdge);
                double bottomIntersectionPoint = GetThirdSideOfRightTriangle(AdjustedInnerRacketRadius, rightEdge);

                double angleOfLeftIntersectionPoint = Math.Atan2(topEdge, leftIntersectionPoint);
                double angleOfBottomIntersectionPoint = Math.Atan2(bottomIntersectionPoint, rightEdge);

                double areaOfArc = AreaOfArc(angleOfLeftIntersectionPoint - angleOfBottomIntersectionPoint);

                double leftEdgeIntersectionPoint = (topEdge / leftIntersectionPoint) * leftEdge;
                double bottomEdgeIntersectionPoint = (rightEdge / bottomIntersectionPoint) * bottomEdge;

                double areaOfTriangle1 = (bottomEdgeIntersectionPoint - leftEdge) * bottomEdge / 2.0D;
                double areaOfTriangle2 = (leftEdgeIntersectionPoint - bottomEdge) * leftEdge / 2.0D;

                double areaOfTriangle3 = (rightEdge - bottomEdgeIntersectionPoint) * (bottomIntersectionPoint - bottomEdge) / 2.0D;
                double areaOfTriangle4 = (topEdge - leftEdgeIntersectionPoint) * (leftIntersectionPoint - leftEdge) / 2.0D;

                return (areaOfArc - areaOfTriangle1 - areaOfTriangle2) + areaOfTriangle3 + areaOfTriangle4;
            }
            else if (!topLeftCornerIsInsideRacket && bottomRightCornerIsInsideRacket)
            {
                double leftIntersectionPoint = GetThirdSideOfRightTriangle(AdjustedInnerRacketRadius, leftEdge);
                double rightIntersectionPoint = GetThirdSideOfRightTriangle(AdjustedInnerRacketRadius, rightEdge);

                double angleOfLeftIntersectionPoint = Math.Atan2(leftIntersectionPoint, leftEdge);
                double angleOfRightIntersectionPoint = Math.Atan2(rightIntersectionPoint, rightEdge);

                double areaOfArc = AreaOfArc(angleOfLeftIntersectionPoint - angleOfRightIntersectionPoint);

                double bottomEdgeIntersectionPoint = (rightEdge / rightIntersectionPoint) * bottomEdge;

                double areaOfTriangle1 = leftEdge * (leftIntersectionPoint - bottomEdge) / 2.0D;
                double areaOfTriangle2 = bottomEdge * (bottomEdgeIntersectionPoint - leftEdge) / 2.0D;

                double areaOfTriangle3 = (rightEdge - bottomEdgeIntersectionPoint) * (rightIntersectionPoint - bottomEdge) / 2.0D;

                return (areaOfArc - areaOfTriangle1 - areaOfTriangle2) + areaOfTriangle3;
            }
            else if (topLeftCornerIsInsideRacket && !bottomRightCornerIsInsideRacket)
            {
                double topIntersectionPoint = GetThirdSideOfRightTriangle(AdjustedInnerRacketRadius, topEdge);
                double bottomIntersectionPoint = GetThirdSideOfRightTriangle(AdjustedInnerRacketRadius, bottomEdge);

                double angleOfTopIntersectionPoint = Math.Atan2(topEdge, topIntersectionPoint);
                double angleOfBottomIntersectionPoint = Math.Atan2(bottomEdge, bottomIntersectionPoint);

                double areaOfArc = AreaOfArc(angleOfTopIntersectionPoint - angleOfBottomIntersectionPoint);

                double leftEdgeIntersectionPoint = (topEdge / topIntersectionPoint) * leftEdge;

                double areaOfTriangle1 = leftEdge * (leftEdgeIntersectionPoint - bottomEdge) / 2.0D;
                double areaOfTriangle2 = bottomEdge * (bottomIntersectionPoint - leftEdge) / 2.0D;

                double areaOfTriangle3 = (topIntersectionPoint - leftEdge) * (topEdge - leftEdgeIntersectionPoint) / 2.0D;

                return (areaOfArc - areaOfTriangle1 - areaOfTriangle2) + areaOfTriangle3;
            }

            return 0.0D;
        }

        private double AreaOfArc
            (
            double arcAngle
            )
        {
            return (arcAngle / (2.0D * Math.PI)) * AdjustedInnerRacketArea;
        }

        private bool SquareIsAtLeastPartiallyInRacket
            (
            int x,
            int y
            )
        {
            double leftEdge = AdjustedStringRadius + (((double)x) * (AdjustedStringGap + AdjustedStringThickness));
            double bottomEdge = AdjustedStringRadius + (((double)y) * (AdjustedStringGap + AdjustedStringThickness));

            double radiusToLeftBottomCorner = Hypotenuse(leftEdge, bottomEdge);

            return (radiusToLeftBottomCorner < AdjustedInnerRacketRadius);
        }

        private bool SquareIsCompletelyInRacket
            (
            int x,
            int y
            )
        {
            double rightEdge = AdjustedStringRadius + AdjustedStringGap + (((double)x) * (AdjustedStringGap + AdjustedStringThickness));
            double topEdge = AdjustedStringRadius + AdjustedStringGap + (((double)y) * (AdjustedStringGap + AdjustedStringThickness));

            double radiusToTopRightCorner = Hypotenuse(rightEdge, topEdge);

            return (radiusToTopRightCorner <= AdjustedInnerRacketRadius);
        }

        private double Hypotenuse
            (
            double x,
            double y
            )
        {
            return Math.Sqrt(x * x + y * y);
        }

        private double GetThirdSideOfRightTriangle
            (
            double hypotenuse,
            double oneSide
            )
        {
            return Math.Sqrt(hypotenuse * hypotenuse - oneSide * oneSide);
        }
    }
}
