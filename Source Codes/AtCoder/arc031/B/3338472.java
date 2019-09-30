import java.util.*;

public class Main {
    static int H;
    static int W;
    static char[][] table;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        H = 10;
        W = 10;

        int oNum = 0;

        table = new char[H][W];
        for (int i = 0; i < H; i++) {
            String line = sc.nextLine();
            for (int j = 0; j < W; j++) {
                char c = line.charAt(j);
                if (c == 'o') oNum++;
                table[i][j] = c;
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (table[i][j] == 'o') continue;

                table[i][j] = 'o';

                // ???'o'????????dfs????
                for (int a = 0; a < H; a++) {
                    for (int b = 0; b < W; b++) {
                        if (table[a][b] == 'x') continue;
                        boolean[][] visited = new boolean[H][W];
                        int dfsRet = dfs(a, b, visited);
                        if (dfsRet == oNum + 1) {
                            System.out.println("YES");
                            return;
                        }
                        break;
                    }
                }

                table[i][j] = 'x';
            }
        }

        System.out.println("NO");
    }

    static int dfs(int a, int b, boolean[][] visited) {
        if (a < 0 || b < 0 || a >= H || b >= W || visited[a][b] || table[a][b] == 'x') return 0;
        visited[a][b] = true;
        return dfs(a + 1, b, visited) + dfs(a - 1, b, visited) + dfs(a, b - 1, visited) + dfs(a, b + 1, visited) + 1;
    }
}