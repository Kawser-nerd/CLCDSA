import java.io.*;

public class CodeJam2014R1C3 {

    private static int min;
    private static boolean A[][];
    private static int B[][];

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("C-small.in")));
            PrintWriter pw = new PrintWriter(new FileOutputStream("C-small.out"));
            //BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("C-large.in")));
            //PrintWriter pw = new PrintWriter(new FileOutputStream("C-large.out"));
            String line = br.readLine();
            int T = Integer.parseInt(line);
            for (int i = 0; i < T; i++) {
                System.out.println((i + 1) + " / " + T + "...");

                line = br.readLine();
                String[] values = line.split(" ");
                int M = Integer.parseInt(values[0]);
                int N = Integer.parseInt(values[1]);
                int K = Integer.parseInt(values[2]);
                min = K;

                for (int j = 0; j < 1 << M * N; j++) {
                    checkConfig(M, N, j, K);
                }

                pw.println("Case #" + (i + 1) + ": " + min);

            }
            pw.close();
            System.out.println("DONE");
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static void checkConfig(int m, int n, int bits, int total) {
        A = new boolean[m][n];
        int k = 0;
        int used = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = ((bits >> k) & 1) > 0;
                if (A[i][j]) {
                    used++;
                }
                k++;
            }
        }

        if (used > min) {
            return;
        }

        int enclosed = 0;
        B = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j]) {
                    B[i][j] = 1;
                } else {
                    B[i][j] = 2;
                }
            }
        }
        //display(B);
        fill(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (B[i][j] == 1) {
                    enclosed++;
                }
            }
        }
        if (enclosed >= total) {
            min = used;
        }

    }

    private static void display(int[][] b) {
        for (int i = 0; i < b.length; i++) {
            for (int j = 0; j < b[i].length; j++) {
                System.out.print(b[i][j]);
            }
            System.out.println();
        }
    }

    private static void fill(int m, int n) {
        int current = 2;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (B[i][j] == 2) {
                    current++;
                    boolean result = fill(i, j, m, n, current);
                    if (result) {
                        for (int ii = 0; ii < m; ii++) {
                            for (int jj = 0; jj < n; jj++) {
                                if (B[ii][jj] == current) {
                                    B[ii][jj] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    private static boolean fill(int i, int j, int m, int n, int current) {
        if (B[i][j] == 2) {
            B[i][j] = current;
            boolean result = (i > 0 && i < m - 1 && j > 0 && j < n - 1);
            if (i > 0) {
                result &= fill(i - 1, j, m, n, current);
            }
            if (i < m - 1) {
                result &= fill(i + 1, j, m, n, current);
            }
            if (j > 0) {
                result &= fill(i, j - 1, m, n, current);
            }
            if (j < n - 1) {
                result &= fill(i, j + 1, m, n, current);
            }
            return result;
        }
        return true;
    }
}
