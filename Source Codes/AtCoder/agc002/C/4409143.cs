using System;

public class AtCoder{
	public static void Main(){
		string[] s;
		s = NextS();
		
		int n, l;
		n = int.Parse(s[0]);
		l = int.Parse(s[1]);
		s = NextS();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) a[i] = int.Parse(s[i]);
		
		int ans = -1;
		for(int i=0; i<n-1; i++) if(a[i] + a[i+1] >= l) ans = i;
		if(ans > -1) Console.WriteLine("Possible");
		else{
		    Console.WriteLine("Impossible");
		    return;
		}
		int c = 0;
		while(c != ans){
		    Console.WriteLine(c + 1);
		    c++;
		}
		c = n-2;
		while(c != ans){
		    Console.WriteLine(c + 1);
		    c--;
		}
		Console.WriteLine(ans + 1);
	}

	public static void DebugWL(object x){ System.Diagnostics.Debug.WriteLine(x); }
	public static string[] NextS(){ return Console.ReadLine().Trim().Split(' '); }
}