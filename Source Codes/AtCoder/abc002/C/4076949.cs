using System;

class Program
{
  /// <summary>
  ///   The main entry point for the application
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    string[] inputs = Console.ReadLine().Split(' ');
    double x = double.Parse(inputs[0]);
    double y = double.Parse(inputs[1]);
    double a = double.Parse(inputs[2]);
    double b = double.Parse(inputs[3]);
    double c = double.Parse(inputs[4]);
    double d = double.Parse(inputs[5]);
    a -= x; b -= y; c -= x; d -= y;
    Console.WriteLine((((Math.Max(a * d, b * c)) - Math.Min(a * d, b * c)) / 2).ToString("f1"));
  }
}