using System;

class ARC056 {
    static void Main(string[] args) {
        var spl = Console.ReadLine().Split();
        var A = long.Parse(spl[0]);
        var B = long.Parse(spl[1]);
        var K = long.Parse(spl[2]);
        var L = long.Parse(spl[3]);

        long BN = K / L;
        long AN = K - BN * L;
        var res = Math.Min(BN * B + AN * A, (BN + 1) * B);
        Console.WriteLine(res);
    }
}