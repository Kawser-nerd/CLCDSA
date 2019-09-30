import java.util.Arrays;
import java.util.Scanner;
import java.util.StringJoiner;
import java.util.function.Predicate;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        long[] hs = new long[N];
        long[] ss = new long[N];

        for (int i = 0; i < N; i++) {
            hs[i] = sc.nextInt();
            ss[i] = sc.nextInt();
        }

        System.out.println( solve(N, hs, ss) );
    }

    private static long solve(int N, long[] hs, long[] ss) {
        return findLower(0, Long.MAX_VALUE, x -> {
            // x???????????????
            // => x?????????????????????????????
            long[] limits = new long[N];
            for (int i = 0; i < N; i++) {
                long h = hs[i];
                long s = ss[i];

                //?????????x????????????
                if( h > x ) return false;

                // ????????x??????
                // x >= h + s * n-1 ???????n?????
                limits[i] = (x - h) / s;
            }

            // ?????index????????????????????????
            //   index=?
            Arrays.sort(limits);

            for (int i = 0; i < N; i++) {
                if( limits[i] < i ) return false;
            }
            return true;
        });
    }

    private static long findLower(long low, long high, Predicate<Long> p) {
        long mid;
        while( low < high ) {
            mid = ((high - low) >>> 1) + low; // (high + low) / 2
            if( p.test(mid) ) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    private static int upperBound(int[] array, int value) {
        int low = 0;
        int high = array.length;
        int mid;
        while( low < high ) {
            mid = ((high - low) >>> 1) + low; // (high + low) / 2
            if( array[mid] <= value ) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    private static void show(long[] array) {
        StringJoiner j = new StringJoiner(" ");
        for (long value : array) {
            j.add("" + value);
        }
        System.err.println( j.toString() );
    }
}