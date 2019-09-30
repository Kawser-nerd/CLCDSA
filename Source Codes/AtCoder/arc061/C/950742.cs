using System;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Threading;

public struct Z2 {
    public int x, y;
    public Z2(int x, int y){
        this.x = x;
        this.y = y;
    }
}
class Q<T> {
	public int start, end;
	public T[] ar;
	public int size = 0;
	public Q(int N){
		ar = new T[N];
		size = N;
		start = end = 0;
	}
	public void AddFirst(T o){
		start = (start-1+size)%size;
		ar[start] = o;
	}
	public void AddLast(T o){
		ar[end] = o;
		end = (end+1)%size;
	}
	public T RemoveFirst(){
		T ans = ar[start];
		start = (start+1)%size;
		return ans;
	}
	public int Count(){
		return (end-start+size)%size;
	}
}

 
 
public class A {
	int N,M;
    
	
	public A(){
	}
	
	string[] Rs(){
		return Console.ReadLine().Split(' ');
	}
	public void run(){
        string[] str = Rs();
		N = int.Parse(str[0]); M = int.Parse(str[1]);
        Dictionary<Z2, int> hs = new Dictionary<Z2,int>(2*M+N+10);
        int cnt1 = 0;
        for(int i=0;i<N;i++){
            hs.Add(new Z2(i,-1), cnt1);
            cnt1++;
        }
        int cnt2 = 0;
        int[,] input = new int[2,6*M]; 
        
        Action<int, int> f = (x, y) => {
            input[0,cnt2] = x; input[1,cnt2] = y;
            cnt2++;
        };
        
        for(int i=0;i<M;i++){
            int[] ip = Rs().Select( x => int.Parse(x)-1 ).ToArray();
            int i0 = ip[0];
            int i1 =ip[1];
            int i2 = ip[2];
            
            Z2 e0 = new Z2(i0, i2), e1 = new Z2(i1, i2);
            Z2 ne0 = new Z2(i0, -1), ne1 = new Z2(i1, -1);
            int hne0 = hs[ne0], hne1 = hs[ne1];
            
            if(!hs.ContainsKey(e0)){
                hs.Add(e0, cnt1);
                cnt1++;
                f(hs[e0],hne0);f(hne0, hs[e0]);
            }
            if(!hs.ContainsKey(e1)){
                hs.Add(e1, cnt1);
                cnt1++;
                f(hs[e1],hne1);f(hne1, hs[e1]);
            }
            f(hs[e0], hs[e1]);
            f(hs[e1], hs[e0]);
        }
        int[] index = new int[cnt1+1];
        int[] pos = new int[cnt1];
        int[] edges = new int[cnt2+10];
        for(int i=0;i<cnt2;i++) index[input[0,i]+1]++;
        for(int i=0;i<cnt1;i++) index[i+1] = index[i] + index[i+1];
        for(int i=0;i<cnt1;i++) pos[i] = index[i];
        for(int i=0;i<cnt2;i++){
            edges[pos[input[0,i]]] = input[1,i];
            pos[input[0,i]]++;
        }
        
        int end = hs[new Z2(N-1, -1)];
        int INF = 100000000;
        int[] dis = new int[cnt1];
        for(int i=0;i<cnt1;i++) dis[i] = INF;
		Q<Z2> que = new Q<Z2>(cnt2+3);
		que.AddLast(new Z2(0, 0)); 
		dis[0] = 0;
       
		while(que.Count()!=0){
			Z2 n = que.RemoveFirst();
			if(n.y==end){ 
				Console.WriteLine(dis[end]);
				return;
			}
			if(n.x > dis[n.y]) continue;
			
            for(int i = index[n.y]; i<index[n.y+1]; i++){
                    int e = edges[i];
					if(n.y<N){
						int nv = dis[n.y] + 1;
	                    if(nv < dis[e]){
							dis[e] = nv;
							que.AddLast(new Z2(nv, e));
						}
					} else {
						if(dis[n.y] < dis[e]){
							dis[e] = dis[n.y];
							que.AddFirst(new Z2(dis[n.y], e));
						}
					}
            }
        }
		Console.WriteLine("-1");
        
	}
}
 
public class Program {
	static void Main(string[] args){
		A a = new A();
        a.run();
	}
}