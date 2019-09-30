using System;
using System.Collections.Generic;

public class CSharp{
    public static void Main(){
        Kyopuro chokudai = new Kyopuro();
	    chokudai.AtCoder();
	}
}

public class Kyopuro{
    List<int>[] list;
    bool[] v;
    bool f;
    List<int> ans1;
    List<int> ans2;
    
    public void AtCoder(){
        string[] s;
		s = Console.ReadLine().Split(' ');
		
		int n, m;
		n = int.Parse(s[0]);
		m = int.Parse(s[1]);
		
		int[] a = new int[m];
		int[] b = new int[m];
		for (int i = 0; i < m; i++){
		    s = Console.ReadLine().Split(' ');
		    a[i] = int.Parse(s[0]) - 1;
		    b[i] = int.Parse(s[1]) - 1;
		}
		
		list = new List<int>[n];
		for (int i = 0; i < n; i++) list[i] = new List<int>();
		for (int i = 0; i < m; i++){
		    list[a[i]].Add(b[i]);
		    list[b[i]].Add(a[i]);
		}
		
		ans1 = new List<int>();
		ans2 = new List<int>();
		ans1.Add(0);
		v = new bool[n];
		f = false;
		v[0] = true;
		v[list[0][0]] = true;
		Dfs1(list[0][0]);
		f = false;
		Dfs2(0);
		Console.WriteLine(ans1.Count+ans2.Count);
		foreach(int p in ans2) Console.Write(p+1+" ");
		foreach(int p in ans1) Console.Write(p+1+" ");
		Console.WriteLine();
    }
    void Dfs1(int x){
        ans1.Add(x);
        foreach(int p in list[x]){
            if(!v[p]){
                v[p] = true;
                Dfs1(p);
            }
            if(f) return;
        }
        f = true;
    }
    void Dfs2(int x){
        foreach(int p in list[x]){
            if(!v[p]){
                v[p] = true;
                Dfs2(p);
            }
            if(f){
                ans2.Add(p);
                return;
            }
        }
        f = true;
    }
    
    public static void DebugWL(object x){ System.Diagnostics.Debug.WriteLine(x); }
}