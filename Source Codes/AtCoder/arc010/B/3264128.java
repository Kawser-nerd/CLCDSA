import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.util.Calendar;

public class Main {
    static String S;

    static final char dlm = '/';
    static final int y = 2012;
    static final int m = 1;
    static final int subm = 1;

    static Calendar start = Calendar.getInstance();
    static Calendar now = Calendar.getInstance();


    public static void main(String[] args) throws IOException {
        FastScanner fs = new FastScanner();

        final int N = fs.nextInt();
        String[] S = new String[N];

        for (int i = 0; i < N; i++) S[i] = fs.next();

        // ?? ??? ???
        int SUN = -1;
        int SAT = -1;

        // Calender
        // month : 0-indexed
        Calendar tmp = Calendar.getInstance();
        tmp.set(y, m - subm, 1);

        int x = 0;
        while (SUN == -1 || SAT == -1) {
            int dow = tmp.get(Calendar.DAY_OF_WEEK);

            // DAY_OF_WEEK : 1-indexed (Calendar.SUNDAY:1)
            if (Calendar.SUNDAY == dow) SUN = x;
            else if (Calendar.SATURDAY == dow) SAT = x;

            // 1????
            tmp.add(Calendar.DAY_OF_MONTH, 1);
            x++;
        }

        start.set(y, m - subm, 1);
        now.set(y, 12 - subm, 31);

        // 2012? 366?
        // 0-indexed
        int daysOfYear = getDiffDays(now, start);

        // 0-indexed
        // default false
        boolean[] holiday = new boolean[daysOfYear + 1];

        // ????
        // 0-indexed
        for (int i = 0; i <= daysOfYear; i++)
            if (SUN == i % 7 || SAT == i % 7) holiday[i] = true;

        // ??????
        for (int i = 0; i < N; i++) {
            int m = Integer.parseInt(S[i].split(String.valueOf(dlm))[0]);
            int d = Integer.parseInt(S[i].split(String.valueOf(dlm))[1]);
            now.set(y, m - subm, d);
            int diff = getDiffDays(now, start);

            boolean flg = true;
            int j = diff;

            while (flg) {
                if (daysOfYear < j) flg = false;
                else if (!holiday[j]) {
                    holiday[j] = true;
                    flg = false;
                }
                j++;
            }
        }

        int ans = -1;
        int cnt = 0;

        // ??????
        // 0-indexed
        for (int i = 0; i <= daysOfYear; i++) {
            if (holiday[i]) cnt++;
            else {
                ans = Math.max(ans, cnt);
                cnt = 0;
            }
        }

        ans = Math.max(ans, cnt);

        System.out.println(ans);
    }

    /**
     * 2??????
     * java.util.Calendar
     * date1 - date2 ????
     *
     * long? 1970/01/01 00:00:00 GMT ?????
     * 1? (24??) 86,400,000 ???
     */
    public static int getDiffDays(Calendar date1,Calendar date2) {
        long MILLIS_OF_DAY = 1000 * 60 * 60 * 24;

        long milli1 = date1.getTimeInMillis();
        long milli2 = date2.getTimeInMillis();

        long diffDays = (milli1 - milli2) / MILLIS_OF_DAY;
        return (int)diffDays;
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