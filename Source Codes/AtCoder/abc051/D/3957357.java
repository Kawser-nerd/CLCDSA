import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    public static void main(String[] args)throws IOException{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(),m = sc.nextInt();
        int inf = Integer.MAX_VALUE/2-10;
        int[][] dist = new int[n+1][n+1];
        for(int i=0;i<=n;i++) Arrays.fill(dist[i],inf);
        for(int i=0;i<=n;i++) dist[i][i] = 0;
        Edge[] dic = new Edge[m];
        for(int i=0;i<m;i++){
            int a = sc.nextInt(), b=sc.nextInt(), c = sc.nextInt();
            dic[i] = new Edge(a,b,c);
            dist[a][b] = Math.min(dist[a][b],c);
            dist[b][a] = Math.min(dist[b][a],c);
        }
        // run Floyd-Warshall
        for(int mid=1;mid<=n;mid++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++) dist[i][j] = Math.min(dist[i][j], dist[i][mid]+dist[mid][j]);
            }
        }
        int ans = 0;
        for(Edge e:dic){
            if(dist[e.left][e.right]<e.length) ans++;
        }
        System.out.println(ans);
    }
    static class Edge{
        int left,right,length;
        public Edge(int l, int r, int len){
            left = l;
            right = r;
            length = len;
        }
    }
}