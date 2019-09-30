using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC083
{
    class SugarWater
    {
        public static void Main()
        {
            var param = ReadLine().Trim().Split(' ').Select(_ => int.Parse(_)).ToArray();
            var a = param[0]; var b = param[1]; var c = param[2]; var d = param[3]; var e = param[4]; var f = param[5];
            var beaker = CalDensity(a, b, c, d, e, f);
            WriteLine($"{beaker.Weight} {beaker.Sugar}");
        }
        static Beaker CalDensity(int A, int B, int C, int D, int E, int F)
        {
            var best = new Beaker();
            for (var beaker = new Beaker(); beaker.Weight <= F; beaker = beaker.AddWater(A)) {
                for (var water = beaker; water.Weight <= F; water = water.AddWater(B)) {
                    for (var sugar = water; sugar.Weight <= F && sugar.Percentage <= E; sugar = sugar.AddSugar(C)) {
                        for (var last = sugar; last.Weight <= F && last.Percentage <= E; last = last.AddSugar(D)) {
                            best = best.ChoiceBetter(last);
                        }
                    }
                }
            }
            return best;
        }
        class Beaker
        {
            public Beaker() { Water = 0; Sugar = 0; }
            private  Beaker(int w, int s) { Water = w; Sugar = s; }
            public int Water { get; private set; }
            public int Sugar { get; private set; }
            public int Weight { get { return Water + Sugar; } }
            public Beaker AddWater(int n)
            {
                return new Beaker(Water + 100 * n, Sugar);
            }
            public Beaker AddSugar(int n)
            {
                return new Beaker(Water, Sugar + n);
            }
            public int Percentage
            {
                get { return (Water == 0) ? 100 : (Sugar + Water / 100 - 1) / (Water / 100); }
            }
            public Beaker ChoiceBetter(Beaker other)
            {
                return (other.Water == 0 || other.Water * this.Sugar > other.Sugar * this.Water) ? this : other;
            }
        }
    }
}