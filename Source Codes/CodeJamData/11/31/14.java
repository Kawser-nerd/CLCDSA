import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class R1CA {

    /**
     * Google Code Jam Round 1C 2011 Problem A. Square Tiles
     * 
     * @author dkorduban
     */
    public static void main(String[] args) {
        try {
            new R1CA().solve();
        } catch (Exception e) {
            e.printStackTrace();
            throw new IllegalStateException();
        }

    }

    private void solve() throws FileNotFoundException {
        // Scanner in = new Scanner(System.in);
        Scanner in = new Scanner(new File("A-large.in"));
        // PrintWriter out = new PrintWriter(System.out);
        PrintWriter out = new PrintWriter("A-large.out");
        int testCount = in.nextInt();
        for (int test = 1; test <= testCount; ++test) {
            int n = in.nextInt();
            int m = in.nextInt();
            char[][] a = new char[n][];
            for (int i = 0; i < n; ++i) {
                a[i] = in.next().toCharArray();
            }
            for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < m - 1; ++j) {
                    if (a[i][j] == '#' && a[i + 1][j] == '#'
                            && a[i][j + 1] == '#' && a[i + 1][j + 1] == '#') {
                        for (int di = 0; di < 2; ++di) {
                            for (int dj = 0; dj < 2; ++dj) {
                                a[i + di][j + dj] = ((di + dj) % 2 == 0) ? '/'
                                        : '\\';
                            }
                        }
                    }
                }
            }
            boolean bad = false;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] == '#') {
                        bad = true;
                    }
                }

            }
            out.printf("Case #%d:\n", test);
            if (bad) {
                out.printf("Impossible\n");
            } else {
                for (int i = 0; i < n; ++i) {
                    out.println(a[i]);
                }
            }
        }
        out.flush();
    }

}
