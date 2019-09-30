import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.Closeable;
import java.io.IOException;
import java.util.Comparator;
import java.util.NoSuchElementException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author HBonsai
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CID solver = new CID();
        solver.solve(1, in, out);
        out.close();
    }

    static class CID {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int N = in.nextInt();
            int M = in.nextInt();
            CityInfo[] cities = new CityInfo[M];
            for (int i = 0; i < M; i++) {
                int pref = in.nextInt();
                int year = in.nextInt();
                CityInfo city = new CityInfo();
                city.pref = pref;
                city.year = year;
                city.inputNo = i;
                cities[i] = city;
            }
            Arrays.sort(cities, Comparator.comparingInt(CityInfo::getPref).thenComparingInt(CityInfo::getYear));
            int nowPref = cities[0].pref;
            int bNo = 1;
            for (int i = 0; i < M; i++) {
                CityInfo city = cities[i];
                if (city.pref != nowPref) {
                    nowPref = city.pref;
                    bNo = 1;
                }
                city.birthNo = bNo;
                bNo++;
            }
            Arrays.sort(cities, Comparator.comparingInt(CityInfo::getInputNo));
            for (int i = 0; i < M; i++) {
                CityInfo city = cities[i];
                String ans = String.format("%06d", city.pref);
                ans += String.format("%06d", city.birthNo);
                out.println(ans);
            }
        }

        class CityInfo {
            public int pref = 0;
            public int year = 0;
            public int inputNo = 0;
            public int birthNo = 0;

            public int getPref() {
                return pref;
            }

            public int getYear() {
                return year;
            }

            public int getInputNo() {
                return inputNo;
            }

        }

    }

    static class FastScanner implements Closeable {
        private final InputStream in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

        public FastScanner(InputStream in) {
            this.in = in;
        }

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
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
            return hasNextByte();
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

        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }

        public void close() {
            try {
                in.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }
}