import java.util.*;
import java.io.*;

public class PC implements Runnable {
    static class Data {
        private StringTokenizer tok;
        private final BufferedReader rd;
        private final PrintWriter wr;

        Data() {
            tok = null;
            rd = new BufferedReader(new InputStreamReader(System.in));
            wr = new PrintWriter(System.out);
        }

        Data(String name) throws IOException {
            tok = null;
            rd = new BufferedReader(new FileReader(new File(name + ".in")));
            wr = new PrintWriter(new File(name + ".out"));
        }

        void println(String line) {
            wr.println(line);
        }

        void close() throws IOException {
            rd.close();
            wr.close();
        }

        String nextToken() throws IOException {
            while (tok == null || !tok.hasMoreTokens()) {
                tok = new StringTokenizer(rd.readLine());
            }
            return tok.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        static Data console() {
            return new Data();
        }

        static Data files(String name) throws IOException {
            return new Data(name);
        }
    }

    public static void main(String[] args) {
        new Thread(new PC()).start();
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (Throwable t) {
            throw new RuntimeException(t);
        }
    }

    private void solve() throws IOException {
        Data data = Data.files("c");

        int t = data.nextInt();
        for (int i = 0; i < t; ++i) {
            int res = subsolve(data);
            data.println(String.format("Case #%d: %s", i + 1, (res == Integer.MAX_VALUE) ? "IMPOSSIBLE" : res));
        }

        data.close();
    }

    private int subsolve(Data data) throws IOException {
        int hd = data.nextInt();
        int ad = data.nextInt();
        int hk = data.nextInt();
        int ak = data.nextInt();
        int b = data.nextInt();
        int d = data.nextInt();
        int bres = Integer.MAX_VALUE;
        for (int nb = 0; nb <= 100; ++nb) {
            for (int nd = 0; nd <= 100; ++ nd) {
                int cres = turns(hd, ad, hk, ak, b, d, nb, nd);
                bres = Math.min(bres, cres);
            }
        }
        return bres;
    }

    private int turns(int hd, int ad, int hk, int ak, int b, int d, int nb, int nd) {
        int chd = hd;
        int chk = hk;
        int nbr = nb;
        int ndr = nd;
        int res = 0;
        while (res <= 1000) {
            ++res;
            if (chk - ad <= 0) {
                return res;  // finishing move
            }
            if (ndr > 0) {
                int dak = Math.max(0, ak - d);
                if (chd - dak <= 0) {
                    chd = hd;  // cure
                } else {
                    ak = dak;  // debuff
                    --ndr;
                }
            } else if (chd - ak <= 0) {
                chd = hd;  // cure
            } else if (nbr > 0) {
                ad += b;  // buff
                --nbr;
            } else {
                chk -= ad;  // attack
                if (chk <= 0) {
                    return res;
                }
            }

            chd -= ak;
            if (chd <= 0) {
                return Integer.MAX_VALUE;
            }
        }
        return Integer.MAX_VALUE;
    }
}
