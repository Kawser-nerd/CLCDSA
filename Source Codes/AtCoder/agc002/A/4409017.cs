using System;

public class AtCoder{
	public static void Main(){
		string[] s;
		s = NextS();
		
		int n, m;
		n = int.Parse(s[0]);
		m = int.Parse(s[1]);
		long a = n;
		long b = m;
		if(a > b){
		    b = n;
		    a = m;
		}
		if(a * b <= 0) Console.WriteLine("Zero");
		else{
		    if(a>0 || (b-a)%2 == 1) Console.WriteLine("Positive");
		    else Console.WriteLine("Negative");
		}
	}

	public static void DebugWL(object x){ System.Diagnostics.Debug.WriteLine(x); }
	public static string[] NextS(){ return Console.ReadLine().Trim().Split(' '); }
}