using System;
using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var dic = new Dictionary<string, int>();
		var N = NextInt();

		for (var i = 0; i < N; i++) {
			var s = ReadLine();
			if (dic.ContainsKey(s)) {
				dic[s]++;
			} else {
				dic[s] = 1;
			}
		}

		var M = NextInt();
		for (var j = 0; j < M; j++) {
			var t = ReadLine();
			if (dic.ContainsKey(t)) {
				dic[t]--;
			}
		}

		var ans = 0;
		foreach (var val in dic.Values) {
			ans = Math.Max(ans, val);
		}

		WriteLine(ans);
	}

	static int NextInt() {
		return int.Parse(ReadLine());
	}
}