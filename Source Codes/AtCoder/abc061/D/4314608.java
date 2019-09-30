import java.util.Arrays;
import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] edge = new int[m][3];
        for (int i = 0; i < m; i++) {
            edge[i][0] = sc.nextInt() -1;
            edge[i][1] = sc.nextInt() -1;
            edge[i][2] = -sc.nextInt();
        }
        long[] d = bellmanFord(n, edge, 0);
        if(d == null) System.out.println("inf");
        else System.out.println(-d[n-1]);
        sc.close();

    }
    public static long[] bellmanFord(int n, int[][] edge, int s){
        long d[] = new long[n];
        Arrays.fill(d, Long.MAX_VALUE);
        d[s] = 0L;
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < edge.length; j++){
                int[] e = edge[j];
                if(d[e[0]] != Long.MAX_VALUE && d[e[1]] > d[e[0]] + e[2]){
                    d[e[1]] = d[e[0]] + e[2];
                    if(i == n - 1 && e[1] == n - 1){
                        d = null;
                        break;
                    }
                }
            }
        }
        return d;
    }

}