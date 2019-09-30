using System;
using System.Collections.Generic;
using System.Linq;

struct Magic {
	public long u { get; set; }
	public long d { get; set; }
}

class Program {
	static void Main(string[] args) {
		int n = int.Parse(Console.ReadLine());
		List<Magic> m = new List<Magic>();
		List<Magic> up = new List<Magic>();
		List<Magic> down = new List<Magic>();
		for(int i = 0; i < n; i++) {
			var s = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
			if(s[0] < s[1]) {
				down.Add(new Magic() { u = s[0], d = s[1] });
			}else {
				up.Add(new Magic() { u = s[0],d = s[1] });
			}
		}
		down.Sort((x, y) => (int)(x.u - y.u));
		up.Sort((x, y) => (int)(y.d - x.d));
		m.AddRange(down);
		m.AddRange(up);
		long ans  = 0, t = 0;
		foreach(var i in m) {
			t += i.u;
			ans = Math.Max(ans, t);
			t -= i.d;
		}
		Console.WriteLine(ans);
	}
}