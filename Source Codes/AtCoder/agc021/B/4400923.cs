using System;
using System.Linq;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {

        int n = int.Parse(Console.ReadLine());
        Vector[] plot = Enumerable.Repeat(0, n).Select(_ => Console.ReadLine().Split().Select(long.Parse).ToArray()).Select(x => new Vector(x[0], x[1])).ToArray();

        for (long i = 0; i < plot.Length; i++)
        {
            bool initialized = false;
            Vector basev = new Vector();
            double lrad = 0;
            double rrad = 0;
            for (long j = 0; j < plot.Length; j++)
            {
                if (i == j) continue;
                
                Vector v = plot[i] - plot[j];
                //???
                if (!initialized)
                {
                    basev = v;
                    initialized = true;
                }
                
                //???????
                double vrad = Vector.GetRadian(basev, v);

                //???????????????(???????)
                if (Vector.CrossProduct(basev, v) < 0)
                {
                    //??top????????????????
                    rrad = Max(rrad, vrad);
                }
                //?????
                else if (Vector.CrossProduct(basev, v) > 0)
                {
                    //??top???????
                    lrad = Max(lrad, vrad);
                }
                else
                {
                    //???0?????????????????????
                    //????????????????????????
                    Vector super = new Vector(17178467375, 778918612);
                    if ((Vector.CrossProduct(super, v) < 0 && Vector.CrossProduct(super, basev) > 0) || 
                        (Vector.CrossProduct(super, v) > 0 && Vector.CrossProduct(super, basev) < 0))
                    {
                        //??????????Max?
                        lrad = PI;
                        rrad = PI;
                    }
                }
            }

            double deg = Max(PI - (lrad + rrad), 0);
            Console.WriteLine(deg / (PI * 2));
        }
    }
}

struct Line
{
    public Vector a;
    public Vector b;
    public Line(Vector a, Vector b)
    {
        this.a = a;
        this.b = b;
    }

    /// <summary>????????</summary>
    public static Vector Cross(Line a, Line b)
    {
        double delta = (a.b.x - a.a.x) * (b.b.y - b.a.y) - (a.b.y - a.a.y) * (b.b.x - b.a.x);
        if (delta == 0) throw new Exception();
        double ramda = ((b.b.y - b.a.y) * (b.b.x - a.a.x) - (b.b.x - b.a.x) * (b.b.y - a.a.y)) / delta;
        double mu = ((a.b.x - a.a.x) * (b.b.y - a.a.y) - (a.b.y - a.a.y) * (b.b.x - a.a.x)) / delta;

        return new Vector(a.a.x + ramda * (a.b.x - a.a.x), a.a.y + ramda * (a.b.y - a.a.y));
    }

    public override string ToString() => $"{a} {b}";
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
    static public double CrossProduct(Vector a, Vector b)
    {
        return a.x * b.y - a.y * b.x;
    }
    /// <summary>??</summary>
    static public double InnerProduct(Vector a, Vector b)
    {
        return a.x * b.x + a.y * b.y;
    }
    static public double GetRadian(Vector a, Vector b)
    {
        return Acos(InnerProduct(a, b) / (a.Length * b.Length));
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

    public static bool operator ==(Vector a, Vector b) => a.x == b.x && a.y == b.y;
    public static bool operator !=(Vector a, Vector b) => a.x != b.x || a.y != b.y;
    #endregion

    public override bool Equals(object obj) => this == (Vector)obj;
    public override int GetHashCode() => (x.GetHashCode() * 11192916 + y.GetHashCode());

    public override string ToString() => $"{x} {y}";
}