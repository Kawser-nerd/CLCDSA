import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    private FastScanner in;
    private PrintWriter out;

    final int HASH_MOD = (int) 1e9 + 7;

    class MyNumber {
        BitSet value;
        int[] hash;
        int[] firstOne;
        int len;

        MyNumber(BitSet s) {
            value = s;
            int slen = s.length();
            hash = new int[slen + 1];
            for (int i = 0; i < slen; i++) {
                hash[i + 1] = (int) ((hash[i] * 29L + (s.get(s.length() - 1 - i) ? 1 : 0)) % HASH_MOD);
            }
            len = slen;
            firstOne = new int[slen + 1];
            firstOne[slen] = slen;
            for (int i = slen - 1; i >= 0; i--) {
                if (s.get(slen - 1 - i)) {
                    firstOne[i] = i;
                } else {
                    firstOne[i] = firstOne[i + 1];
                }
            }
        }

        MyNumber(String s) {
            this(read(s));
        }

        @Override
        public String toString() {
            return value.toString();
        }
    }

    int MAX;

    MyNumber[] numbers;

    int getSameLen(MyNumber a, MyNumber b) {
        int r = Math.min(a.len, b.len) + 1;
        int l = 0;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (a.hash[m] == b.hash[m]) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }

    int calcLenOfDiff(MyNumber a, MyNumber b) {
        if (a.len < b.len) {
            return calcLenOfDiff(b, a);
        }
        int sameLen = getSameLen(a, b);
        if (sameLen == b.len) {
            int firstOne = a.firstOne[sameLen];
            return a.len - firstOne;
        } else {
            return a.len - sameLen;
        }
    }

    List<MyNumber> list = new ArrayList<>();

    BitSet shiftLeft(BitSet x, int shift) {
        if (x.cardinality() == 0) {
            throw new AssertionError();
        }
        int len = x.length();
        BitSet newOne = new BitSet(len + shift);
        for (int i = 0; i < len; i++) {
            if (x.get(i)) {
                newOne.set(i + shift);
            }
        }
        return newOne;
    }

    BitSet xor(BitSet one, BitSet two, int len) {
        BitSet res = new BitSet(len);
        for (int i = 0; i < len; i++) {
            if (one.get(i) != two.get(i)) {
                res.set(i);
            }
        }
        return res;
    }

    void add(MyNumber number) {
        if (numbers[number.len] == null) {
            numbers[number.len] = number;
        }
        for (int i = 0; i < MAX; i++) {
            if (numbers[i] != null) {

                int diffLen = calcLenOfDiff(number, numbers[i]);
                if (diffLen != 0 && numbers[diffLen] == null) {

                    BitSet first = number.value;
                    BitSet second = numbers[i].value;
                    if (number.len > numbers[i].len) {
                        second = shiftLeft(second, number.len - numbers[i].len);
                    } else {
                        first = shiftLeft(first, numbers[i].len - number.len);
                    }
                    MyNumber next = new MyNumber(xor(first, second, diffLen));
                    numbers[diffLen] = next;
                    if (next.len != diffLen) {
                        throw new AssertionError();
                    }
                    list.add(next);
                }

            } else {

                if (i > number.len) {
                    MyNumber next = new MyNumber(shiftLeft(number.value, i - number.len));
                    numbers[i] = next;
                    if (next.len != i) {
                        System.err.println(number + " " + i + " " + next + " " + (i - number.len));
                        throw new AssertionError();
                    }
                    list.add(next);
                }

            }
        }
    }

    MyNumber gcd(MyNumber a, MyNumber b) {
        if (a == null) {
            return b;
        }
        if (a.len < b.len) {
            return gcd(b, a);
        }
        int shift = a.len - b.len;
        BitSet next = new BitSet(a.len);
        for (int i = 0; i < a.len; i++) {
            boolean xx = a.value.get(i);
            if (i >= shift) {
                xx ^= b.value.get(i - shift);
            }
            if (xx) {
                next.set(i);
            }
        }
        if (next.cardinality() == 0) {
            return b;
        }
        return gcd(b, new MyNumber(next));
    }

    BitSet read(String s) {
        BitSet res = new BitSet(s.length());
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                res.set(s.length() - 1 - i);
            }
        }
        return res;
    }

    private void solve() {
        int n = in.nextInt();
        long START = System.currentTimeMillis();
        BitSet X = read(in.next());
        MAX = X.length() + 5;
        MyNumber GCD = null;
        numbers = new MyNumber[MAX];
        for (int i = 0; i < n; i++) {
            MyNumber number = new MyNumber(in.next());
            GCD = gcd(GCD, number);
//            add(number);
        }
        add(GCD);
        final int mod = 998244353;
        BitSet current = new BitSet();
        int[] pow2 = new int[MAX];
        pow2[0] = 1;
        for (int i = 1; i < MAX; i++) {
            pow2[i] = pow2[i - 1];
            if (numbers[i] != null) {
                pow2[i] *= 2;
                pow2[i] %= mod;
            }
        }
        long result = 0;
        boolean found = true;
        for (int i = MAX - 2; i >= 0; i--) {
            boolean xBit = X.get(i);
            boolean myBit = current.get(i);
            if (numbers[i + 1] != null) {
                if (xBit) {
                    result += pow2[i];
                    if (!myBit) {
                        current.xor(numbers[i + 1].value);
                    }
                } else {
                    if (myBit) {
                        current.xor(numbers[i + 1].value);
                    }
                }
            } else {
                if (xBit != myBit) {
                    if (myBit) {
                    } else {
                        result += pow2[i + 1];
                    }
                    found = false;
                    break;
                }
            }
        }
        if (found) {
            result++;
        }
        out.println(result % mod);
        System.err.println(System.currentTimeMillis() - START);
    }

    private void run() {
        try {
            in = new FastScanner(new File("ARC_084_D.in"));
            out = new PrintWriter(new File("ARC_084_D.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
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