using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class D
{
    public static void Main()
    {
        int T = ReadInt();
        for (int t = 1; t <= T; t++)
        {
            Console.WriteLine("Case #{0}: {1}", t, DoTest());
        }
    }

    static int DoTest()
    {
        int[] hwd = ReadInts();
        int H = hwd[0], W = hwd[1], D = hwd[2];
        int x = -1, y = -1;
        string[] grid = new string[H];
        for (int i = 0; i < H; i++)
        {
            grid[i] = ReadLine();
            int idx = grid[i].IndexOf('X');
            if (idx >= 0)
            {
                x = idx;
                y = i;
            }
        }
        return GetAllDirections(D).Count(dir => IsValid(dir, grid, x, y, D));
    }

    private static bool IsValid(Tuple<int, int> dir, string[] grid, int x, int y, long maxD)
    {
        int d = 0;
        int M = dir.Item1 * dir.Item2 * 2;
        if (dir.Item1 == 0)
            M = dir.Item2 * 2;
        if (dir.Item2 == 0)
            M = dir.Item1 * 2;
        M = Math.Abs(M);
        maxD *= M;
        maxD = (maxD * maxD) / (dir.Item1 * dir.Item1 + dir.Item2 * dir.Item2);
        int targetX = x = x * M + M / 2;
        int targetY = y = y * M + M / 2;
        while (true)
        {
            // Find number of dir units to travel
            int travel = 0;
            if (dir.Item1 == 0)
            {
                int ty = y % M;
                if (dir.Item2 < 0) travel = (ty == 0 ? M : ty) / Math.Abs(dir.Item2);
                else travel = (M - ty) / dir.Item2;
            }
            else if (dir.Item2 == 0)
            {
                int tx = x % M;
                if (dir.Item1 < 0) travel = (tx == 0 ? M : tx) / Math.Abs(dir.Item1);
                else travel = (M - tx) / dir.Item1;
            }
            else
            {
                int tmp1, tmp2;
                int ty = y % M;
                if (dir.Item2 < 0) tmp1 = (ty == 0 ? M : ty) / Math.Abs(dir.Item2);
                else tmp1 = (M - ty) / dir.Item2;

                int tx = x % M;
                if (dir.Item1 < 0) tmp2 = (tx == 0 ? M : tx) / Math.Abs(dir.Item1);
                else tmp2 = (M - tx) / dir.Item1;

                travel = Math.Min(tmp1, tmp2);
            }

            // Update position
            x += travel * dir.Item1;
            y += travel * dir.Item2;
            d += travel;

            if (x < 0 || y < 0)
                return false; // Out of bounds

            if (d * d >= maxD)
                return false; // Gone too far

            int X, Y;

            // Check if we hit any mirrors, if so update direction
            bool xedge = x % M == 0, yedge = y % M == 0;
            if (xedge && yedge)
            {
                X = x / M;
                Y = y / M;
                if (dir.Item1 < 0) X--;
                if (dir.Item2 < 0) Y--;

                int X2 = dir.Item1 < 0 ? X + 1 : X - 1;
                int Y2 = dir.Item2 < 0 ? Y + 1 : Y - 1;

                if (X < 0 || Y < 0 || Y >= grid.Length || X >= grid[0].Length)
                    return false; // Left the grid

                if (grid[Y][X] == '#')
                {
                    // Hit the corner of a mirror, so either change direction or stop
                    if (grid[Y][X2] == '#' && grid[Y2][X] == '#')
                    {
                        dir = new Tuple<int, int>(-dir.Item1, -dir.Item2);
                    }
                    else if (grid[Y][X2] == '#')
                    {
                        dir = new Tuple<int, int>(dir.Item1, -dir.Item2);
                    }
                    else if (grid[Y2][X] == '#')
                    {
                        dir = new Tuple<int, int>(-dir.Item1, dir.Item2);
                    }
                    else // This is the or stop part
                    {
                        return false;
                    }
                }
            }
            else if (xedge)
            {
                X = x / M;
                Y = y / M;
                if (dir.Item1 < 0) X--;
                int X2 = dir.Item1 < 0 ? X + 1 : X - 1;

                if (X < 0 || Y < 0 || Y >= grid.Length || X >= grid[0].Length)
                    return false; // Left the grid

                if (grid[Y][X] == '#')
                {
                    dir = new Tuple<int, int>(-dir.Item1, dir.Item2);
                }
            }
            else if (yedge)
            {
                X = x / M;
                Y = y / M;
                if (dir.Item2 < 0) Y--;
                int Y2 = dir.Item2 < 0 ? Y + 1 : Y - 1;

                if (X < 0 || Y < 0 || Y >= grid.Length || X >= grid[0].Length)
                    return false; // Left the grid

                if (grid[Y][X] == '#')
                {
                    dir = new Tuple<int, int>(dir.Item1, -dir.Item2);
                }
            }
            else
            {
                throw new ApplicationException("Something went wrong...");
            }

            // Check if the next square we're entering is the target square, if so, check if we'll hit the target.
            X = x / M;
            Y = y / M;
            if (xedge && dir.Item1 < 0) X--;
            if (yedge && dir.Item2 < 0) Y--;

            if (X < 0 || Y < 0 || Y >= grid.Length || X >= grid[0].Length)
                return false; // Left the grid

            if (grid[Y][X] == 'X')
            {
                int tx = targetX - x, ty = targetY - y;
                if (dir.Item1 == 0 || dir.Item2 == 0)
                {
                    d += dir.Item1 == 0 ? ty / dir.Item2 : tx / dir.Item1;
                    return d * d <= maxD;
                }
                else if (tx / dir.Item1 == ty / dir.Item2)
                {
                    d += dir.Item1 == 0 ? ty / dir.Item2 : tx / dir.Item1;
                    return d * d <= maxD;
                }
            }
        }
    }

    static IEnumerable<Tuple<int, int>> GetAllDirections(int d)
    {
        foreach (var dir in GetDirections(d))
        {
            yield return new Tuple<int, int>(dir.Item1, dir.Item2);
            if (dir.Item2 != 0)
                yield return new Tuple<int, int>(dir.Item1, -dir.Item2);
            if (dir.Item1 != 0)
            {
                yield return new Tuple<int, int>(-dir.Item1, dir.Item2);
                if (dir.Item2 != 0)
                    yield return new Tuple<int, int>(-dir.Item1, -dir.Item2);
            }
        }
    }

    static IEnumerable<Tuple<int, int>> GetDirections(int d)
    {
        Tuple<int, int> first = new Tuple<int, int>(0, 1), last = new Tuple<int, int>(1, 0);
        yield return first;
        foreach (var dir in GetDirections(d, first, last))
            yield return dir;
        yield return last;
    }

    static IEnumerable<Tuple<int, int>> GetDirections(int d, Tuple<int, int> first, Tuple<int, int> last)
    {
        Tuple<int, int> mid = new Tuple<int, int>(first.Item1 + last.Item1, first.Item2 + last.Item2);
        if (mid.Item1 * mid.Item1 + mid.Item2 * mid.Item2 > d * d)
            yield break;
        foreach (var dir in GetDirections(d, first, mid))
            yield return dir;
        yield return mid;
        foreach (var dir in GetDirections(d, mid, last))
            yield return dir;
    }

    #region Library

    static string ReadLine()
    {
        return Console.ReadLine();
    }

    static string[] ReadWords()
    {
        return ReadLine().Split();
    }

    static int ReadInt()
    {
        return int.Parse(ReadLine());
    }

    static int[] ReadInts()
    {
        return Array.ConvertAll(ReadWords(), int.Parse);
    }

    #endregion
}
