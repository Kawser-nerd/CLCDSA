using System;
using System.Linq;
using System.Collections.Generic;
class A{
	public static void Main (){
		var s = Console.ReadLine();
		var d = new Dictionary<char,int>();
		foreach(char c in s) {
			if(d.ContainsKey(c)) {
				d[c]++;
			}else{
				d[c] = 1;
			}
		}
		int cnt = 0;
		int cnt2 = 0;
		foreach(KeyValuePair<char, int> kvp in d) {
			cnt += (kvp.Value / 2);
			if(kvp.Value % 2 == 1)cnt2++; 
		}
		if(cnt2 != 0) {
			Console.WriteLine(( cnt / cnt2 ) * 2  + 1);
		} else {
			Console.WriteLine(cnt * 2);
		} 
	}
}