using System;

public class AtCoder{
	public static void Main(){
		string[] s;
		s = NextS();
		
		long n, x;
		n = long.Parse(s[0]);
		x = long.Parse(s[1]);
		
		long ans = n;
		long a = x;
		long b = n - x;
		long tmp = 0;
		
		while(true){
		    if(b%a==0){
		        ans += b * 2 - a;
		        break;
		    } else {
		        ans += (b - b%a)*2;
		        b = b%a;
		        tmp = a; a = b; b = tmp;
		    }
		}
		
		Console.WriteLine(ans);
	}

	public static void DebugWL(object x){ System.Diagnostics.Debug.WriteLine(x); }
	public static string[] NextS(){ return Console.ReadLine().Trim().Split(' '); }
}