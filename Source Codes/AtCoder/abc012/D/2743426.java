import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
public class Main{
    static int INF = 100000000;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] cost = new int[n][n];
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cost[i][j] = INF;
            }
        }
        for(int i = 0;i < m;i++){
            int a = sc.nextInt()-1;
            int b = sc.nextInt()-1;
            int c = sc.nextInt();
            cost[a][b] = c;
            cost[b][a] = c;
        }
        int ans = solve(n,cost);

        System.out.println(ans);
    }
    public static int solve(int n,int[][] cost){
        Integer[] d = new Integer[n];
        int min = INF;
        for(int i = 0;i < n;i++){
            d = dijkstra(i,n,cost);
            Arrays.sort(d,Collections.reverseOrder());
            min = Math.min(min,d[0]);
        }
        return min;
    }
    public static Integer[] dijkstra(int from,int n,int[][] cost){
        Integer[] d = new Integer[n];
        d[from] = 0;
        for(int i = 0;i < n;i++){
            if(i == from){
                continue;
            }
            d[i] = INF;
        }

        boolean[] visited = new boolean[n];
        while(true){
            int v = -1;
            for(int u = 0;u < n;u++){
                if(!visited[u] && (v == -1 || d[u] < d[v])){
                    v = u;
                }
            }
            if(v == -1){
                break;
            }
            visited[v] = true;

            for(int u = 0;u < n;u++){
                d[u] = Math.min(d[u],d[v]+cost[v][u]);
            }
        }
        return d;
    }
}