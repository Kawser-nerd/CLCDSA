import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            solve(in);
        }
    }

    private static void solve(Scanner in) {
        int N = in.nextInt();
        Map<Integer, Yama> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            int a = in.nextInt();
            Yama yama = new Yama(a, i);
            map.put(a, yama.merge(map.get(a)));
        }
        List<Yama> list = new ArrayList<>(map.values());
        Collections.sort(list);

        long[] freq = new long[N];
        for (int i = 0; i < list.size(); i++) {
            Yama y = list.get(i);
            if (i + 1 < list.size()) {
                Yama z = list.get(i + 1);
                freq[y.mini] += y.count * (y.a - z.a);
                z.merge(y);
            } else {
                freq[y.mini] += y.count * y.a;
            }
        }

        StringBuilder ans = new StringBuilder();
        for (long f : freq) {
            ans.append(f).append('\n');
        }
        System.out.println(ans);
    }
}

class Yama implements Comparable<Yama> {
    long a, count;
    int mini;

    Yama(int a, int i) {
        this.a = a;
        mini = i;
        count = 1;
    }

    Yama merge(Yama o) {
        if (o != null) {
            mini = Math.min(mini, o.mini);
            count += o.count;
        }
        return this;
    }

    @Override
    public int compareTo(Yama o) {
        return Long.compare(o.a, a);
    }

    @Override
    public String toString() {
        return String.format("(a=%d,mini=%d,count=%d)", a, mini, count);
    }
}

class Scanner implements Closeable {
    private final InputStream stream;
    private final byte[] buf = new byte[1024];
    private int cur;
    private int num;

    Scanner(InputStream stream) {
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