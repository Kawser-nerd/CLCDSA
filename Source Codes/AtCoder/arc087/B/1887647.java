import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;


public class Main {

    char[] s;
    int x,y,N;
    boolean[][] xdp,ydp;
    ArrayList<Integer> vx,vy;

    private void solve() {
        s = next().toCharArray();
        N = s.length;
        x = nextInt();
        y = nextInt();

        vx = new ArrayList<>();
        vy = new ArrayList<>();

        int countF = 0;
        int countT = 0;
        for(int i = 0;i < N;i++) {
            if (s[i] == 'F') {
                countF++;
            } else {
                if (countT % 2 == 0) {
                    vx.add(countF);
                } else {
                    vy.add(countF);
                }
                countT++;
                countF = 0;
            }
        }
        if (countF > 0) {
            if (countT % 2 == 0) {
                vx.add(countF);
            } else {
                vy.add(countF);
            }
        }

        xdp = new boolean[vx.size() + 1][8000 * 2 + 1];
        ydp = new boolean[vy.size() + 1][8000 * 2 + 1];

        int add = 0;
        if (s[0] == 'T') {
            xdp[0][8000] = true;
        } else {
            xdp[1][8000 + vx.get(0)] = true;
            add++;
        }
        for(int i = 0 + add;i < vx.size();i++) {
            for(int j = 0;j < 8000 * 2 + 1;j++) {
                if (!xdp[i][j]) continue;
                if(j - vx.get(i) >= 0) {
                    xdp[i + 1][j - vx.get(i)] |= xdp[i][j];
                }

                if (j + vx.get(i) < 8000 * 2 + 1) {
                    xdp[i + 1][j + vx.get(i)] |= xdp[i][j];
                }
            }
        }

        ydp[0][8000] = true;
        for(int i = 0;i < vy.size();i++) {
            for(int j = 0;j < 8000 * 2 + 1;j++) {
                if (!ydp[i][j]) continue;
                if(j - vy.get(i) >= 0) {
                    ydp[i + 1][j - vy.get(i)] |= ydp[i][j];
                }

                if (j + vy.get(i) < 8000 * 2 + 1) {
                    ydp[i + 1][j + vy.get(i)] |= ydp[i][j];
                }
            }
        }

        if (xdp[vx.size()][x + 8000] && ydp[vy.size()][y + 8000]) {
            out.println("Yes");
            return;
        }
        out.println("No");
    }

    public static void main(String[] args) {
        out.flush();
        new Main().solve();
        out.close();
    }

    /* Input */
    private static final InputStream in = System.in;
    private static final PrintWriter out = new PrintWriter(System.out);
    private final byte[] buffer = new byte[2048];
    private int p = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
        if (p < buflen)
            return true;
        p = 0;
        try {
            buflen = in.read(buffer);
        } catch (IOException e) {
            e.printStackTrace();
        }
        if (buflen <= 0)
            return false;
        return true;
    }

    public boolean hasNext() {
        while (hasNextByte() && !isPrint(buffer[p])) {
            p++;
        }
        return hasNextByte();
    }

    private boolean isPrint(int ch) {
        if (ch >= '!' && ch <= '~')
            return true;
        return false;
    }

    private int nextByte() {
        if (!hasNextByte())
            return -1;
        return buffer[p++];
    }

    public String next() {
        if (!hasNext())
            throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = -1;
        while (isPrint((b = nextByte()))) {
            sb.appendCodePoint(b);
        }
        return sb.toString();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}