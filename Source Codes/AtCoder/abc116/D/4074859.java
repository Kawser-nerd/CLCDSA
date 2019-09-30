import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.io.PrintWriter;

import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;

// ??
class Sushi implements Comparable<Sushi> {
    // ?? ????
    int t;
    int d;

    Sushi(int t, int d) {
        this.t = t;
        this.d = d;
    }

    // x.compereTo(y)
    // x ? d
    // y ? Sushi.d
    @Override
    public int compareTo(Sushi sushi) {
        return sushi.d - this.d;
    }
}

@SuppressWarnings("unchecked")
public class Main {
    static PriorityQueue<Integer>[] sushiList;
    static PriorityQueue<Sushi> res;

    static ArrayList<Sushi> away;

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        final int N = nextInt();
        final int K = nextInt();

        res = new PriorityQueue<>();

        int kind = 0;

        for (int i = 0; i < N; i++) {
            // 0-indexed
            int t = nextInt() - 1;
            int d = nextInt();

            Sushi sushi = new Sushi(t, d);
            res.add(sushi);
            kind = Math.max(kind, t);
        }

        kind++;

        sushiList = new PriorityQueue[kind];

        for (int i = 0; i < kind; i++)
            sushiList[i] = new PriorityQueue<>();

        boolean[] done = new boolean[kind];

        long cnt = 0;
        long deli = 0;

        for (int i = 0; i < K; i++) {
            Sushi x = res.poll();

            sushiList[x.t].add(x.d);

            deli += x.d;

            if (!done[x.t]) {
                done[x.t] = true;
                cnt++;
            }
        }

        away = new ArrayList<>();

        for (int i = 0; i < kind; i++) {
            while (done[i] && 1 < sushiList[i].size()) {
                int a = sushiList[i].poll();
                away.add(new Sushi(i, a));
            }
        }

        // ??
        Collections.sort(away);

        int dif = K - (int)cnt;
        int min = Math.min(dif, away.size());
        min = Math.min(min, res.size());

        long[] dl = new long[min];

        long score = deli + cnt * cnt;

        int i = 0;
        int idx = -1;
        long dx = deli;

        while (i < min && 0 < res.size()) {
            Sushi y = res.poll();

            if (done[y.t]) continue;

            done[y.t] = true;

            Sushi x = away.get(away.size() - 1 - i);

            dl[i] = dx + y.d - x.d;
            dx = dl[i];

            long now = dx + (cnt + i + 1) * (cnt + i + 1);

            if (score < now) {
                score = now;
                idx = i;
            }

            i++;
        }

        if (-1 < idx) {
            deli = dl[idx];
            cnt += idx + 1;
        }

        out.println(deli + cnt * cnt);

        out.flush();
    }

    // FastScanner start
    static final InputStream in = System.in;
    static final byte[] buffer = new byte[1024];
    static int ptr = 0;
    static int buflen = 0;

    static boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        } else {
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }

    static int readByte() {
        if (hasNextByte())
            return buffer[ptr++];
        else
            return -1;
    }

    static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    static boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr]))
            ptr++;
        return hasNextByte();
    }

    static String next() {
        if (!hasNext())
            throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    static long nextLong() {
        if (!hasNext())
            throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    static int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
            throw new NumberFormatException();
        return (int) nl;
    }

    static double nextDouble() {
        return Double.parseDouble(next());
    }
    // FastScanner end
}