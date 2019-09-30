package rayker.gcj2017;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Solver {
    public void solve(InputReader in, PrintWriter out) {

        int nTests = in.nextInt();
        for (int t = 1; t <= nTests; t++) {
            long n = in.nextLong();
            assert stupid(n) == smart(n);
            print(t, out, smart(n));
        }
    }

    private long smart(long n) {
        if (isTidy(n)) return n;

        IntStream intStream = Long.toString(n).chars().map(c -> c - '0');
        int[] arr = IntStream.concat(IntStream.of(0), intStream).toArray();

        int brokenAt = -1;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i - 1] > arr[i]) {
                brokenAt = i;
                break;
            }
        }

        int fixAt = -1;
        for (int i = brokenAt - 1;; i--) {
            if (arr[i - 1] < arr[i]) {
                fixAt = i;
                break;
            }
        }

        arr[fixAt]--;

        for (int i = fixAt + 1; i < arr.length; i++) {
            arr[i] = 9;
        }

        String collect = Arrays.stream(arr)
                .mapToObj(Integer::toString)
                .collect(Collectors.joining());

        long ans = Long.parseLong(collect);

        return ans;
    }

    private long stupid(long n) {
        for (long i = n; i >= 0; i--) {
            if (isTidy(i)) {
                return i;
            }
        }
        throw new RuntimeException("WTF?");
    }

    private boolean isTidy(long n) {
        char[] chars = Long.toString(n).toCharArray();
        for (int i = 1; i < chars.length; i++) {
            if (chars[i - 1] > chars[i]) {
                return false;
            }
        }
        return true;
    }

    private void print(int t, PrintWriter out, long v) {
//        if (v == -1) {
//            out.printf("Case #%d: IMPOSSIBLE%n", t);
//        } else {
            out.printf("Case #%d: %d%n", t, v);
//        }
    }
}
