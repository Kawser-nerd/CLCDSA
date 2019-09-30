using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC074C {
    class Program {
        static void Main(string[] args) {
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int H = input[0];
            int W = input[1];
            int across = (H % 3 == 0) ? 0 : W;
            int down = (W % 3 == 0) ? 0 : H;
            int Hdiv = H / 3;
            int leftdown = (H - Hdiv) * (W / 2);
            int rightdown = (H - Hdiv) * ((W + 1) / 2);
            int[] acrdow1set = { Hdiv * W, leftdown, rightdown };
            int acrdow1 = acrdow1set.Max() - acrdow1set.Min();
            int[] acrdow2set = { (Hdiv + 1) * W, leftdown - (W / 2), rightdown - ((W + 1) / 2) };
            int acrdow2 = acrdow1set.Max() - acrdow2set.Min();
            int Wdiv = W / 3;
            int upright = (W - Wdiv) * (H / 2);
            int downright = (W - Wdiv) * ((H + 1) / 2);
            int[] dowacr1set = { Wdiv * H, upright, downright };
            int dowacr1 = dowacr1set.Max() - dowacr1set.Min();
            int[] dowacr2set = { (Wdiv + 1) * H, upright - (H / 2), downright - ((H + 1) / 2) };
            int dowacr2 = dowacr2set.Max() - dowacr2set.Min();
            int ans = (new int[] { across, down, acrdow1, acrdow2, dowacr1, dowacr2 }).Min();
            Console.WriteLine(ans);
        }
    }
}