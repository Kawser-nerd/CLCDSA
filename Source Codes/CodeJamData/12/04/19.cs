using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

class Problem4
{
    private const string FileName = @"D-small-attempt0";
    private const string InputFileName = @"..\..\" + FileName + ".in";
    private const string OutputFileName = @"..\..\" + FileName + ".out";
    private const bool MultipleCases = true;

    public int Height { get; private set; }
    public int Width { get; private set; }
    public int Distance { get; private set; }

    private class HSegment
    {
        public int left, right;
    }

    private class VSegment
    {
        public int top, bottom;
    }

    private class Ray
    {
        public double x, y;
        public int mx, my;
        public double d;

        public Ray MoveInX(double dx)
        {
            double nx = x + dx;
            double ny = y + dx * my / mx;
            double nd = d - Math.Sqrt(dx * dx + (ny - y) * (ny - y));
            return new Ray() { x = nx, y = ny, mx = mx, my = my, d = nd };
        }

        public Ray MoveInY(double dy)
        {
            double nx = x + dy * mx / my;
            double ny = y + dy;
            double nd = d - Math.Sqrt((nx - x) * (nx - x) + dy * dy);
            return new Ray() { x = nx, y = ny, mx = mx, my = my, d = nd };
        }
    }

    private List<HSegment>[] SegmentsFacingDown { get; set; }
    private List<HSegment>[] SegmentsFacingUp { get; set; }
    private List<VSegment>[] SegmentsFacingRight { get; set; }
    private List<VSegment>[] SegmentsFacingLeft { get; set; }
    private double InitialX { get; set; }
    private double InitialY { get; set; }

    private Problem4(InputParser input)
    {
        Height = input.GetInt();
        Width = input.GetInt();
        Distance = input.GetInt();
        char[][] hall = input.GetStrings(Height).Select(s => s.ToCharArray()).ToArray();
        SegmentsFacingDown = Enumerable.Range(0, Height - 1).Select(i => new List<HSegment>()).ToArray();
        SegmentsFacingUp = Enumerable.Range(0, Height - 1).Select(i => new List<HSegment>()).ToArray();
        SegmentsFacingRight = Enumerable.Range(0, Width - 1).Select(i => new List<VSegment>()).ToArray();
        SegmentsFacingLeft = Enumerable.Range(0, Width - 1).Select(i => new List<VSegment>()).ToArray();
        for (int h = 0; h < Height; ++h)
        {
            for (int w = 0; w < Width; ++w)
            {
                if (hall[h][w] == '#')
                {
                    if (h != Height - 1 && hall[h + 1][w] != '#')
                    {
                        if (SegmentsFacingDown[h].Count  > 0 && SegmentsFacingDown[h][SegmentsFacingDown[h].Count - 1].right == w - 1)
                        {
                            SegmentsFacingDown[h][SegmentsFacingDown[h].Count - 1].right = w;
                        }
                        else
                        {
                            SegmentsFacingDown[h].Add(new HSegment() { left = w - 1, right = w });
                        }
                    }
                    if (h != 0 && hall[h - 1][w] != '#')
                    {
                        if (SegmentsFacingUp[h - 1].Count > 0 && SegmentsFacingUp[h - 1][SegmentsFacingUp[h - 1].Count - 1].right == w - 1)
                        {
                            SegmentsFacingUp[h - 1][SegmentsFacingUp[h - 1].Count - 1].right = w;
                        }
                        else
                        {
                            SegmentsFacingUp[h - 1].Add(new HSegment() { left = w - 1, right = w });
                        }
                    }
                    if (w != Width - 1 && hall[h][w + 1] != '#')
                    {
                        if (SegmentsFacingRight[w].Count > 0 && SegmentsFacingRight[w][SegmentsFacingRight[w].Count - 1].bottom == h - 1)
                        {
                            SegmentsFacingRight[w][SegmentsFacingRight[w].Count - 1].bottom = h;
                        }
                        else
                        {
                            SegmentsFacingRight[w].Add(new VSegment() { top = h - 1, bottom = h });
                        }
                    }
                    if (w != 0 && hall[h][w - 1] != '#')
                    {
                        if (SegmentsFacingLeft[w - 1].Count > 0 && SegmentsFacingLeft[w - 1][SegmentsFacingLeft[w - 1].Count - 1].bottom == h - 1)
                        {
                            SegmentsFacingLeft[w - 1][SegmentsFacingLeft[w - 1].Count - 1].bottom = h;
                        }
                        else
                        {
                            SegmentsFacingLeft[w - 1].Add(new VSegment() { top = h - 1, bottom = h });
                        }
                    }
                }
                else if (hall[h][w] == 'X')
                {
                    InitialX = w - 0.5;
                    InitialY = h - 0.5;
                }
            }
        }
    }

    private object SolveCase()
    {
        const int MaxD = 50;

        int count = 0;
        if (CheckDirection(0, 1)) ++count;
        if (CheckDirection(0, -1)) ++count;
        if (CheckDirection(1, 0)) ++count;
        if (CheckDirection(-1, 0)) ++count;
        if (CheckDirection(1, 1)) ++count;
        if (CheckDirection(1, -1)) ++count;
        if (CheckDirection(-1, 1)) ++count;
        if (CheckDirection(-1, -1)) ++count;
        for (int i = 1; i < MaxD; ++i)
        {
            for (int j = i + 1; j < MaxD; ++j)
            {
                if (Utils.Gcd(i, j) == 1)
                {
                    if (CheckDirection(i, j)) ++count;
                    if (CheckDirection(-i, j)) ++count;
                    if (CheckDirection(i, -j)) ++count;
                    if (CheckDirection(-i, -j)) ++count;
                    if (CheckDirection(j, i)) ++count;
                    if (CheckDirection(-j, i)) ++count;
                    if (CheckDirection(j, -i)) ++count;
                    if (CheckDirection(-j, -i)) ++count;
                }
            }
        }
        return count;
    }

    private bool CheckDirection(int mx, int my)
    {
        var ray = new Ray() { x = InitialX, y = InitialY, mx = mx, my = my, d = Distance };
        while ((ray = MoveRay(ray)) != null)
        {
            if (HitsGoal(ray))
            {
                //PrintDirection(mx, my);
                return true;
            }
        }
        return false;
    }

    private void PrintDirection(int mx, int my)
    {
        Console.WriteLine("* ({0}, {1}):", mx, my);
        var ray = new Ray() { x = InitialX, y = InitialY, mx = mx, my = my, d = Distance };
        while ((ray = MoveRay(ray)) != null)
        {
            Console.WriteLine(" ==> ({0:0.00}; {1:0.00}) ({2}; {3}) d={4:0.00}", ray.x, ray.y, ray.mx, ray.my, ray.d);
            if (HitsGoal(ray))
            {
                if (ray.mx != 0)
                {
                    ray = ray.MoveInX(InitialX - ray.x);
                }
                else
                {
                    ray = ray.MoveInY(InitialY - ray.y);
                }
                Console.WriteLine(" ==> ({0:0.00}; {1:0.00}) ({2}; {3}) d={4:0.00}", ray.x, ray.y, ray.mx, ray.my, ray.d);
                return;
            }
        }
    }

    private Ray MoveRay(Ray ray)
    {
        HSegment hsegment;
        VSegment vsegment;
        var hray = FindHCollision(ray, out hsegment);
        var vray = FindVCollision(ray, out vsegment);
        if (hray == null && vray == null)
        {
            return null;
        }
        if (hray != null && vray != null)
        {
            // Discard the farthest hit.
            if (!LessOrEqual(hray.d, vray.d))
            {
                vray = null;
            }
            else if (!LessOrEqual(vray.d, hray.d))
            {
                hray = null;
            }
        }
        if (hray != null && vray == null)
        {
            if (Equal(hray.x, hsegment.left) || Equal(hray.x, hsegment.right))
            {
                // We graze a corner and move on.
                return MoveRay(hray);
            }
            else
            {
                // Regular reflection.
                hray.my = -hray.my;
                return hray;
            }
        }
        else if (vray != null && hray == null)
        {
            if (Equal(vray.y, vsegment.top) || Equal(vray.y, vsegment.bottom))
            {
                // We graze a corner and move on.
                return MoveRay(vray);
            }
            else
            {
                // Regular reflection.
                vray.mx = -vray.mx;
                return vray;
            }
        }
        else
        {
            // Both rays are identical and hit a corner. Check which type.
            if (vray.mx > 0 && vray.my < 0 && Equal(vray.x, hsegment.right) && Equal(vray.y, vsegment.top) ||
                vray.mx < 0 && vray.my < 0 && Equal(vray.x, hsegment.left) && Equal(vray.y, vsegment.top) ||
                vray.mx > 0 && vray.my > 0 && Equal(vray.x, hsegment.right) && Equal(vray.y, vsegment.bottom) ||
                vray.mx < 0 && vray.my > 0 && Equal(vray.x, hsegment.left) && Equal(vray.y, vsegment.bottom))
            {
                vray.mx = -vray.mx;
                vray.my = -vray.my;
                return vray;
            }
            else
            {
                // Crashed against a jutting corner. We're done!
                return null;
            }
        }
    }

    private bool HitsGoal(Ray ray)
    {
        if ((ray.mx > 0) != (InitialX > ray.x) || (ray.my > 0) != (InitialY > ray.y))
        {
            // False if the goal is in the wrong direction.
            return false;
        }
        if (!Equal((InitialX - ray.x) * ray.my, (InitialY - ray.y) * ray.mx))
        {
            // Also, if the goal is in the ray of the goal.
            return false;
        }
        double goalDistance = Math.Sqrt((InitialX - ray.x) * (InitialX - ray.x) + (InitialY - ray.y) * (InitialY - ray.y));
        if (!LessOrEqual(goalDistance, ray.d))
        {
            // Also, if we can't reach the goal.
            return false;
        }
        // Finally, check that there's nothing in the way.
        return MoveRay(new Ray() { x = ray.x, y = ray.y, mx = ray.mx, my = ray.my, d = goalDistance }) == null;
    }

    private Ray FindHCollision(Ray ray, out HSegment segment)
    {
        segment = null;
        if (ray.my < 0)
        {
            for (int h = (int)Math.Ceiling(ray.y - 1); h >= 0; --h)
            {
                var nextRay = ray.MoveInY(h - ray.y);
                if (!LessOrEqual(0.0, nextRay.d))
                    return null;
                foreach (var candidate in SegmentsFacingDown[h])
                {
                    if (LessOrEqual(candidate.left, nextRay.x) && LessOrEqual(nextRay.x, candidate.right))
                    {
                        segment = candidate;
                        return nextRay;
                    }
                }
            }
        }
        else if (ray.my > 0)
        {
            for (int h = (int)(ray.y + 1); h < Height - 1; ++h)
            {
                var nextRay = ray.MoveInY(h - ray.y);
                if (!LessOrEqual(0.0, nextRay.d))
                    return null;
                foreach (var candidate in SegmentsFacingUp[h])
                {
                    if (LessOrEqual(candidate.left, nextRay.x) && LessOrEqual(nextRay.x, candidate.right))
                    {
                        segment = candidate;
                        return nextRay;
                    }
                }
            }
        }
        return null;
    }

    private Ray FindVCollision(Ray ray, out VSegment segment)
    {
        segment = null;
        if (ray.mx < 0)
        {
            for (int w = (int)Math.Ceiling(ray.x - 1); w >= 0; --w)
            {
                var nextRay = ray.MoveInX(w - ray.x);
                if (!LessOrEqual(0.0, nextRay.d))
                    return null;
                foreach (var candidate in SegmentsFacingRight[w])
                {
                    if (LessOrEqual(candidate.top, nextRay.y) && LessOrEqual(nextRay.y, candidate.bottom))
                    {
                        segment = candidate;
                        return nextRay;
                    }
                }
            }
        }
        else if (ray.mx > 0)
        {
            for (int w = (int)(ray.x + 1); w < Width - 1; ++w)
            {
                var nextRay = ray.MoveInX(w - ray.x);
                if (!LessOrEqual(0.0, nextRay.d))
                    return null;
                foreach (var candidate in SegmentsFacingLeft[w])
                {
                    if (LessOrEqual(candidate.top, nextRay.y) && LessOrEqual(nextRay.y, candidate.bottom))
                    {
                        segment = candidate;
                        return nextRay;
                    }
                }
            }
        }
        return null;
    }

    private const double Epsilon = 1e-7;
    private static bool LessOrEqual(double a, double b)
    {
        return a <= b + Epsilon;
    }

    private static bool Equal(double a, double b)
    {
        return Math.Abs(a - b) <= Epsilon;
    }

    static void Main(string[] args)
    {
        bool useFile = File.Exists(InputFileName);
        var inputParser = useFile ? new InputParser(InputFileName) : new InputParser();

        TextWriter output;
        if (useFile)
        {
            File.Delete(OutputFileName);
            output = new StreamWriter(File.OpenWrite(OutputFileName));
        }
        else
        {
            output = Console.Out;
        }

        var sw = new Stopwatch();
        sw.Start();
        try
        {
            if (MultipleCases)
            {
                int caseCount = inputParser.GetInt();
                for (int c = 0; c < caseCount; ++c)
                {
                    output.WriteLine(string.Format("Case #{0}: {1}", c + 1, new Problem4(inputParser).SolveCase()));
                }
            }
            else
            {
                output.WriteLine(string.Format("{0}", new Problem4(inputParser).SolveCase()));
            }
        }
        finally
        {
            if (useFile)
            {
                output.Dispose();
            }
        }
        if (useFile)
        {
            Console.WriteLine("Output:");
            Console.Write(File.ReadAllText(OutputFileName));
            Console.WriteLine("Total time: {0} ms", sw.ElapsedMilliseconds);
            Console.ReadLine();
        }
    }
}

public class InputParser
{
    private IEnumerator<string> Elements { get; set; }

    private IEnumerable<string> GetElements(IEnumerable<string> lines)
    {
        // Insert a null element at the end of each line.
        return lines.SelectMany(l => Regex.Split(l, @"\s+").Concat(new string[] { null }));
    }

    private static IEnumerable<string> ReadConsoleLines()
    {
        string line;
        while ((line = Console.ReadLine()) != null)
        {
            yield return line;
        }
    }

    public InputParser()
        : this(ReadConsoleLines())
    {
    }

    public InputParser(string filename)
        : this(File.ReadLines(filename))
    {
    }

    public InputParser(IEnumerable<string> lines)
    {
        Elements = GetElements(lines).GetEnumerator();
    }

    public string GetString()
    {
        if (Elements.MoveNext())
        {
            return string.IsNullOrEmpty(Elements.Current) ? GetString() : Elements.Current;
        }
        else
        {
            throw new Exception("Tried to go past the end of the file");
        }
    }

    public IEnumerable<string> GetStrings(int count)
    {
        for (int i = 0; i < count; i++)
        {
            yield return GetString();
        }
    }

    public string[] GetStringArray(int length)
    {
        return GetStrings(length).ToArray();
    }

    public IEnumerable<string> GetNextLine()
    {
        yield return GetString();
        while (Elements.MoveNext() && Elements.Current != null)
        {
            yield return Elements.Current;
        }
    }

    public int GetInt()
    {
        return int.Parse(GetString());
    }

    public int[] GetIntArray()
    {
        return GetNextLine().Select(i => int.Parse(i)).ToArray();
    }

    public int[] GetIntArray(int length)
    {

        return GetStrings(length).Select(i => int.Parse(i)).ToArray();
    }

    public long GetLong()
    {
        return long.Parse(GetString());
    }

    public long[] GetLongArray()
    {
        return GetNextLine().Select(i => long.Parse(i)).ToArray();
    }

    public long[] GetLongArray(int length)
    {
        return GetStrings(length).Select(i => long.Parse(i)).ToArray();
    }

    public float GetFloat()
    {
        return float.Parse(GetString());
    }

    public float[] GetFloatArray()
    {
        return GetNextLine().Select(i => float.Parse(i)).ToArray();
    }

    public float[] GetFloatArray(int length)
    {
        return GetStrings(length).Select(i => float.Parse(i)).ToArray();
    }

    public double GetDouble()
    {
        return double.Parse(GetString());
    }

    public double[] GetDoubleArray()
    {
        return GetNextLine().Select(i => double.Parse(i)).ToArray();
    }

    public double[] GetDoubleArray(int length)
    {
        return GetStrings(length).Select(i => double.Parse(i)).ToArray();
    }

    public char GetChar()
    {
        return GetString().ToCharArray().Single();
    }

    public char[] GetChars()
    {
        return GetString().ToCharArray();
    }
}

public static class Utils
{
    public static string Join(this IEnumerable<string> strings)
    {
        return strings.Join(string.Empty);
    }

    public static string Join(this IEnumerable<string> strings, char separator)
    {
        return strings.Join(separator.ToString());
    }

    public static string Join(this IEnumerable<string> strings, string separator)
    {
        return string.Join(separator, strings.ToArray());
    }

    public static string Join<T>(this IEnumerable<T> elems)
    {
        return elems.Join(string.Empty);
    }

    public static string Join<T>(this IEnumerable<T> elems, char separator)
    {
        return elems.Join(separator.ToString());
    }

    public static string Join<T>(this IEnumerable<T> elems, string separator)
    {
        return elems.Select(elem => elem.ToString()).Join(separator);
    }

    /// <summary>
    /// Returns the greatest common divisor of two numbers.
    /// </summary>
    /// <param name="a">The first number.</param>
    /// <param name="b">The second number.</param>
    /// <returns>The GCD of both numbers.</returns>
    public static long Gcd(long a, long b)
    {
        if (a < b)
        {
            long temp = a;
            a = b;
            b = temp;
        }
        while (b != 0)
        {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
