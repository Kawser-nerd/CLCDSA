import java.util.Scanner;


public class Main {

    public static boolean dfs(
            int n, int u, int c, int[] color, int[][] colorGraph,
            int[] colorCount
    ) {
        color[u] = c;
        colorCount[c]++;
        for (int v = 1; v <= n; ++v) {
            if (u == v || colorGraph[u][v] == 0) {
                continue;
            }
            if (color[v] == 0  && !dfs(n, v, 3 - c, color, colorGraph, colorCount)) {
                return false;
            }
            if (color[v] == c) {
                return false;
            }
        }
        return true;
    }

    public static void main(String [] args) {
        final Scanner sc = new Scanner(System.in);
        final int n = sc.nextInt();
        final int m = sc.nextInt();
        final int [][] road = new int [n + 1][n + 1];
        for (int i = 0; i < m; ++i) {
            final int u = sc.nextInt();
            final int v = sc.nextInt();
            road[u][v] = 1;
            road[v][u] = 1;
        }

        final int [][] colorGraph = new int[n + 1][n + 1];

        for (int u = 1; u <= n; ++u) {
            for (int v = 1; v <= n; ++v) {
                if (u == v) {
                    continue;
                }
                if (road[u][v] != 1) {
                    colorGraph[u][v] = 1;
                    colorGraph[v][u] = 1;
                }
            }
        }

        //all nodes in colorGraph must be 2 color
        //check whether it's possible
        // color : 1 red
        // color : 2 white
        // color: 0 undefined
        final int[] color = new int[n + 1];
        final int[] colorCount = new int[3];
        final int [][] dp = new int[n + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            colorCount[1] = colorCount[2] = 0;

            if (color[i] == 0) {
                if (!dfs(n, i, 1, color, colorGraph, colorCount)) {
                    System.out.println(-1);
                    return;
                }
            }
            for (int count = 0; count <= n; ++count) {
                if (dp[i - 1][count] == 1) {
                    dp[i][count + colorCount[1]] = 1;
                    dp[i][count + colorCount[2]] = 1;
                }
            }
        }

        int minCount = Integer.MAX_VALUE;


            for (int red = 0; red <= n; ++red) {
                if (dp[n][red] == 1) {
                    int currentCount = red * (red - 1) / 2 +
                            (n - red) * (n - red - 1) / 2;
                    minCount = Math.min(minCount, currentCount);
                }
            }



        System.out.println(minCount);
    }
}