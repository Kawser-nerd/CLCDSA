using System;
using System.Collections.Generic;

public class CSharp{
    public static void Main(){
        Kyopuro chokudai = new Kyopuro();
	    chokudai.AtCoder();
	}
}

public class Kyopuro{
    int n;
    List<List<int>> list;
    List<int>[] tree;
    List<int>[] ptree;
    bool[] v;
    int[] star;
    bool ans;
    
    public void AtCoder(){
        n = int.Parse(Console.ReadLine());
        tree = new List<int>[n];
        ptree = new List<int>[n];
        for (int i=0; i<n; i++){
            tree[i] = new List<int>();
            ptree[i] = new List<int>();
        }
        string[] s;
        for (int i = 0; i < n - 1; i++){
		    s = Console.ReadLine().Split(' ');
		    int a = int.Parse(s[0]) - 1;
		    int b = int.Parse(s[1]) - 1;
		    tree[a].Add(b);
		    tree[b].Add(a);
        }
        
        ans = false;
        v = new bool[n];
        v[0] = true;
        star = new int[n];
        list = new List<List<int>>();
        list.Add(new List<int>());
        list[0].Add(0);
        Bfs(1);
        int cc = 0;
        foreach(int x in ptree[0]){
            if(star[x] == 1) cc++;
        }
        if(cc != 1) ans = true;
        if(ans) Console.WriteLine("First");
        else Console.WriteLine("Second");
    }
    
    void Bfs(int d){
        list.Add(new List<int>());
        foreach(int p in list[d-1]){
            foreach(int q in tree[p]){
                if(!v[q]){
                    list[d].Add(q);
                    ptree[p].Add(q);
                    v[q] = true;
                }
            }
        }
        if(list[d].Count > 0){
            Bfs(d+1);
            foreach(int x in list[d]){
                star[x] = 1;
                int cc = 0;
                foreach(int y in ptree[x]){
                    if(star[y] == 1){
                        cc++;
                        star[x] = 0;
                    }
                }
                if(cc>1) ans = true;
            }
        }
    }
    
    public static void DebugWL(object x){ System.Diagnostics.Debug.WriteLine(x); }
}