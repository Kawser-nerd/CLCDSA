import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] rck = scanner.nextLine().split(" ", 3);
        int R = Integer.parseInt(rck[0]);
        int C = Integer.parseInt(rck[1]);
        int K = Integer.parseInt(rck[2]);
        int N = Integer.parseInt(scanner.nextLine());

        int[] countPerR = new int[R+1];
        int[] countPerC = new int[C+1];

        int[] Rs = new int[N];
        int[] Cs = new int[N];
        for (int i = 0; i < N; i++) {
            String[] rc = scanner.nextLine().split(" ", 2);
            int r = Integer.parseInt(rc[0]);
            int c = Integer.parseInt(rc[1]);
            countPerR[r]++;
            countPerC[c]++;
            Rs[i] = r;
            Cs[i] = c;
        }

        long[] rPerCount = new long[N+1];
        for (int i = 1; i <= R; i++) {
            rPerCount[countPerR[i]]++;
        }

        long[] cPerCount = new long[N+1];
        for (int i = 1; i <= C; i++) {
            cPerCount[countPerC[i]]++;
        }

        long result = 0;
        for (int i = 0; i <= K; i++) {
            result += rPerCount[i] * cPerCount[K-i];
        }

        for (int i = 0; i < N; i++) {
            int r = Rs[i];
            int c = Cs[i];
            long count = countPerR[r] + countPerC[c];
            if (count == K) {
                result--;
            } else if (count == K + 1) {
                result++;
            }
        }

        System.out.println(result);
    }
}