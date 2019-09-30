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
        int[] nm = in.readLineAsIntArray();
        final int N = nm[0];
        final int M = nm[1];
        Requirement[] requirements = new Requirement[M];
        for (int i = 0; i < M; i++) {
            int[] r = in.readLineAsIntArray();
            requirements[i] = new Requirement(r[0], r[1]);
        }

        Arrays.sort(requirements, (Requirement r1, Requirement r2) -> r1.right - r2.right);
        int count = 0;
        int pos = 0;
        for(int i=0; i<M; i++){
            if(pos>requirements[i].left){
                continue;
            }
            pos = requirements[i].right;
            count++;
        }
        System.out.println(count);

    }

    class Requirement{
        public final int left;
        public final int right;

        public Requirement(int l, int r) {
            this.left = l;
            this.right = r;
        }
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