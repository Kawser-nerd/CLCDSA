using System;
using System.Linq;
public class Aprob {
    public static void Main() {
        string[] readSome = new string[2];
        readSome = Console.ReadLine().Split(' ');
        int h = int.Parse(readSome[0]);
        int m = int.Parse(readSome[1]);
        float shortA = h * 30 + (float)m * 0.5f;
        shortA %= 360;
        float longA = m * 6;
        float degree = Math.Abs(shortA - longA);
        Console.WriteLine(Math.Min(degree,360-degree));
        Console.ReadLine();
    }
}