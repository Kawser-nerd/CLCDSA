using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Math;

class Doit {
    static IEnumerable<int> rep(int a, int b) {
        return Enumerable.Range(a, b);
    }
    
    static void Main() {
	var n = int.Parse(ReadLine());

	long x = 1;
	long y = 1;

	foreach (var i in rep(0, n)) {
	    var l = ReadLine().Split();
	    var t = long.Parse(l[0]);
	    var a = long.Parse(l[1]);

	    var m = Max((x - 1) / t, (y - 1) / a) + 1;
	    x = m * t;
	    y = m * a;
	}

	WriteLine("{0}", x + y);
    }
}