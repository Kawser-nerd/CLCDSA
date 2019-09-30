using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int[] xyxytv = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int dist = xyxytv[4] * xyxytv[5];
        Vector s = new Vector(xyxytv[0], xyxytv[1]);
        Vector e = new Vector(xyxytv[2], xyxytv[3]);
        int n = int.Parse(Console.ReadLine());
        Vector[] vectors = Enumerable.Repeat(0, n).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToArray()).Select(x => new Vector(x[0], x[1])).ToArray();
        foreach (var v in vectors) if (((s - v).Length + (v - e).Length) <= dist) goto end;
        Console.WriteLine("NO");
        return;
        end:Console.WriteLine("YES");
    }
}
struct Vector
{
    public double x;
    public double y;
    public double this[int index]
    {
        get
        {
            if (index == 0) return x;
            else return y;
        }
        set
        {
            if (index == 0) x = value;
            else y = value;
        }
    }
    public double Length
    {
        get
        {
            return Math.Sqrt(x * x + y * y);
        }
    }
    public Vector(double x, double y)
    {
        this.x = x;
        this.y = y;
    }

    /// <summary>??</summary>
    public Vector rotateVector(double radian)
    {
        return new Vector(x * Math.Cos(radian) - y * Math.Sin(radian), x * Math.Sin(radian) + y * Math.Cos(radian));
    }
    /// <summary>??</summary>
    #region static

    /// <summary>??</summary>
    static public double crossProduct(Vector a, Vector b)
    {
        return a.x * b.y - a.y * b.x;
    }
    /// <summary>??</summary>
    static public double innerProduct(Vector a, Vector b)
    {
        return a.x * b.x + a.y * b.y;
    }
    #endregion

    #region operator
    public static Vector operator +(Vector a, Vector b)
    {
        return new Vector(a.x + b.x, a.y + b.y);
    }
    public static Vector operator -(Vector a, Vector b)
    {
        return new Vector(a.x - b.x, a.y - b.y);
    }
    #endregion
}