import java.util.*;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int N = scanner.nextInt();
            int K = scanner.nextInt();
            long[] heights = new long[N];
            for (int i = 0; i < N; i++) {
                heights[i] = scanner.nextLong();
            }
            Arrays.sort(heights);
            long min = Long.MAX_VALUE;
            for (int i = 0; i + K - 1 < N; i++) {
                long diff = heights[i + K - 1] - heights[i];
                min = Math.min(diff, min);
            }
            System.out.println(min);
        }
    }

    static class Pair {
        final int kind;
        final long point;

        Pair(int kind, long point) {
            this.kind = kind;
            this.point = point;
        }
    }

}