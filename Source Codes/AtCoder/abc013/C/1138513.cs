using System;
using System.Collections.Generic;
public class Aprob {
    public static void Main() {
        string[] readSome = new string[2];
        readSome = Console.ReadLine().Split(' ');
        long N = long.Parse(readSome[0]);
        long H = long.Parse(readSome[1]);
        readSome = new string[5];
        readSome = Console.ReadLine().Split(' ');
        long A = long.Parse(readSome[0]);
        long B = long.Parse(readSome[1]);
        long C = long.Parse(readSome[2]);
        long D = long.Parse(readSome[3]);
        long E = long.Parse(readSome[4]);
        long Y;
        long cost;
        long min=A*N;
        for (long X = N; X >= 0; X--) {
            if (H + X * B - (N - X) * E > 0) {
                Y = 0;
            } else {
                Y = (((N - X) * E - H - B * X) / (D + E)) + 1;
            }
            cost = A * X + C * Y;
            min = Math.Min(cost, min);
        }
        Console.WriteLine(min);
    }
}