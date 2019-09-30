using System;

public class AtCoder{
	public static void Main(){
		string[] s;
		s = NextS();
		
		int n;
		n = int.Parse(s[0]);
		
		int[] L = new int[n*2];
		s = NextS();
		for(int i=0; i<n*2; i++){
		    L[i] = int.Parse(s[i]);
		}
		
		Array.Sort(L);
		 
		int ans = 0;
		for(int i=0; i<n*2; i = i+2){
		    ans += L[i];
		}
		
		Console.WriteLine(ans);
	}

	public static void DebugWL(object x){ System.Diagnostics.Debug.WriteLine(x); }
	public static string[] NextS(){ return Console.ReadLine().Trim().Split(' '); }
}