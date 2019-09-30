import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;

public class Main {
    private static final int MOD = 1_000_000_007;

    public static void main(String[] args) {
        try (CustomReader in = new CustomReader()) {
            new Main().execute(in);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void execute(CustomReader in) throws IOException {
        final int N = Integer.parseInt(in.readLine());
        int[] a = in.readLineAsIntArray();
        long total = 0;
        long subTotal = 1;
        int seq = 1;
        for (int i = 1; i < N; i++) {
            if (a[i] > a[i - 1]) {
                seq++;
                subTotal += seq;
            } else {
                total += subTotal;
                subTotal = 1;
                seq = 1;
            }
        }
        total += subTotal;
        System.out.println(total);
    }


    static class CustomReader extends BufferedReader {

        private static final int DEFAULT_BUF_SIZE = 2048;
        // private static final int DEFAULT_BUF_SIZE = 4096;
        // private static final int DEFAULT_BUF_SIZE = 8192;
        //private static final int DEFAULT_BUF_SIZE = 16384;
        // private static final int DEFAULT_BUF_SIZE = 1048576;

        public CustomReader() throws IOException {
            super(new InputStreamReader(System.in), DEFAULT_BUF_SIZE);
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