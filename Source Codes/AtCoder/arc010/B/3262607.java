/**
 * ??????
 */

import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.util.Calendar;
import java.util.HashSet;

// year?month?day????????
public class Main {
    static final char dlm = '/';
    static final int y = 2012;
    static final int starty = 1900;
    static final int subm = 1;

    static Calendar cal = Calendar.getInstance();

    static int[] ymd = new int[3];
    static HashSet<String> hs = new HashSet<String>();

    static String S;

    // year?month?day????????
    public static void main(String[] args) throws IOException {
        FastScanner fs = new FastScanner();
        final int N = fs.nextInt();

        for (int i = 0; i < N; i++) {
            S = fs.next();

            setymd();

            while (true) {
                // ?????????????
                if (hs.contains(S)) {
                    addday(1);
                    if (y < ymd[0]) break;
                    sets();
                } else {
                    // ???????????
                    int dow = cal.get(Calendar.DAY_OF_WEEK);

                    // ??
                    if (dow == Calendar.SUNDAY || dow == Calendar.SATURDAY) {
                        addday(1);
                        if (y < ymd[0]) break;
                        sets();
                    } else {
                        // ????
                        hs.add(S);
                        break;
                    }
                }
            }
        }

        ymd[0] = y;
        ymd[1] = 1;
        ymd[2] = 1;

        // Calender
        // month : 0-indexed
        cal.set(ymd[0], ymd[1] - subm, ymd[2]);

        int ans = -1;
        int days = 0;

        while (ymd[0] == y)
        {
            int dow = cal.get(Calendar.DAY_OF_WEEK);

            // ??
            if (dow == Calendar.SUNDAY || dow == Calendar.SATURDAY) days++;
            else
            {
                sets();

                // ??????
                if (hs.contains(S)) days++;
                else {
                    // ??????
                    ans = Math.max(ans, days);
                    days = 0;
                }
            }

            // ?????
            addday(1);
        }

        ans = Math.max(ans, days);
        System.out.println(ans);
    }

    static void setymd() {
        String[] tmp = S.split(String.valueOf(dlm));
        ymd[0] = y;
        ymd[1] = Integer.parseInt(tmp[0]);
        ymd[2] = Integer.parseInt(tmp[1]);

        // Calender
        // month : 0-indexed
        cal.set(ymd[0], ymd[1] - subm, ymd[2]);
    }

    static void addday(int day) {
        cal.add(Calendar.DAY_OF_MONTH, day);

        ymd[0] = cal.get(Calendar.YEAR);
        ymd[1] = cal.get(Calendar.MONTH) + 1;
        ymd[2] = cal.get(Calendar.DATE);
    }

    static void sets() {
        S = String.format("%d/%d", ymd[1], ymd[2]);
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