import java.util.Scanner;

public class C2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            int K = sc.nextInt();
            if (N == 1 || M == 1) {
                System.out.println("Case #" + caseNum + ": " + K);
                continue;
            }

            int answer = 2 * N + 2 * M - 4;
            for (int stones = 2 * N + 2 * M - 5; stones > 0; stones--) {
                int newEnclosed = Math.max(temp(M, N, stones), temp(N, M, stones));
                if (newEnclosed >= K) {
                    answer = stones;
                } else {
                    break;
                }
            }
            System.out.println("Case #" + caseNum + ": " + answer);
        }
    }

    private static int temp(int N, int M, int stones) {
        int diff = 2 * N + 2 * M - 4 - stones;
        int d1 = diff / 4;
        int d2 = (diff + 1) / 4;
        int d3 = (diff + 2) / 4;
        int d4 = (diff + 3) / 4;
        int newEnclosed = 0;
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (n + m >= d1 && n + (M - 1 - m) >= d2 && (N - 1 - n) + (M - 1 - m) >= d3 && (N - 1 - n) + m >= d4) {
                    newEnclosed++;
                }
            }
        }
        return newEnclosed;
    }
}
