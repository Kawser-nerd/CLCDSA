using System;
using System.Collections.Generic;

public class AtCoder{
	public static void Main(){
	    
	    Tree tree = new Tree();
	    Console.WriteLine(tree.Calc(1));
	}

	public static void DebugWL(object x){ System.Diagnostics.Debug.WriteLine(x); }
}

class Tree{
    
    int n;
    int[] a;
    List<int>[] list;
    List<int>[] m;
    
    public Tree() {
        n = int.Parse(Console.ReadLine());
	    a = new int[n+1];
	    for(int i=2; i<=n; i++){
	        a[i] = int.Parse(Console.ReadLine());
	    }
	    
	    list = new List<int>[n+1];
	    m = new List<int>[n+1];
	    for(int i=1; i<=n; i++){
	        list[i] = new List<int>();
	        m[i] = new List<int>();
	    }
	    for(int i=2; i<=n; i++){
	        list[a[i]].Add(i);
	    }
    }
    
    public int Calc(int x){
        int c = 0;
        int max = -1;
        foreach(int i in list[x]){
            m[x].Add(Calc(i));
            c++;
        }
        m[x].Sort();
        for(int i=0; i<c; i++){
            m[x][i] += c - 1 - i;
            if(m[x][i]>max) max = m[x][i];
        }
        if(c==0) return 0;
        else return max + 1;
    }
}