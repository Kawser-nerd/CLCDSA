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
        int[] nk = in.readLineAsIntArray();
        final int N = nk[0];
        final int K = nk[1];
        final String S = in.readLine();
        char[] chars = S.toCharArray();
        reOrder(S, chars, 0, K);
        System.out.println(String.valueOf(chars));

    }

    private void reOrder(String original, char[] arr, int currentIndex, int k) {
        if (currentIndex == arr.length) {
            return;
        }
        else if (arr.length - currentIndex <= k) {
            Arrays.sort(arr, currentIndex, arr.length);
            return;
        }else{
            int minIndex = findMinCharIndexOoO(original, arr, currentIndex, k);
            assert (minIndex > 0);
            int r = countOoO(original, arr, currentIndex, minIndex);
            swap(arr, currentIndex, minIndex);
            reOrder(original, arr, currentIndex + 1, k - r);
        }
    }

    private int countOoO(String original, char[] arr, int i, int j) {
        int count = 0;
        if (arr[i] == original.charAt(i))
            count++;
        if (arr[j] == original.charAt(j))
            count++;
        if (arr[j] == original.charAt(i))
            count--;
        if (arr[i] == original.charAt(j))
            count--;
        return count;
    }

    private void swap(char[] arr, int i, int j) {
        char tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    private int findMinCharIndexOoO(String s, char[] arr, int offset, int k) {
        char min = (char) 'z' + 1;
        int index = -1;
        for (int i = offset; i < arr.length; i++) {
            if (countOoO(s, arr, offset, i) <= k && arr[i] < min) {
                index = i;
                min = arr[i];
            }
        }
        return index;
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