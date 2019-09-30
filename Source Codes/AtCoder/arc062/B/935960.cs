using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Math;

class Doit {
    static IEnumerable<int> rep(int a, int b) {
        return Enumerable.Range(a, b);
    }
    
    static void Main() {
	var s = ReadLine();

	var n = (from x in s
		 where x == 'p'
		 select x).Count();

	WriteLine("{0}", (s.Count() / 2) - n);
    }
}