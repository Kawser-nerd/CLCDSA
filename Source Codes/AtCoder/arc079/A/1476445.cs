using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC079
{
    class CatSnukeAndAVoyage
    {
        public static void Main()
        {
            var nm = ReadLine().Trim().Split(' ').Select(_ => int.Parse(_));
            var n = nm.First(); var m = nm.Last();
            var lands = new int[n];
            foreach(var bridge in (new int[m]).Select(_ => ReadLine().Trim().Split(' ').Select(s => int.Parse(s)).OrderBy(num => num))) {
                if (bridge.First() == 1) lands[bridge.Last()] += 1;
                if (bridge.Last() == n) lands[bridge.First()] += n;
            }
            var possible = "POSSIBLE";
            var impossible = "IMPOSSIBLE";
            if (lands.Any(_ => _ == n + 1)) WriteLine(possible);
            else WriteLine(impossible);
        }

    }
}