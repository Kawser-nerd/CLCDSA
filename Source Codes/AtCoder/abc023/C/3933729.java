import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.io.PrintWriter;

import java.util.Arrays;
import java.util.ArrayList;

@SuppressWarnings("unchecked")
public class Main {
    static int[] r;
    static int[] c;
    static int[] rcnt;
    static int[] ccnt;

    static ArrayList<Integer>[] rclm;

    static ArrayList<Integer>[] cclm;

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        final int R = nextInt();
        final int C = nextInt();
        final int K = nextInt();
        final int N = nextInt();

        r = new int[R];
        c = new int[C];

        // ???
        // 1-indexed
        rcnt = new int[N + 1];
        ccnt = new int[N + 1];

        Arrays.fill(r, 0);
        Arrays.fill(c, 0);
        Arrays.fill(rcnt, 0);
        Arrays.fill(ccnt, 0);

        rclm = new ArrayList[R];
        for (int i = 0; i < R; i++) rclm[i] = new ArrayList<>();

        cclm = new ArrayList[C];
        for (int i = 0; i < C; i++) cclm[i] = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            // 0-indexed
            int row = nextInt() - 1;
            int column = nextInt() - 1;

            r[row]++;
            c[column]++;
            rclm[row].add(column);
            cclm[column].add(row);
        }

        for (int i = 0; i < R; i++) rcnt[r[i]]++;

        for (int i = 0; i < C; i++) ccnt[c[i]]++;

        long ans = 0;

        // ????????
        for (int i = 0; i < rclm.length; i++) {
            if (rclm[i].size() == 0) continue;

            // ? ? ????? ?? ??
            // ????? = K - ????? + 1
            int num = K - r[i] + 1;

            // ???? ??? ??
            long exclude = 0;

            for (int clm : rclm[i]) {
                if (num <= 0) continue;

                if (c[clm] == num) ans++;
                else if (c[clm] == num - 1) exclude++;
            }

            // ? ? ????? ??
            // ????? = K - ?????
            num--;

            if (num < 0) continue;

            ans += ccnt[num];

            ans -= exclude;
        }

        // ?????
        ans += rcnt[0] * ccnt[K];

        out.println(ans);

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
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }
    static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
    static boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    static String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    static long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
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
            } else if(b == -1 || !isPrintableChar(b)) {
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