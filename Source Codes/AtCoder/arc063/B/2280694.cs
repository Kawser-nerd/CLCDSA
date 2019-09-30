using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC063D {
    class Program {
        static void Main(string[] args) {
            int[] NTinput = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int N = NTinput[0];
            int T = NTinput[1];
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int min = 1000000009;
            int num = 0;
            int nowprofit = 0;
            for (int i = 0; i < N; i++) {
                if (input[i] < min) {
                    min = input[i];
                }
                int dif = input[i] - min;
                if (dif > nowprofit) {
                    nowprofit = dif;
                    num = 1;
                } else if (dif == nowprofit) {
                    num++;
                }
            }
            Console.WriteLine(num);
        }
    }
}