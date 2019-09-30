import java.util.*;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numCases = sc.nextInt();
        for (int q = 0; q < numCases; q++) {
            int N = sc.nextInt();
            int P = sc.nextInt();
            long[] R = new long[N];
            for (int i = 0; i < N; i++) {
                R[i] = sc.nextLong() * 10;
            }
            long[][] Q = new long[N][P];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < P; j++) {
                    Q[i][j] = sc.nextLong() * 10;
                }
                Arrays.sort(Q[i]);
            }

            Queue<Long>[] queues = new Queue[N];
            for (int i = 0; i < N; i++) {
                queues[i] = new ArrayDeque<>();
                for (int j = 0; j < P; j++) {
                    queues[i].offer(Q[i][j]);
                }
            }

            int count = 0;
            outer:
            while (true) {
                long[] nextVals = new long[N];
                for (int i = 0; i < N; i++) {
                    if (queues[i].isEmpty()) {
                        break outer;
                    } else {
                        nextVals[i] = queues[i].peek();
                    }
                }

                long[] minServings = new long[N];
                long[] maxServings = new long[N];
                boolean ok = true;
                for (int i = 0; i < N; i++) {
                    minServings[i] = minServings(nextVals[i], R[i]);
                    maxServings[i] = maxServings(nextVals[i], R[i]);
                    if (minServings[i] > maxServings[i] || minServings[i] <= 0) {
                        queues[i].poll();
                        ok = false;
                    }
                }

                if (!ok) {
                    continue;
                }

                long maxMin = 0;
                for (int i = 0; i < N; i++) {
                    maxMin = Math.max(maxMin, minServings[i]);
                }


                for (int i = 0; i < N; i++) {
                    if (maxServings[i] < maxMin) {
                        queues[i].poll();
                        ok = false;
                    }
                }

                if (ok) {
                    count++;
                    for (int i = 0; i < N; i++) {
                        queues[i].poll();
                    }
                }
            }

            System.out.printf("Case #%d: ", q+1);
            System.out.println(count);
        }
    }

    static long maxServings(long top, long bot) {
        return top / (minTotal(bot));
    }

    static long minServings(long top, long bot) {
        bot = maxTotal(bot);
        return (top + bot - 1) / bot;
    }

    static long maxTotal(long num) {
        return num * 11 / 10;
    }

    static long minTotal(long num) {
        return num * 9 / 10;
    }
}
