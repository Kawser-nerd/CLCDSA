import java.io.*;
import  java.util.*;

import static java.lang.System.in;

class Main{
    static HashMap<Integer,Long> dist = new HashMap<>();
    static ArrayList<Edge>[] map;
    public static void main(String[] args)throws IOException{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int X = sc.nextInt();
        map = new ArrayList[n+1];
        for(int i=0;i<=n;i++) map[i]=new ArrayList<>();
        for(int i=0;i<n-1;i++){
            int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
            map[a].add(new Edge(b,c));
            map[b].add(new Edge(a,c));
        }
        for(Edge e:map[1]) dfs(e.to,1,e.weight);
        if(X==0){
            long ans = dist.getOrDefault(0,0L);
            for(int w:dist.keySet()){
                long cur = dist.get(w);
                ans += cur*(cur-1)/2;
            }
            System.out.println(ans);
        }else{
            // X!=0, then w^w!=X for all w>=0
            long ans1 = dist.getOrDefault(X,0L);
            long ans2 = 0;
            for(int w:dist.keySet()){
                long cur = dist.get(w);
                ans2 += cur*dist.getOrDefault(w^X,0L);
            }
            System.out.println(ans1+ans2/2);
        }
    }
    static void dfs(int cur, int from, int len){
        dist.put(len,dist.getOrDefault(len,0L)+1L);
        for(Edge e:map[cur]){
            if(e.to==from) continue;
            dfs(e.to,cur,len^e.weight);
        }
    }
    static class Edge{
        int to,weight;
        public Edge(int t, int w){
            this.to = t; this.weight = w;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.