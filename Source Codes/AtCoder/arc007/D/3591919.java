import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

    static char[] C;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        C = fc.next().toCharArray();
        System.out.println(solve());
    }

    static String solve() {
        BigInteger first;
        int secondStart;
        if( C[0] != '0' ) {
            // 0??????C[0]?first???
            // ?????0????second??????first?????
            StringBuilder b = new StringBuilder();
            b.append(C[0]);
            int found = -1;
            for (int i = 1; i < C.length; i++) {
                if( C[i] == '0' ) {
                    b.append(C[i]);
                } else {
                    found = i;
                    break;
                }
            }
            first = new BigInteger(b.toString());
            if( found == -1 ) {
                secondStart = C.length;
            } else {
                secondStart = found;
            }

        } else {
            // 0???????????1????????????
            int found = -1;
            StringBuilder b = new StringBuilder();
            for (int i = 0; i < C.length; i++) {
                if( C[i] != '0' ) {
                    found = i;
                    break;
                } else {
                    b.append(C[i]);
                }
            }
            first = new BigInteger("1" + b.toString());
            if( found == -1 ) {
                secondStart = C.length;
            } else {
                secondStart = found;
            }
        }

        BigInteger second = null;
        if( secondStart == C.length ) {
            // second??????????first+1???
            second = first.add(BigInteger.ONE);

        } else {
            // ???????second -> thrid????????????????????
            int k_first = first.toString().length();
            for (int k = k_first; k <= C.length - secondStart; k++) {
                BigInteger candidate = num(secondStart, k);

                if( isOk(first, candidate, secondStart+k ) ) {
                    second = candidate;
                    break;
                }
            }

            // ?????????????second???????
            if( second == null ) {
                // first?[1-9]0*?????????(??)???????
                BigInteger candidate = num(secondStart, C.length-secondStart);
                if( first.equals(candidate) ) {
                    // 300300
                    second = candidate.multiply(BigInteger.valueOf(10));

                } else {
                    while(true) {
                        BigInteger next = candidate.multiply(BigInteger.valueOf(10));
                        if( next.compareTo(first) == 0 ) {
                            // 30030
                            second = first.add(BigInteger.ONE);
                            break;

                        } else if( next.compareTo(first) > 0 ) {
                            // 30035
                            second = next;
                            break;

                        } else {
                            candidate = next;
                        }
                    }
                }
            }
        }

        return first + " " + (second.subtract(first));
    }

    // diff??????
    // 1st -> 2nd -> 3rd... ????????
    static boolean isOk(BigInteger first, BigInteger second, int thirdStart) {
        if( first.compareTo(second) >= 0 ) return false;
        BigInteger diff = second.subtract(first);

        BigInteger curr = second;
        int idx = thirdStart;
        while(true) {
            // next???????????????
            BigInteger next = curr.add(diff);
            String next_s = next.toString();

            int last = C.length-idx;
            if( next_s.length() <= last ) {
                BigInteger num = num(idx, next_s.length());
                if( next.equals(num) ) {
                    idx += next_s.length();
                    curr = next;

                } else {
                    return false;
                }

            } else {
                // ???????prefix???????ok
                char[] arr = new char[last];
                System.arraycopy(C, idx, arr, 0, last);
                String prefix = new String(arr);
                return next_s.startsWith(prefix);
            }
        }
    }

    // C?????????????
    static BigInteger num(int start, int len) {
        char[] arr = new char[len];
        System.arraycopy(C, start, arr, 0, len);
        return new BigInteger( new String(arr) );
    }

    // C??????,????????'d'???
    static BigInteger numFill(int start, int len, char d) {
        int len1 = Math.min(len, C.length-start);
        BigInteger num1 = num(start, len1);
        return new BigInteger(num1.toString() + digits(d, len-len1));
    }

    static String digits(char d, int n) {
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < n; i++) {
            b.append(d);
        }
        return b.toString();
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}