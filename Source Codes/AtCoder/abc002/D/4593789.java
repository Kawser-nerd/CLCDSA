import java.util.*;
public class Main {
    private static int ans = 1;
    private static int n, m;
    private static boolean[][] connection;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        connection = new boolean[n][n];
        for(int i = 0; i < m; i++) {
            int x = sc.nextInt() - 1;
            int y = sc.nextInt() - 1;
            connection[x][y] = true;
            connection[y][x] = true;
        }
        for(int i = 0; i < (1 << n); i++) {
            if(isConnected(i)) {
                ans = Math.max(ans, Integer.bitCount(i));
            }
        }
        System.out.println(ans);
    }

    private static boolean isConnected(int num) {
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(((num >> i) & 1) == 1 && ((num >> j) & 1) == 1 && !connection[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}