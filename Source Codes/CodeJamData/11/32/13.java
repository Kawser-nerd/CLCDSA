import java.io.*;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

/**
 * @author Ivan Romanov
 */
public class B {
    private static final String PROBLEM = "B";

    private static final String SIZE = "large";
    //private static final String SIZE = "small-attempt1";
    //private static final String SIZE = "small-practice";
    private static final int MAX_A = 11000;

    private String solve() throws IOException {
        int l = nextInt();
        long t = nextLong();
        int n = nextInt();
        int c = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < c; i++) {
            int x = nextInt();
            for (int k = 0; c * k + i < n; k++) {
                a[c * k + i] = x;
            }
        }
        boolean[] build = new boolean[n];
        long ans = Long.MAX_VALUE;
        if (l == 0) {
            ans = calc(a, build, t);
        } /*else if (l == 1) {
            for (int i = 0; i < n; i++) {
                build[i] = true;
                long tmp = calc(a, build, t);
                ans = Math.min(ans, tmp);
                build[i] = false;
            }
        } else if (l == 2) {
            for (int i = 0; i < n; i++) {
                build[i] = true;
                for (int j = i + 1; j < n; j++) {
                    build[j] = true;
                    long tmp = calc(a, build, t);
                    ans = Math.min(ans, tmp);
                    build[j] = false;
                }
                build[i] = false;
            }
        }   */ else {

            long time = 0;
            int first = -1;

            for (int i = 0; i < n; i++) {
                long nextTime = time + 2 * a[i];
                if (nextTime < t) {
                    // no need to check
                } else if (time < t) {
                    long tmp = calc(a, i, l, t, true);
                    ans = Math.min(ans, tmp);
                    first = i;
                } else if (i == first + 1) {
                    long tmp = calc(a, i - 1, l, t, false);
                    ans = Math.min(ans, tmp);                    
                }
                time = nextTime;
            }
        }
        return "" + ans;
    }

    private static long calc(int[] a, int firstIdx, int count, long t, boolean takeFirst) {
        if (takeFirst) {
            count--;
        }
        long time = 0;
        int[] cnt = new int[MAX_A];
        for (int i = 0; i < a.length; i++) {
            if (i == firstIdx && takeFirst) {

                if (time >= t) {
                    time += a[i];
                } else if (time + 2 * a[i] <= t) {
                    time += 2 * a[i];
                } else {
                    long tmp = t - time;
                    if (tmp % 2 != 0) {
                        throw null;
                    }
                    time += a[i] + tmp / 2;
                }

            } else {
                time += 2 * a[i];
                if (i > firstIdx) {
                    cnt[a[i]]++;
                }
            }
        }
        for (int i = MAX_A - 1; i >= 0; i--) {
            if (cnt[i] > 0 && count > 0) {
                int tmp = Math.min(cnt[i], count);
                time -= tmp * i;
                count -= tmp;
            }
            if (count == 0) {
                break;
            }
        }
        return time;
    }

    private static long calc(int[] a, boolean[] build, long t) {
        long time = 0;
        for (int i = 0; i < a.length; i++) {
            if (build[i]) {

                if (time >= t) {
                    time += a[i];
                } else if (time + 2 * a[i] <= t) {
                    time += 2 * a[i];
                } else {
                    long tmp = t - time;
                    if (tmp % 2 != 0) {
                        throw null;
                    }
                    time += a[i] + tmp / 2;
                }

            } else {
                time += 2 * a[i];
            }
        }
        return time;
    }

    private BufferedReader reader;

    private StringTokenizer tt = new StringTokenizer("");

    private String nextToken() throws IOException {
        while (!tt.hasMoreTokens()) {
            tt = new StringTokenizer(reader.readLine());
        }
        return tt.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private void run() throws IOException {
        reader = new BufferedReader(new FileReader(PROBLEM + "-" + SIZE + ".in"));
        PrintWriter writer = new PrintWriter(new File(PROBLEM + "-" + SIZE + ".out"));
        try {
            int n = nextInt();
            for (int i = 0; i < n; i++) {
                writer.print("Case #" + (i + 1) + ": ");
                writer.print(solve());
                writer.println();
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new B().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
