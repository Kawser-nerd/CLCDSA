
import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;

public class Erdos implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new Erdos(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();

            out = new PrintWriter(System.out);
            in = new BufferedReader(new FileReader("src/input.txt"));
           out = new PrintWriter("src/erdos.txt");

            Locale.setDefault(Locale.US);
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }
    // solution

    void solve() throws IOException {
        int ct = readInt();
        int n = 0;
        while (ct-- > 0) {
            solveTestCase(++n);
        }
    }

    void solveTestCase(int number) throws IOException {
        int n = readInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = readInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = readInt();
        }
        boolean[][] greater = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (a[j] == a[i]) {
                    greater[j][i] = true;
                }
            }
            for (int j = i - 1; j >= 0; j--) {
                if (a[j] == a[i] - 1) {
                    greater[i][j] = true;
                    break;
                }
            }

            for (int j = i + 1; j < n; j++) {
                if (b[j] == b[i]) {
                    greater[j][i] = true;
                }
            }
            for (int j = i + 1; j < n; j++) {
                if (b[j] == b[i] - 1) {
                    greater[i][j] = true;
                    break;
                }
            }
        }


        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (greater[i][k] && greater[k][j]) {
                        greater[i][j] = true;
                    }
                }
            }
        }
        int[] result = new int[n];
        boolean[] used = new boolean[n];
        Arrays.fill(result, -1);
        for (int i = 0; i < n; i++) {
            int minid = 0;
            int mincount = Integer.MAX_VALUE / 2;
            for (int j = 0; j < n; j++) {
                if (result[j] >= 0) {
                    continue;
                }
                int count = 0;
                if (result[j] == -1) {
                    for (int k = 0; k < n; k++) {
                        if (greater[j][k]) {
                            count++;
                        }
                    }
                }
                if (count < mincount) {
                    mincount = count;
                    minid = j;
                }
            }
            result[minid] = i;
            for (int j = 0; j < n; j++) {
                greater[j][minid] = false;
                greater[minid][j] = false;
            }
        }
        out.print("Case #" + number + ": ");
        for (int i = 0; i < n; i++) {
            out.print((1 + result[i]) + " ");
        }
        out.println();
        System.out.println(number);
    }
}