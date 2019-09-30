import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class Main {

    static MyScanner sc;
    private static PrintWriter out;
    static long M = 1000000007;

    public static void main(String[] s) throws Exception {
        StringBuilder stringBuilder = new StringBuilder();

//        Random r = new Random(4);
//        int x = 10000;
//        stringBuilder.append(x + " ");
//        for (int l = 0; l < x; l++) {
//            int tt = r.nextInt(5) + 2;
//            stringBuilder.append(tt + " ");
//            for (int xx = 0 ; xx < tt; xx++) {
//                stringBuilder.append((r.nextInt(1000) + 1) + " ");
//            }
//        }

//        stringBuilder.append("1 3 63 928 4");

        if (stringBuilder.length() == 0) {
            sc = new MyScanner(System.in);
        } else {
            sc = new MyScanner(new BufferedReader(new StringReader(stringBuilder.toString())));
        }

        out = new PrintWriter(new OutputStreamWriter(System.out));
        initData();
        solve();
        out.flush();
    }

    private static void solveT() {
        int r = sc.nextInt();
        while (r-- > 0) {
            solve();
        }

    }


    private static void initData() {


    }

    private static void solve() {
//        BitSet kt = new BitSet(150);
//        for (int i = 0; i < 100; i+=2) {
//            kt.set(i);
//        }
//        for (int i = 0; i <= 100; i++) {
//            out.println(kt.toLeft(i));
//        }

        int r = sc.nextInt();
        int[] data = sc.na(r);
//        int xx = sl(data);
        int sum = (Arrays.stream(data).sum());
        int mm = sum / 2;

        BitSet kt = new BitSet(mm + 1);
        kt.set(0);
        for (int s : data) {
            kt.or(kt.toLeft(s));
        }
        int l = mm;
        while (!kt.is(l)) {
            l--;
        }
//        if (xx != sum - l) {
//            out.println(Arrays.toString(data) + " " + xx + " " + (sum - l));
//        }
        out.println(sum - l);
    }


    private static int sl(int[] data) {
        int[] m = new int[(1 << data.length) - 1];
        for (int s = 1; s < 1 << data.length; s++) {
            for (int k = 0; k < data.length; k++) {
                if ((s & (1 << k)) > 0) {
                    m[s - 1] += data[k];
                }
            }
        }
        Arrays.sort(m);
        return m[-1 + (1 << (data.length - 1))];
    }

    private static final class BitSet {
        private final long[] vals;

        BitSet(int v) {
            vals = new long[(v + 63) / 64];
        }

        void or(BitSet l) {
            for (int i = 0; i < vals.length; i++) {
                vals[i] |= l.vals[i];
            }
        }

        boolean is(int f) {
            return (vals[f / 64] & (1L << (f % 64))) != 0;
        }

        BitSet toLeft(int n) {
            if (n >= vals.length * 64) {
                return new BitSet(vals.length * 64);
            }
            BitSet a = new BitSet(vals.length * 64);
            int s1 = n / 64;
            int s2 = n % 64;
            if (s2 == 0) {
                System.arraycopy(vals, 0, a.vals, s1, vals.length - s1);
            } else {
                for (int i = 0; i < vals.length - s1; i++) {
                    a.vals[i + s1] |= vals[i] << s2;
                }
                for (int i = 0; i < vals.length - s1 - 1; i++) {
                    a.vals[i + s1 + 1] |= vals[i] >>> (64 - s2);
                }
            }
            return a;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int s = 0; s < vals.length * 64; s++) {
                if (is(s)) {
                    sb.append(s + ",");
                }

            }
            sb.append("]\n");
            for (int i = vals.length - 1; i >= 0; i--) {
                String s = Long.toBinaryString(vals[i]);
                for (int k = s.length(); k < 64; k++) {
                    sb.append('0');
                }
                sb.append(s);
            }


            return sb.toString();
        }

        public void set(int i) {
            vals[i / 64] |= 1L << (i % 64);
        }
    }


    static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        MyScanner(BufferedReader br) {
            this.br = br;
        }

        public MyScanner(InputStream in) {
            this(new BufferedReader(new InputStreamReader(in)));
        }

        void findToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }

        String next() {
            findToken();
            return st.nextToken();
        }

        int[] na(int n) {
            int[] k = new int[n];
            for (int i = 0; i < n; i++) {
                k[i] = sc.nextInt();
            }
            return k;
        }

        long[] nl(int n) {
            long[] k = new long[n];
            for (int i = 0; i < n; i++) {
                k[i] = sc.nextLong();
            }
            return k;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

}