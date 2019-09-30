import java.util.*;
import java.io.*;

class A implements Runnable {

    public void solve() throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
        PrintWriter out = new PrintWriter(new File("A-large.out"));

        int testn = Integer.parseInt(in.readLine());
        for (int test = 0; test < testn; test++) {
            int n = Integer.parseInt(in.readLine());
            int[][] a = new int[n][n];
            for (int i = 0; i < n; i++) {
                String s = in.readLine();
                for (int j = 0; j < n; j++) {
                    a[i][j] = s.charAt(j) - '0';
                }
            }

            int[] last = new int[n];
            for (int i = 0; i < n; i++) {
                last[i] = 0;
                for (int j = 0; j < n; j++) {
                    if (a[i][j] == 1) {
                        last[i] = j;
                    }
                }
            }

            int r = 0;
            for (int i = 0; i < n; i++) {
                int k = -1;
                for (int j = i; j < n; j++) {
                    if (last[j] <= i) {
                        k = j;
                        break;
                    }
                }
                if (k == -1) {
                    System.out.println("FAIL");
                    return;
                }
                r += k - i;
                for (int j = k; j > i; j--) {
                    last[j] = last[j - 1];
                }
            }

            out.println("Case #" + (test + 1) + ": " + r);
            System.out.println("Case #" + (test + 1) + ": " + r);
        }

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
            throw new AssertionError();
        }
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new Thread(new A()).start();
    }
}