import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    void solve() {
        Random rnd = new Random(123);
        final long p = (long) 1e9 + 7;
        BigInteger MODULO = BigInteger.valueOf(2).pow(64);
        final long pInv = BigInteger.valueOf(p).modInverse(MODULO).longValue();
        final int MAX = 500010;
        long[] vals = new long[MAX];
        vals[MAX / 2] = 1;
        for (int i = MAX / 2 + 1; i < MAX; i++) {
            vals[i]= vals[i - 1] * p;
        }
        for (int i = MAX / 2 - 1; i >= 0; i--) {
            vals[i] = vals[i + 1] * pInv;
        }
        in.nextInt();
        String s = in.next();
        long[] hashes = new long[s.length() + 1];
        int curPos = MAX / 2;
        int[] myPos = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            myPos[i] = curPos - MAX / 2;
            hashes[i + 1] = hashes[i];
            if (c == '<') {
                curPos--;
            } else if (c == '>') {
                curPos++;
            } else if (c == '-') {
                hashes[i + 1] -= vals[curPos];
            } else {
                hashes[i + 1] += vals[curPos];
            }
        }
//        System.err.println(Arrays.toString(hashes));
        long expectedHash = hashes[hashes.length - 1];
        long mul = 1, add = 0;
        int realPower = 0;
        HashMap<Long, Integer> count = new HashMap<>();
        long result = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            long nothingHash = -add * vals[MAX / 2 - realPower];
            long check = nothingHash * mul + add;
            if (check != 0) {
                throw new AssertionError();
            }
            Integer now = count.get(nothingHash);
            count.put(nothingHash, now == null ? 1 : (now + 1));
            char c = s.charAt(i);
            if (c == '<') {
                mul *= pInv;
                realPower--;
                add *= pInv;
            } else if (c == '>') {
                mul *= p;
                realPower++;
                add *= p;
            } else if (c == '-') {
                add--;
            } else {
                add++;
            }
            long need = expectedHash;
//            need *= vals[MAX / 2 - myPos[i]];
            long inMap = (need - add) * vals[MAX / 2 - realPower];
            Integer cou = count.get(inMap);
            if (cou != null) {
                result += cou;
//                System.err.println(i + "-> " + cou);
            }
        }
        out.println(result);
    }

    void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
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

    public static void main(String[] args) {
        new Main().runIO();
    }
}