import java.util.*;

public class Main {
    public static int[][] dp;
    public static ArrayList<Integer>[] al;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        al = new ArrayList[n];
        for(int i = 0; i<n; i++){
            al[i] = new ArrayList<Integer>();
            al[i].add(i);
        }

        for(int i=0; i<m; i++){
            int ma = sc.nextInt() - 1;
            int mb = sc.nextInt() - 1;
            al[ma].add(mb);
            al[mb].add(ma);
        }

        int q = sc.nextInt();
        int[][] p = new int[q][3];

        for(int i=0; i<q; i++){
            p[i][0] = sc.nextInt() - 1;
            p[i][1] = sc.nextInt();
            p[i][2] = sc.nextInt();
        }
        sc.close();

        dp = new int[n][11];
        for(int i=0; i<n; i++){
            for(int j=0; j<11; j++){
                dp[i][j] = -1;
            }
            
        }

        for(int i=0; i<q; i++){
            paint(p[q-i-1][0], p[q-i-1][1], q-i-1);
        }

        for(int i=0; i<n; i++){
            if(dp[i][0] == -1){
                System.out.println("0");
            }else{
                System.out.println(p[dp[i][0]][2]);
            }
        }
    }

    public static void paint(int v, int d, int t){
        if(dp[v][d] != -1) return;

        dp[v][d] = t;
        if(d == 0) return;
        for(int i=0; i<al[v].size(); i++){
            paint(al[v].get(i), d-1, t);
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.