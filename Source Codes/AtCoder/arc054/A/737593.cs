using System;

class Program {

    static double L, X, Y, S, D;
    static double ans;
    static void Main() {
        
        Read();
        ans = Math.Min(Migi(), Hidari());
        Console.WriteLine(ans);
    }
    static double Migi() {
        if (D >= S) {
            return (D - S) / (X + Y);
        }
        else {
            return (L - (S - D)) / (X + Y);
        }
    }
    static double Hidari() {
        double Kyori;
        if (S > D) {
            Kyori = S - D;
        }
        else {
            Kyori = L - (D - S);
        }
        if (X == Y) {
            return 9999999999;
        }
        if ((Kyori / (Y - X)) < 0) {
            return (Migi());
        }
        else {
            return (Kyori / (Y - X));
        }
    }
    static void Read() {
        string s = Console.ReadLine();
        L = int.Parse(s.Split(' ')[0]);
        X = int.Parse(s.Split(' ')[1]);
        Y = int.Parse(s.Split(' ')[2]);
        S = int.Parse(s.Split(' ')[3]);
        D = int.Parse(s.Split(' ')[4]);
    }
}