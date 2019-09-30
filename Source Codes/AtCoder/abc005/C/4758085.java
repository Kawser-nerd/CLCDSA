import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        try (CustomReader in = new CustomReader()) {
            new Main().execute(in);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void execute(CustomReader in) throws IOException {
        final int T = Integer.parseInt(in.readLine());
        final int N = Integer.parseInt(in.readLine());
        int[] tako = in.readLineAsIntArray();
        final int M = Integer.parseInt(in.readLine());
        int[] customers = in.readLineAsIntArray();

        System.out.println(sellable(N, M, tako, customers, T) ? "yes" : "no");
    }

    private boolean sellable(int N, int M, int[] tako, int[] customers, int T) {
        int sold = 0;
        for (int i = 0; i < M; i++) {
            while (sold < N && tako[sold] + T < customers[i]) {
                sold++;
            }
            if (sold == N || tako[sold] > customers[i]) {
                return false;
            }
            sold++;
        }
        return true;
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

        public int[][] readLinesAsIntMatrix(int rows, int columns) throws IOException {
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