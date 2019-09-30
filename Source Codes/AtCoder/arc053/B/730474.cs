using System;
class A{
	static void Main (){
		var s = Console.ReadLine();
		var d = new System.Collections.Generic.Dictionary<char,int>();
		foreach(char c in s)
			d[c] = d.ContainsKey(c) ? d[c]+1 : 1;
		int a = 0, b = 0;
		foreach(var kvp in d) {
			a += (kvp.Value / 2);
			if(kvp.Value % 2 == 1) b++; 
		}
		Console.WriteLine((b != 0) ? ( a / b ) * 2  + 1 : a * 2 );
	}
}