using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder {
    class Program {
        static int X1, X2, X3, Y1, Y2, Y3, R;
        static bool Red, Blue;
        static void Main() {
            Read();
            Shori();
            if (Red) {
                Console.WriteLine("YES");
            }
            else {
                Console.WriteLine("NO");
            }
            if (Blue) {
                Console.WriteLine("YES");
            }
            else {
                Console.WriteLine("NO");
            }
        }
        static void Shori() {
            bool a = true;
           for(int i=X2; i <= X3; i++) {
                for(int j = Y2; j <= Y3; j++) {
                    a = a && R * R > (X1 - i) * (X1 - i) + (Y1 - j) * (Y1 - j);
                }
            }
            if (a) {
                Blue = false;
            }
            else {
                Blue = true;
            }
            bool b = true;
            for(int i = X1 - R; i <= X1 + R; i++) {
                for (int j = Y1 - R; j <= Y1 + R; j++) {
                    if ((X1 - i) * (X1 - i) + (Y1 - j) * (Y1 - j) <= R * R) {
                        b = b && ((X2 <= i && i <= X3) && (Y2 <= j && j <= Y3));
                    }
                }
            }
            if (b) {
                Red = false;
            }
            else {
                Red = true;
            }
        }

        static void Read() {
            string s = Console.ReadLine();
            X1 = int.Parse(s.Split(' ')[0]);
            Y1 = int.Parse(s.Split(' ')[1]);
            R = int.Parse(s.Split(' ')[2]);
            s = Console.ReadLine();
            X2 = int.Parse(s.Split(' ')[0]);
            Y2 = int.Parse(s.Split(' ')[1]);
            X3 = int.Parse(s.Split(' ')[2]);
            Y3 = int.Parse(s.Split(' ')[3]);
        }
        
    }
}