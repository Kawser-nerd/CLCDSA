import java.util.Scanner;

public class Main {
    void run() {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[][] b = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++){
            b[i][j] = sc.nextInt();
        }

        for (int c = 1; c <= n;c++) for (int r = 1; r <= n; r++) {
            b[c][r] += b[c - 1][r] + b[c][r - 1] - b[c - 1][r - 1];
        }

        int[] mem = new int[n * n + 1];

        for (int c1 = 1; c1 <= n; c1++) for (int r1 = 1; r1 <= n; r1++) {
            for (int c2 = c1; c2 <= n; c2++) for (int r2 = r1; r2 <= n; r2++) {
                mem[(c2 - c1 + 1) * (r2 - r1 + 1)] = Math.max(mem[(c2 - c1 + 1) * (r2 - r1 + 1)], b[c2][r2] + b[c1 - 1][r1 - 1] - b[c2][r1 - 1] - b[c1 - 1][r2]);
            }
        }

        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int max = 0;
            for (int j = sc.nextInt(); j > 0; j--) max = Math.max(max, mem[j]);
            System.out.println(max);
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }
}