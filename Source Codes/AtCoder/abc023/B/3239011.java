import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            FastScanner fs = new FastScanner();

            final int N = fs.nextInt();
            final String S = fs.next();

            Character[] C = toCharacterArray(S);

            Arrays.sort(C);

            int ans = -1;

            if ('a' <= C[0] && C[N - 1] <= 'c') {
                int ope = 0;
                StringBuilder sb = new StringBuilder();

                do {
                    sb = command(ope, sb);
                    if (S.equals(sb.toString())) {
                        ans = ope;
                        break;
                    }
                    ope++;
                } while (sb.length() < N);
            }

            System.out.println(ans);
        }
    }

    static Character[] toCharacterArray( String s ) {
        if ( s == null ) {
            return null;
        }

        int len = s.length();
        Character[] array = new Character[len];
        for (int i = 0; i < len ; i++) {
            array[i] = new Character(s.charAt(i));
        }

        return array;
    }

    static StringBuilder command(int i, StringBuilder sb) {
        if (i != 0) {
            if (i % 3 == 0) {
                sb.insert(0, "b");
                sb.append("b");
            } else if (i % 3 == 1) {
                sb.insert(0, "a");
                sb.append("c");
            } else {
                sb.insert(0, "c");
                sb.append("a");
            }
        } else {
            sb.append("b");
        }
        return sb;
    }
}

class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean hasNextByte() {
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
    private int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }
    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
    public boolean hasNext() {
        while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public long nextLong() {
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
        while(true) {
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
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
            throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() {
        return Double.parseDouble(next());
    }
}