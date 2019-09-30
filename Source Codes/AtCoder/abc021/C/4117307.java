import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt() - 1;
        int b = sc.nextInt() - 1;
        int m = sc.nextInt();
        int[] x = new int[m];
        int[] y = new int[m];
        long MOD = 1000000007;
        int[][] dp = new int[n][n];
        for (int i = 0; i < m ; i++) {
            x[i] = sc.nextInt() - 1;
            y[i] = sc.nextInt() - 1;
            dp[x[i]][y[i]] = dp[y[i]][x[i]] = 1;
        }
        for (int i = 0; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (i != j && dp[i][j] == 0) {
                    dp[i][j] = 1000;
                }
            }
        }
        //?????????
        for (int k = 0 ; k < n ; k++) {
            for (int i = 0 ; i < n ; i++) {
                for (int j = 0 ; j < n ; j++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        // ???DAG
        int[][] dag = new int[n][n];
        for (int i = 0 ; i < m ; i++) {
            if (dp[a][x[i]] == dp[a][y[i]] + 1) {
                dag[y[i]][x[i]] = 1;
            }
            if (dp[a][x[i]] == dp[a][y[i]] - 1) {
                dag[x[i]][y[i]] = 1;
            }
        }
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
        for (int i = 0 ; i < n ; i++) {
            int d = dp[a][i];
            if (map.containsKey(d)) {
                ArrayList<Integer> list = map.get(d);
                list.add(i);
                map.put(d, list);
            } else {
                ArrayList<Integer> list = new ArrayList<>();
                list.add(i);
                map.put(d, list);
            }
        }
        long[] minStep = new long[n];
        minStep[a] = 1;
        for (int i = 0 ; i < dp[a][b] ; i++) {
            ArrayList<Integer> list = map.get(i);
            for (int j = 0 ; j < list.size() ; j++) {
                int town = list.get(j);
                for (int k = 0 ; k < n ; k++) {
                    if (dag[town][k] == 1) {
                        minStep[k] = (minStep[k] + minStep[town]) % MOD;
                    }
                }
            }
        }
        System.out.println(minStep[b]);

    }


}