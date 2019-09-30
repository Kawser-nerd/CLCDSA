using System;

namespace ABC001C {
    class Program {
        static void Main(string[] args) {
            var s = Console.ReadLine();
            Program.Main1(s);
            //for (double i = 0.0; i < 2000.0; i += 1.0) {
            //    Console.Write($"{i}:{i / 60.0:0.00}:{Math.Round(i / 60.0, 1, MidpointRounding.AwayFromZero)} ");
            //    Program.Main1($"0 {i}");
            //}

        }


        static void Main1(string a1) {
            var s = a1;
            var ss = s.Split();
            var deg = int.Parse(ss[0]);
            var degs = string.Empty;


            var b = ((deg * 10 + 1125) / 2250) % 16;

            string[] a = { "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW" };

            degs = a[b];

            var dis = double.Parse(ss[1]);
            dis = Math.Round(dis / 60.0, 1, MidpointRounding.AwayFromZero);
            //Console.WriteLine(dis);

            double[] val = new double[] { 0.25 , 1.55, 3.35, 5.45, 7.95, 10.75, 13.85, 17.15, 20.75, 24.45, 28.45, 32.65, double.MaxValue};

            var diss = 0;
            int i;

            for(i = 0;i < val.Length; i++) {
                if (dis >= val[i]) {
                    diss = i+1;
                }
            }
            if(diss == 0) { degs = "C"; }
            //Console.WriteLine(dis);

            Console.WriteLine($"{degs} {diss}");
        }
    }
}