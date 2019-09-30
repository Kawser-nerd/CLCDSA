using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC080D {
    class Program {
        static void Main(string[] args) {
            int[] HWinput = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int H = HWinput[0];
            int W = HWinput[1];
            int N = int.Parse(Console.ReadLine());
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int nownum = 1;
            int dir = 1;
            int nownumcount = 0;
            for (int i = 0; i < H; i++) {
                string str = "";
                for (int j = 0; j < W; j++) {
                    if(dir == 1) {
                        str += nownum.ToString() + " ";
                    } else {
                        str = nownum.ToString() + " " + str;
                    }
                    nownumcount++;
                    if (nownumcount == input[nownum - 1]) {
                        nownum++;
                        nownumcount = 0;
                    }
                }
                Console.WriteLine(str);
                dir = (dir + 1) % 2;
            }
        }
    }
}