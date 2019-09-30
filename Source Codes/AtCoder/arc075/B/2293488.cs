using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC075D {
    class Program {
        static void Main(string[] args) {
            int[] NABinput = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int N = NABinput[0];
            int A = NABinput[1];
            int B = NABinput[2];
            int[] hp = new int[N];
            for (int i = 0; i < N; i++) {
                hp[i] = int.Parse(Console.ReadLine());
            }
            int upper = (hp.Max() + B - 1) / B;
            long max = upper;
            long min = 0;
            bool ok = false;
            long ans = -1;
            while (!ok) {
                if (max - min >= 2) {
                    long now = (max + min) / 2;
                    long rema = 0;
                    for (int i = 0; i < N; i++) {
                        rema += Math.Max(((hp[i] - now * B) + (A - B) - 1) / (A - B), 0);
                    }
                    if (rema <= now) {
                        max = now;
                    } else {
                        min = now;
                    }
                } else {
                    ans = max;
                    ok = true;
                }
            }
            Console.WriteLine(ans);
        }
    }
}