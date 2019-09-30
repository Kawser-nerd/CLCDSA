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
        final String S = in.readLine();
        final String T = in.readLine();
        List<String> candidates = new ArrayList<>();

        for (int i = 0, bound = S.length() - T.length(); i <= bound; i++) {
            if (match(S, T, i)) {
                String key = S.substring(0, i).replace('?', 'a') + T + S.substring(i + T.length(), S.length()).replace('?', 'a');
                candidates.add(key);
            }
        }
        Collections.sort(candidates);

        System.out.println(candidates.size() > 0 ? candidates.get(0) : "UNRESTORABLE");
    }

    private boolean match(String s, String t, int pos) {
        for (int i = 0; i < t.length(); i++) {
            if ( s.charAt(pos+i) == '?'){
                continue;
            }if(s.charAt(pos + i) == t.charAt(i)) {
                continue;
            }
            return false;
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