import java.util.*;
import java.io.*;
class Main{
  
  static int[] update;
  static int[] pare;
  static TreeMap<Integer, Integer> sizes[];
  
  static int root(int v, int t){
    if(update[v]>t)return v;
    return root(pare[v], t);
  }
  
  static int size(int v, int t){
    v=root(v, t);
	return sizes[v].floorEntry(t).getValue();
  }
  
  static void unite(int v, int u, int t){
    v=root(v, t);
    u=root(u, t);
    if(v==u)return;
    if(pare[u] < pare[v]){
      int tmp = u;u=v;v=tmp;
    }
    pare[v] += pare[u];
    sizes[v].put(t, -pare[v]);
    pare[u]=v;
    update[u]=t;
  }
  
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    pare = new int[N];
    update = new int[N];
    sizes = new TreeMap[N];
    for(int i=0;i<N;++i){
      sizes[i]=new TreeMap<>();
      sizes[i].put(0, 1);
    }
    Arrays.fill(pare, -1);
    Arrays.fill(update, Integer.MAX_VALUE);
    for(int i=1;i<=M;++i){
      unite(Integer.parseInt(sc.next())-1, Integer.parseInt(sc.next())-1, i);
    }
    int Q = sc.nextInt();
    PrintWriter out = new PrintWriter(System.out);
    while(Q-->0){
      int x = Integer.parseInt(sc.next())-1, y=Integer.parseInt(sc.next())-1, z=Integer.parseInt(sc.next());
      int left = 0, right=M;
      while(right-left>1){
        int t = (left+right)/2;
        int v = root(x, t), u = root(y, t);
        if(v==u){
          if(size(v, t) >=z)right=t;
          else left=t;
        }else{
          if(size(v, t)+size(u, t) >=z)right=t;
          else left=t;
        }
      }
      out.println(right);
    }
    out.flush();
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.