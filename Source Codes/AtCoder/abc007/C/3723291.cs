using System;
using System.Linq;
using System.Collections.Generic;
using System.Collections;
public class Program {
  public static int R, C;
  public static Point start, goal;
  public static int[][] map;

  public static void Main() {
    int[] line1 = ReadIntArray();
    R = line1[0];
    C = line1[1];
    start = new Point(ReadIntArray().Select(i => --i).ToArray());
    goal = new Point(ReadIntArray().Select(i => --i).ToArray());
    map = new int[R][];
    for (int i = 0; i < R; i++) {
      map[i] = ReadCharStringArray().Select(s => s.Replace("#", "-1")).Select(s => s.Replace(".", "100000")).Select(int.Parse).ToArray();
    }
    BFS();
    Console.WriteLine(map[goal.X][goal.Y]);
  }

  public static void BFS() {
    int[] xM = { 1, 0, -1 , 0 };
    int[] yM = { 0, -1, 0, 1 };

    Queue<Point> queue = new Queue<Point>();
    queue.Enqueue(start);
    map[start.X][start.Y] = 0;
    while (queue.Count > 0) {
      Point current = queue.Dequeue();
      int d = map[current.X][current.Y] + 1;
      for (int i = 0; i < 4; i++) {
        int x = current.X + xM[i], y = current.Y + yM[i];
        if (map[x][y] > d) {
          map[x][y] = d;
          queue.Enqueue(new Point(x, y));
        }
      }
    }
  }

  private static int GCD(int a, int b) { if (a < b) { Swap(ref a, ref b); } int mod = a % b, div = b, temp; while (mod != 0) { temp = mod; mod = div % mod; div = temp; } return div; }
  private static int LCM(int a, int b) { return a*b/GCD(a, b); }
  private static int[] Complement(int[] A, int a, int b) { int[] notA = new int[(b-a+1) - A.Length]; for (int i = a, j = 0; i <= b; i++) { if (!A.Contains(i)) { notA[j] = i; j++; } } return notA; }
  private static void Swap<T>(ref T a, ref T b) { T temp = a; a = b; b = temp; }
  private static int ReadInt() { return int.Parse(Console.ReadLine()); }
  private static double ReadDouble() { return double.Parse(Console.ReadLine()); }
  private static long ReadLong() { return long.Parse(Console.ReadLine()); }
  private static char ReadChar() { return Console.ReadLine()[0]; }
  private static string[] ReadStringArray() { return Console.ReadLine().Split(' '); }
  private static int[] ReadIntArray() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
  private static double[] ReadDoubleArray() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
  private static long[] ReadLongArray() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
  private static char[] ReadCharArray() { return Console.ReadLine().ToCharArray(); }
  private static string[] ReadCharStringArray() { return Console.ReadLine().ToCharArray().Select(c => c.ToString()).ToArray(); }
  private static void WriteArraySingleLine(Object[] array, string split) { Console.WriteLine(string.Join(split, array)); }
  private static void WriteArrayMultiLine(Object[] array) { Console.WriteLine(string.Join(Environment.NewLine, array)); }
  private static void WriteYesNo(bool b) { Console.WriteLine((b) ? "Yes" : "No"); }
}

public class Point {
  public int X;
  public int Y;
  public Point(int X, int Y) { this.X = X; this.Y = Y; }
  public Point(int[] XY) { this.X = XY[0]; this.Y = XY[1]; }
  public double EuclideanDistance(Point point) { return EuclideanDistance(this, point); }
  public double ManhattanDistance(Point point) { return ManhattanDistance(this, point); }
  public double ChebyshevDistance(Point point) { return ChebyshevDistance(this, point); }
  public Point Clone() { return new Point(this.X, this.Y); }
  public static double EuclideanDistance(Point point1, Point point2) { return Math.Sqrt(Math.Pow(point1.X - point2.X, 2) + Math.Pow(point1.Y - point2.Y, 2)); }
  public static double ManhattanDistance(Point point1, Point point2) { return Math.Abs(point1.X - point2.X) + Math.Abs(point1.Y - point2.Y); }
  public static double ChebyshevDistance(Point point1, Point point2) { return Math.Max(Math.Abs(point1.X - point2.X), Math.Abs(point1.Y - point2.Y)); }
}