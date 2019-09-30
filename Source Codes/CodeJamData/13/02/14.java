import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int caseNum = 1; caseNum <= T; caseNum++) {
            int N = sc.nextInt();
            int M = sc.nextInt();

            int[][] lawn = new int[N][M];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    lawn[i][j] = sc.nextInt();
                }
            }

            int[] rowMax = new int[N];
            int[] colMax = new int[M];
            for (int i = 0; i < N; i++) {
                rowMax[i] = lawn[i][0];
                for (int j = 1; j < M; j++) {
                    rowMax[i] = Math.max(rowMax[i], lawn[i][j]);
                }
            }
            for (int j = 0; j < M; j++) {
                colMax[j] = lawn[0][j];
                for (int i = 1; i < N; i++) {
                    colMax[j] = Math.max(colMax[j], lawn[i][j]);
                }
            }

            boolean possible = true;
            outer: for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (lawn[i][j] != Math.min(rowMax[i], colMax[j])) {
                        possible = false;
                        break outer;
                    }
                }
            }
            System.out.print("Case #" + caseNum + ": ");
            if (possible) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
