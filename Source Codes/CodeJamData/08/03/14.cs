using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace FlySwatter
{
    class Program
    {
        //        C:\Users\Patrick\Desktop\output.txt
        //        C:\Users\Patrick\Dev\VS2008\SavingUniverse\FlySwatter\Program.cs

        const double EPSILON = 0.0000001;
        const double RADIUS_DIVISIONS = 16284;   //8192  //16284

        static void Main(string[] args)
        {
            using (var sr = new StreamReader(@"C:\Users\Patrick\Desktop\c-large.in"))
//            using (var sr = new StreamReader(@"C:\Users\Patrick\Desktop\c-small-attempt0.in"))
            using (var sw = new StreamWriter(@"C:\Users\Patrick\Desktop\output.txt"))
            {
                int cases = int.Parse(sr.ReadLine());
                for (int i = 0; i < cases; i++)
                    sw.WriteLine("Case #{0}: {1}", i + 1, SolveCase(sr).ToString("0.000000"));
            }
        }

        private static double SolveCase(StreamReader sr)
        {
            var values = sr.ReadLine().Split(' ');

            double fly = double.Parse(values[0]);
            double radius = double.Parse(values[1]);
            double wood = double.Parse(values[2]);
            double halfcord = double.Parse(values[3]);
            double spacing = double.Parse(values[4]);

            double internalRadius = radius - wood - fly;

            if ((fly * 2 / spacing) >= 1 - EPSILON)
                return 1.0;

            double totalArea = (radius * radius * Math.PI) / 4;
            double woodArea = totalArea - (internalRadius * internalRadius * Math.PI) / 4;

            double cordsArea = 0;

            double currentX = 0;
            double currentY = internalRadius;
            string[] elements = new[] { "cord", "flyradius", "crosscords", "flyradius", "cord" };
            int nextElement = 0;

            while (currentX / internalRadius < 1)
            {
                switch (elements[nextElement])
                {
                    case "cord":
                        VerticalElement(internalRadius, halfcord, ref cordsArea, ref currentX, ref currentY);
                        //Console.WriteLine("Element Tot Wood Cords : {0,-12} {1,6:0.000000} {2,6:0.000000} {3,6:0.000000} {4,8:0.000000}", elements[nextElement], totalArea, woodArea, cordsArea, (woodArea + cordsArea) / totalArea);
                        break;
                    case "flyradius":
                        VerticalElement(internalRadius, fly, ref cordsArea, ref currentX, ref currentY);
                        //Console.WriteLine("Element Tot Wood Cords : {0,-12} {1,6:0.000000} {2,6:0.000000} {3,6:0.000000} {4,8:0.000000}", elements[nextElement], totalArea, woodArea, cordsArea, (woodArea + cordsArea) / totalArea);
                        break;
                    case "crosscords":
                        {
                            double spacingEndX = Math.Min(currentX + spacing - fly * 2, internalRadius);

                            double hElementCurrentY = 0;
                            int nextHElement = 0;

                            while (hElementCurrentY / currentY < 1)
                            {
                                switch (elements[nextHElement])
                                {
                                    case "cord":
                                        HorizontalElements(internalRadius, currentX, currentY, halfcord, spacingEndX, ref hElementCurrentY, ref cordsArea);
                                        //Console.WriteLine("Element Tot Wood Cords : HOR {0,-12} {1,6:0.000000} {2,6:0.000000} {3,6:0.000000} {4,8:0.000000}", elements[nextElement], totalArea, woodArea, cordsArea, (woodArea + cordsArea) / totalArea);
                                        break;
                                    case "flyradius":
                                        HorizontalElements(internalRadius, currentX, currentY, fly, spacingEndX, ref hElementCurrentY, ref cordsArea);
                                        //Console.WriteLine("Element Tot Wood Cords : HOR {0,-12} {1,6:0.000000} {2,6:0.000000} {3,6:0.000000} {4,8:0.000000}", elements[nextElement], totalArea, woodArea, cordsArea, (woodArea + cordsArea) / totalArea); 
                                        break;
                                    case "crosscords":
                                        hElementCurrentY += (spacing - fly*2);
                                        //Console.WriteLine("Element Tot Wood Cords : HOR {0,-12} {1,6:0.000000} {2,6:0.000000} {3,6:0.000000} {4,8:0.000000}", elements[nextElement], totalArea, woodArea, cordsArea, (woodArea + cordsArea) / totalArea);
                                        break;
                                    default:
                                        throw new ApplicationException("element not valid");
                                }

                                nextHElement++;
                                nextHElement = nextHElement % elements.Length;
                            }
                            currentX = spacingEndX;
                            currentY = internalRadius * Math.Sin(Math.Acos((spacingEndX / internalRadius))); ;
                        }
                        //Console.WriteLine("Element Tot Wood Cords : {0,-12} {1,6:0.000000} {2,6:0.000000} {3,6:0.000000} {4,8:0.000000}", elements[nextElement], totalArea, woodArea, cordsArea, (woodArea + cordsArea) / totalArea);
                        break;
                    default:
                        throw new ApplicationException("element not valid");
                }

                nextElement++;
                nextElement = nextElement % elements.Length;
            }

            return (woodArea + cordsArea) / totalArea;
        }

        private static void HorizontalElements(double internalRadius, double currentX, double currentY, double elementWidth, double spacingEndX, ref double hElementCurrentY, ref double cordsArea)
        {
            double microUnit = internalRadius / RADIUS_DIVISIONS;
            int points = Math.Max((int)Math.Ceiling(elementWidth / microUnit - EPSILON), 1);
            for (int i = 0; i < points; i++)
            {
                double hElementNextY = Math.Min(hElementCurrentY + elementWidth / points, currentY);

                double baseWidth = Math.Min(internalRadius * Math.Cos(Math.Asin((hElementCurrentY / internalRadius))), spacingEndX) - currentX;
                double topWidth = Math.Min(internalRadius * Math.Cos(Math.Asin((hElementNextY / internalRadius))), spacingEndX) - currentX;

                cordsArea += (hElementNextY - hElementCurrentY) * (topWidth + baseWidth) / 2;

                hElementCurrentY = hElementNextY;

                if (hElementCurrentY / currentY > 1)
                    break;
            }
        }

        private static void VerticalElement(double internalRadius, double elementWidth, ref double cordsArea, ref double currentX, ref double currentY)
        {
            double microUnit = internalRadius / RADIUS_DIVISIONS;
            int points = Math.Max((int)Math.Ceiling(elementWidth / microUnit - EPSILON), 1);
            for (int i = 0; i < points; i++)
            {
                double nextX = Math.Min(currentX + elementWidth / points, internalRadius);
                double nextY = internalRadius * Math.Sin(Math.Acos((nextX / internalRadius)));
                cordsArea += (nextX - currentX) * (nextY + currentY) / 2;

                currentX = nextX;
                currentY = nextY;

                if (currentX / internalRadius > 1)
                    break;
            }
        }
    }
}
