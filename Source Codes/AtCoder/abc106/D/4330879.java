import java.util.Arrays;
import java.util.Scanner;

public class Main {

    void run() {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(), m = sc.nextInt(), q = sc.nextInt();
        int[][] lr = new int[m][2];
        int[][] pq = new int[q][2];

        for (int i = 0; i < m; i++) {
            lr[i][0] = sc.nextInt();
            lr[i][1] = sc.nextInt();
        }
        for (int i = 0; i < q; i++) {
            pq[i][0] = sc.nextInt();
            pq[i][1] = sc.nextInt();
        }
        int[][] board = new int[n + 2][n + 2];

        for (int i = 0; i < m; i++) {
            board[lr[i][1]][lr[i][0]] += 1;
        }

        for (int y = 1; y <= n; y++) for (int x = 1; x <= n; x++) {
            board[y][x] += board[y - 1][x] + board[y][x - 1] - board[y - 1][x - 1];
        }

        for (int i = 0; i < q; i++) {
            System.out.println(query(pq[i][0], pq[i][1], board));
        }
    }

    int query(int p, int q, int[][] board) {
        return board[q][q] - board[q][p - 1] - board[p - 1][q] + board[p - 1][p - 1];
    }

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        new Main().run();
    }
}