using System;

public class AtCoder{
	public static void Main(){
		string[] s;
		s = NextS();
		
		int n, m;
		n = int.Parse(s[0]);
		m = int.Parse(s[1]);
		 
		int[] num = new int[n];
		bool[] red = new bool[n];
		red[0] = true;
		for (int i = 0; i < n; i++) num[i] = 1;
		int[] x = new int[m];
		int[] y = new int[m];
		for (int i = 0; i < m; i++){
		    s = NextS();
		    x[i] = int.Parse(s[0]) - 1;
		    y[i] = int.Parse(s[1]) - 1;
		}
		
		for (int i = 0; i < m; i++){
		    if(red[x[i]]) red[y[i]] = true;
		    num[y[i]]++;
		    num[x[i]]--;
		    if(num[x[i]] == 0) red[x[i]] = false;
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
		    if(red[i]) ans++;
		}
		
		
		
		Console.WriteLine(ans);
	}

	public static void DebugWL(object x){ System.Diagnostics.Debug.WriteLine(x); }
	public static string[] NextS(){ return Console.ReadLine().Trim().Split(' '); }
}