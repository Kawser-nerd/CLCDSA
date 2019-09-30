import java.util.BitSet;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.List;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collections;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Collection;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.io.PrintStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ogiekako
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		MyScanner in = new MyScanner(inputStream);
		MyPrintWriter out = new MyPrintWriter(outputStream);
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
    int MOD = (int) (1e9 + 7);

    public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
        Mint.set1e9_7();
        int N = in.nextInt();
        int M = in.next().length();

        int res = solve(N, M);
        out.println(res);
    }

    private long[] computeStep(int N, int M) {
        int[][] stepDp = new int[2][N + 1];
        int cur=0,nxt=1;
        stepDp[cur][0] = 1;
        long[] step = new long[N + 1];
        for (int i = 0; i <= N; i++) {
            step[i] = stepDp[cur][M];
            Arrays.fill(stepDp[nxt],0);
            for (int j = 0; j < N; j++) {
                if(stepDp[cur][j] == 0) continue;
                stepDp[nxt][j + 1] += stepDp[cur][j];
                if (stepDp[nxt][j + 1] >= MOD) {
                    stepDp[nxt][j + 1] -= MOD;
                }
                stepDp[nxt][Math.max(0, j - 1)] += stepDp[cur][j];
                if (stepDp[nxt][Math.max(0, j - 1)] >= MOD) {
                    stepDp[nxt][Math.max(0, j - 1)] -= MOD;
                }
            }
            int tmp=cur;cur=nxt;nxt=tmp;
        }
        return step;
    }

    private int solve(int N, int M) {
        long[] step = computeStep(N, M);

        two = new Mint[N+1];
        for (int i = 0; i < N + 1; i++)
            two[i] = i==0 ? Mint.ONE : two[i-1].mul(2);

        Mint res = Mint.ZERO;
        int zeroDet = 0;
        int zeroComb = 0;
        for (int t = 0; t < N + 1; t++) if(t%2==0) {
            for (int k = 0; k < N + 1; k++) {
                if (N-t+k < 0 || t/2-k<0) continue;

                if (step[N - t] > 0) {
                    Mint c = MathUtils.comb(N - t + k, k);
                    Mint det = det(t,k);
                    Mint val = c.mul(step[N - t]).mul(det);
                    if(c.equals(Mint.ZERO)) zeroComb++;
                    if(det.equals(Mint.ZERO)) zeroDet++;
                    res = res.add(val);
                }
            }
        }
        Debug.print("zeroComb", zeroComb);
        Debug.print("zeroDet", zeroDet);
        return res.get();
    }
    Mint[] two;
    Mint det(int i, int J) {
        if(i==0 && J==0)return Mint.ONE;
        int n = i / 2;
        if(n-J < 0) return Mint.ZERO;
        return MathUtils.catalanTransposed(n,J).mul(two[n-J]);
    }
}

class MyScanner {
    private final InputStream in;

    public MyScanner(InputStream in) {
        this.in = in;
    }

    private static final int BUFSIZE = 65536;
    int bufLen;
    int bufPtr;
    byte[] buf = new byte[BUFSIZE];

    public int read() {
        if (bufLen == -1)
            throw new InputMismatchException();
        if (bufPtr >= bufLen) {
            bufPtr = 0;
            try {
                bufLen = in.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (bufLen <= 0)
                return -1;
        }
        return buf[bufPtr++];
    }

    private char[] strBuf = new char[BUFSIZE];

    public String next() {
        int strLen = 0;
        int c;
        do {
            c = read();
            if (c == -1) throw new NoSuchElementException();
        } while (Character.isWhitespace(c));
        do {
            if (strLen + 1 >= strBuf.length) {
                char[] tmp = new char[strBuf.length * 2];
                System.arraycopy(strBuf, 0, tmp, 0, strBuf.length);
                strBuf = tmp;
            }
            strBuf[strLen++] = (char) c;
            c = read();
        } while (c != -1 && !Character.isWhitespace(c));
        return new String(strBuf, 0, strLen);
    }

    public int nextInt() {
        int c = read();
        if (c == -1) throw new NoSuchElementException();
        while (c != '-' && (c < '0' || '9' < c)) {
            c = read();
            if (c == -1) throw new NoSuchElementException();
        }
        if (c == '-') return -nextInt();
        int res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = read();
        } while ('0' <= c && c <= '9');
        return res;
    }

}

class MyPrintWriter {
    PrintWriter out;

    public MyPrintWriter(OutputStream outputStream) {
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void println(int a) {
        out.println(a);
    }

    public void close() {
        out.close();
    }

}

class Mint {
    public static Mint ZERO;
    public static Mint ONE;

    final long x;

    private static int MOD = 0;

    private Mint(long x) {
        this.x = normalize(x);
    }

    public static void set1e9_7() {
        setMod((int) (1e9 + 7));
    }

    public static void setMod(int mod) {
        if (mod <= 0) throw new IllegalArgumentException("mod should be positive: " + mod);
        if (!BigInteger.valueOf(mod).isProbablePrime(10)) throw new IllegalArgumentException("mod must be a prime." + mod);
        MOD = mod;

        ZERO = of(0);
        ONE = of(1);
    }

    public static int getMod() {
        if (MOD == 0) throw new IllegalArgumentException("Please set mod first.");
        return MOD;
    }

    public static long normalize(long x) {
        if (0 <= x) {
            if (x < MOD) return x;
            if (x < MOD * 2) return x - MOD;
            return x % MOD;
        }
        if (-MOD <= x) return x + MOD;
        x %= MOD;
        return x == 0 ? 0 : x + MOD;
    }

    private static long mulLong(long x, long y) {
        return normalize(normalize(x) * normalize(y));
    }

    public int get() {
        return (int) x;
    }

    public static Mint of(long value) {
        return new Mint(value);
    }

    public Mint mulInv() {
        return of(MathUtils.inverse(x, getMod()));
    }

    public Mint mul(Mint other) {
        return mul(other.x);
    }

    public Mint mul(long y) {
        return of(mulLong(x, y));
    }

    public Mint add(Mint other) {
        return of(x + other.x);
    }

    public Mint minus(Mint other) {
        return minus(other.x);
    }

    public Mint minus(long y) {
        return of(x - normalize(y));
    }

    public String toString() {
        return "" + x;
    }

    public boolean equals(Object o) {
        if (!(o instanceof Mint)) return false;
        Mint other = (Mint)o;
        return x == other.x;
    }

    public int hashCode() {
        return Long.hashCode(x);
    }
}

class MathUtils {

    public static long powMod(long value, long exponent, int modulo) {
        if (exponent < 0) throw new IllegalArgumentException("negative exponent");
        if (modulo == 1) return 0;
        if (value >= modulo) value %= modulo;
        if (value < 0) value = value % modulo + value;
        long res = 1;
        while (exponent > 0) {
            if ((exponent & 1) == 1) {
                res = res * value % modulo;
            }
            value = value * value % modulo;
            exponent >>= 1;
        }
        return res;
    }

    private static int factPrevMod;
    private static Mint[] fact;
    public static Mint fact(int n) {
        if(factPrevMod != Mint.getMod()) {
            fact = null;
            factPrevMod = Mint.getMod();
        }
        if (fact == null || n >= fact.length){
            fact = new Mint[Math.min(Mint.getMod(), Math.max(n+1,fact==null ? 100010 : fact.length * 2))];
            for (int i = 0; i < fact.length; i++){
                fact[i] = i == 0 ? Mint.ONE : fact[i-1].mul(i);
            }
        }
        return fact[n];
    }

    private static int ifactPrevMod;
    private static Mint[] ifact;
    public static Mint ifact(int n) {
        if(ifactPrevMod != Mint.getMod()) {
          ifact = null;
          ifactPrevMod = Mint.getMod();
        }
        if(ifact==null || n >= ifact.length) {
            ifact = new Mint[Math.min(Mint.getMod(), Math.max(n + 1, ifact == null ? 100010 : ifact.length * 2))];
            for(int i=ifact.length-1;i>=0;i--){
                ifact[i] = i == ifact.length-1 ? fact(i).mulInv() : ifact[i+1].mul(i+1);
            }
        }
        return ifact[n];
    }

    public static Mint comb(int n, int k) {
        if (n<0 || k<0 || n-k < 0) return Mint.ZERO;
        return fact(n).mul(ifact(k)).mul(ifact(n - k));
    }

    public static long inverse(long value, int modPrime) {
        return powMod(value, modPrime - 2, modPrime);
    }

    public static Mint catalan(int n, int k) {
        if (n<0 || k<0 || k>n) return Mint.ZERO;
        return comb(n+k, n).minus(comb(n+k,n+1));
    }

    public static Mint catalanTransposed(int n, int k) {
        if (n == 0) return k == 0 ? Mint.ONE : Mint.ZERO;
        return catalan(n-1,n-k);
    }

}

class Debug {
    public static void print(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }
}