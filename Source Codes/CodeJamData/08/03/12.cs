using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;

namespace Fly
{
  class Program
  {
    static void Main(string[] args)
    {
      String prefix = "C-large";
      FileStream read = File.OpenRead(prefix + ".in");
      StreamReader sr = new StreamReader(read);
      FileStream write = File.OpenWrite(prefix + ".out");
      StreamWriter wr = new StreamWriter(write);
      int numCases = int.Parse(sr.ReadLine());
      for (int i = 1; i <= numCases; i++)
      {
        HandleCase(i, sr, wr);
      }
      wr.Flush();
      wr.Close();
    }

    public static void HandleCase(int index, StreamReader input, StreamWriter output)
    {
      string[] split = input.ReadLine().Split(' ');
      double f = double.Parse(split[0]);
      double R = double.Parse(split[1]);
      double t = double.Parse(split[2]);
      double r = double.Parse(split[3]);
      double g = double.Parse(split[4]);
      double res = HandleCase(f, R, t, r, g);
      output.WriteLine("Case #{0}: {1}", index, res.ToString(CultureInfo.InvariantCulture));
    }

    public static double HandleCase(double f, double R, double t, double r, double g)
    {
      return HandleCase(R, t + f, r + f, g - f * 2);


    }

    public static double HandleCase(double R, double t, double r, double g)
    {
      if (g <= 0)
        return 1;
      double innerRadius = R - t;
      double space = 0;
      for (double x = r; x < innerRadius; x += g + 2*r)
      {
        for (double y = r; y < innerRadius; y += g + 2*r)
        {
          double x1 = x;
          double x2 = x + g;
          double y1 = y;
          double y2 = y + g;
          if (x2 * x2 + y2 * y2 <= innerRadius * innerRadius)
          {
            space += g * g;
          }
          else if (x1 * x1 + y1 * y1 >= innerRadius * innerRadius)
          {
            // nothing
          }
          else if (x2 * x2 + y1 * y1 >= innerRadius * innerRadius && x1 * x1 + y2 * y2 <= innerRadius * innerRadius)
          {
            double lowintersectionx = Math.Sqrt(innerRadius * innerRadius - y1 * y1);
            double highintersectionx = Math.Sqrt(innerRadius * innerRadius - y2 * y2);
            double boxarea = (y2 - y1) * (highintersectionx-x1);
            double trianglearea = (y2 - y1) * (lowintersectionx - highintersectionx) / 2.0;
            double segmentdegrees = Math.Atan2(y2, highintersectionx) - Math.Atan2(y1, lowintersectionx);
            double segmentarea = 0.5 * innerRadius * innerRadius * (segmentdegrees - Math.Sin(segmentdegrees));
            double thisarea = boxarea + trianglearea + segmentarea;
            if (boxarea <0)
              throw new Exception("Error");
            if (trianglearea < 0)
              throw new Exception("Error");
            if (segmentarea < 0)
              throw new Exception("Error");
            if (thisarea > g * g)
              throw new Exception("Error");
            space += thisarea;
          }
          else if (x1 * x1 + y2 * y2 >= innerRadius * innerRadius && x2 * x2 + y1 * y1 <= innerRadius * innerRadius)
          {
            double leftintersectiony = Math.Sqrt(innerRadius * innerRadius - x1 * x1);
            double rightintersectiony = Math.Sqrt(innerRadius * innerRadius - x2 * x2);
            double boxarea = (x2 - x1) * (rightintersectiony-y1);
            double trianglearea = (x2 - x1) * (leftintersectiony - rightintersectiony) / 2.0;
            double segmentdegrees = Math.Atan2(leftintersectiony, x1) - Math.Atan2(rightintersectiony, x2);
            double segmentarea = 0.5 * innerRadius * innerRadius * (segmentdegrees - Math.Sin(segmentdegrees));
            double thisarea = boxarea + trianglearea + segmentarea;
            if (boxarea < 0)
              throw new Exception("Error");
            if (trianglearea < 0)
              throw new Exception("Error");
            if (segmentarea < 0)
              throw new Exception("Error");
            if (thisarea > g * g)
              throw new Exception("Error");
            space += thisarea;
          }
          else if (x1 * x1 + y2 * y2 >= innerRadius * innerRadius && x2 * x2 + y1 * y1 >= innerRadius * innerRadius)
          {
            double intersectionx = Math.Sqrt(innerRadius * innerRadius - y1 * y1);
            double intersectiony = Math.Sqrt(innerRadius * innerRadius - x1 * x1);
            double trianglearea = (intersectionx - x1) * (intersectiony - y1) / 2.0;
            double segmentdegrees = Math.Atan2(intersectionx, y1) - Math.Atan2(x1, intersectiony);
            double segmentarea = 0.5 * innerRadius * innerRadius * (segmentdegrees - Math.Sin(segmentdegrees));
            double thisarea = trianglearea + segmentarea;
            if (trianglearea < 0)
              throw new Exception("Error");
            if (segmentarea < 0)
              throw new Exception("Error");
            if (thisarea > g * g)
              throw new Exception("Error");
            space += thisarea;
          }
          else if (x1 * x1 + y2 * y2 <= innerRadius * innerRadius && x2 * x2 + y1 * y1 <= innerRadius * innerRadius)
          {
            double intersectionx = Math.Sqrt(innerRadius * innerRadius - y2 * y2);
            double intersectiony = Math.Sqrt(innerRadius * innerRadius - x2 * x2);
            double boxarea1 = (intersectionx - x1) * (y2 - y1);
            double boxarea2 = (x2 - intersectionx) * (intersectiony - y1);
            double trianglearea = (x2 - intersectionx) * (y2 - intersectiony) / 2.0;
            double segmentdegrees = Math.Atan2(y2, intersectionx) - Math.Atan2(intersectiony, x2);
            double segmentarea = 0.5 * innerRadius * innerRadius * (segmentdegrees - Math.Sin(segmentdegrees));
            double thisarea = boxarea1 + boxarea2 + trianglearea + segmentarea;
            if (boxarea1 < 0)
              throw new Exception("Error");
            if (boxarea2 < 0)
              throw new Exception("Error");
            if (trianglearea < 0)
              throw new Exception("Error");
            if (segmentarea < 0)
              throw new Exception("Error");
            if (thisarea > g * g+0.000001)
              throw new Exception("Error");
            space += thisarea;
          }
          else
          {
            Console.WriteLine(innerRadius * innerRadius);
            Console.WriteLine(x1 * x1 + y1 * y1);
            Console.WriteLine(x1 * x1 + y2 * y2);
            Console.WriteLine(x2 * x2 + y1 * y1);
            Console.WriteLine(x2 * x2 + y2 * y2);
            throw new Exception(string.Format("Unhandled case {0} {1} {2} {3} {4}", x1, x2, y1, y1, innerRadius));
          }
        }
      }
      return 1.0 - 4.0 * space / (Math.PI * R * R);
    }
  }
}
