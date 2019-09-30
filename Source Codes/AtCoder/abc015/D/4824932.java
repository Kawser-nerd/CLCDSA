import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    private int H;
    private int W;

    public static void main(String[] args) {
        try (CustomReader in = new CustomReader()) {
            new Main().execute(in);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void execute(CustomReader in) throws IOException {
        final int W = in.readLineAsInt();
        int[] l2 = in.readLineAsIntArray();
        final int N = l2[0];
        final int K = l2[1];

        ScreenShot[] scs = new ScreenShot[N];
        for (int i = 0; i < N; i++) {
            int[] l = in.readLineAsIntArray();
            scs[i] = new ScreenShot(l[0], l[1]);
        }

        int[][][] dp = new int[N + 1][K + 1][W + 1];

        for (int i = 1; i <= N; i++) {
            ScreenShot sc = scs[i - 1];
            for (int k = 0, bound = Math.min(K, i); k <= bound; k++) {
                for (int w = 0; w <= W; w++) {
                    if (dp[i - 1][k][w] > 0) {
                        dp[i][k][w] = dp[i - 1][k][w];
                    }
                }
            }
            if(sc.width<=W) {
                dp[i][1][sc.width] = Math.max(sc.importance, dp[i][1][sc.width]);
            }
            for (int k = 0, bound = Math.min(K, i); k < bound; k++) {
                for (int w = 0; w <= W; w++) {
                    if (dp[i - 1][k][w] > 0 && w + sc.width <= W) {
                        dp[i][k + 1][w + sc.width] = Math.max(dp[i - 1][k][w] + sc.importance, dp[i][k + 1][w + sc.width]);
                    }
                }
            }

/*
            System.out.println("i=" + i);
            for (int k = 0; k <= K; k++) {
                System.out.println("k=" + k + "  " + Arrays.toString(dp[i][k]));
            }
            System.out.println("---");
*/


        }

        int maxValue = 0;
        for (int k = 1; k <= K; k++) {
            for (int w = 0; w <= W; w++) {
                maxValue = Math.max(maxValue, dp[N][k][w]);
            }
        }

        System.out.println(maxValue);
    }

    class ScreenShot {
        public final int width;
        public final int importance;

        public ScreenShot(int w, int i) {
            this.width = w;
            this.importance = i;
        }
    }

    static class CustomReader extends BufferedReader {

        private static final int DEFAULT_BUF_SIZE = 2048;
        // private static final int DEFAULT_BUF_SIZE = 4096;
        //private static final int DEFAULT_BUF_SIZE = 8192;
        //private static final int DEFAULT_BUF_SIZE = 16384;
        // private static final int DEFAULT_BUF_SIZE = 1048576;

        public CustomReader() throws IOException {
            super(new InputStreamReader(System.in), DEFAULT_BUF_SIZE);
        }


        public int readLineAsInt() throws IOException {
            return Integer.parseInt(this.readLine());
        }


        public int[] readLineAsIntArray() throws IOException {
            String[] strArray = this.readLine().split(" ");
            int[] intArray = new int[strArray.length];
            for (int i = 0, n = strArray.length; i < n; i++) {
                intArray[i] = Integer.parseInt(strArray[i]);
            }
            return intArray;
        }

        public int[][] readAsIntMatrix(int rows, int columns) throws IOException {
            int[][] matrix = new int[rows][columns];
            for (int i = 0; i < rows; i++) {
                String[] r = this.readLine().split(" ");
                for (int j = 0; j < columns; j++) {
                    matrix[i][j] = Integer.parseInt(r[j]);
                }
            }
            return matrix;
        }
    }
}