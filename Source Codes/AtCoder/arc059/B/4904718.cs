using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Linq;
using static System.Math;

class Program{
	static string s;

	static void Main(){
		s = Console.ReadLine();
		for (int i = 0;i < s.Length - 1;i++){
			if (s[i] == s[i + 1]){
				Console.WriteLine("{0} {1}",i + 1,i + 2);
				return;
			}
			if (i != s.Length - 2 && s[i] == s[i + 2]){
				Console.WriteLine("{0} {1}",i + 1,i + 3);
				return;
			}
		}
		Console.WriteLine("-1 -1");
	}
}