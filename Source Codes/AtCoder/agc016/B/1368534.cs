using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.AGC016
{
    class ColorfulHat
    {
        public static void Main()
        {
            var yes = "Yes";
            var no = "No";
            var n = int.Parse(ReadLine());
            var testinomial = ReadLine().Trim().Split(' ').Select(_ => int.Parse(_));
            var suspect = testinomial.Distinct().OrderBy(_ => _).ToArray();
            if (suspect.Length > 2) WriteLine(no);
            else if (suspect.Length == 2 && ((suspect[0] + 1) != suspect[1])) WriteLine(no);
            else {
                var smaller = new Color(suspect[0], n);
                var bigger = new Color(suspect[0] + 1, n);
                foreach (var t in testinomial) {
                    if (smaller == t) {
                        smaller.Many++;
                        bigger.Single++;
                    }
                    else {
                        bigger.Many++;
                    }
                }
                if (smaller.IsNotParadoxical() || bigger.IsNotParadoxical()) WriteLine(yes);
                else WriteLine(no);
            }
        }
        struct Color
        {
            int ColorNum;
            int Num;
            public int Single, Many;
            public Color(int color, int n)
            {
                ColorNum = color;
                Num = n;
                Single = Many = 0;
            }
            public static implicit operator int(Color c)
            {
                return c.ColorNum;
            }
            public bool IsNotParadoxical()
            {
                return Num == Single + Many && ColorNum >= Single + ((Many == 0) ? 0 : 1) && ColorNum <= Single + Many / 2;
            }
        }


    }
}