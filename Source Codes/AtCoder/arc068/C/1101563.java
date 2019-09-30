import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        try (SScanner in = new SScanner(System.in)) {
            solve(in);
        }
    }

    @SuppressWarnings("unchecked")
    private static void solve(SScanner in) {
        int N = in.nextInt(), M = in.nextInt();
        int[] l = new int[N + 1], r = new int[N + 1];
        List<Integer>[] nByLen = new List[M + 1];

        for (int n = 1; n < N + 1; n++) {
            l[n] = in.nextInt();// 1 <= l <= r <= M
            r[n] = in.nextInt();
            int len = r[n] - l[n] + 1;
            if (nByLen[len] == null) {
                nByLen[len] = new ArrayList<>();
            }
            nByLen[len].add(n);
        }

        int accum = N;
        Fenwick F = new Fenwick(M);

        StringBuilder ans = new StringBuilder();
        for (int d = 1; d < M + 1; d++) {
            int sum = accum;
            for (int e = d; e < M + 1; e += d) {
                sum += F.accum(e);
            }
            if (nByLen[d] != null) {
                accum -= nByLen[d].size();
                for (int n : nByLen[d]) {
                    F.add(l[n], 1);
                    F.add(r[n] + 1, -1);
                }
            }
            ans.append(sum).append('\n');
        }
        System.out.println(ans);
    }
}

class Fenwick {
    private final int[] fenwick;

    public Fenwick(int n) {
        fenwick = new int[n + 1];
    }

    public int accum(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += fenwick[i];
        }
        return sum;
    }

    public int sum(int begin, int end) {
        return accum(end) - accum(begin - 1);
    }

    public void add(int i, int a) {
        for (; i < fenwick.length; i += i & -i) {
            fenwick[i] += a;
        }
    }
}

class SScanner implements Closeable {
    private final InputStream stream;
    private final byte[] buf = new byte[1024];
    private int cur;
    private int num;

    SScanner(InputStream stream) {
        this.stream = stream;
    }

    int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt();
        return a;
    }

    int nextInt() {
        return (int) nextLong();
    }

    long nextLong() {
        int c = read();
        while (isdel(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long l = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            l *= 10;
            l += c - '0';
            c = read();
        } while (!isdel(c));
        return l * sgn;
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    String next() {
        int c = read();
        while (isdel(c))
            c = read();
        StringBuilder s = new StringBuilder();
        do {
            s.appendCodePoint(c);
            c = read();
        } while (!isdel(c));
        return s.toString();
    }

    private int read() {
        if (num == -1)
            throw new InputMismatchException();
        if (cur >= num) {
            cur = 0;
            try {
                num = stream.read(buf);
            } catch (Exception e) {
                throw new InputMismatchException();
            }
            if (num <= 0)
                return -1;
        }
        return buf[cur++];
    }

    private boolean isdel(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    @Override
    public void close() {
        try {
            stream.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}