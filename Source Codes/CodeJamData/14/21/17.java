import java.io.*;
import java.util.*;

public class Main {
    static final long MOD = 1000000007;
    static boolean fail;
    static String prev;
    
    static int[] parse(String input) {
        int[] res = new int[100];
        int index = 0;
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < input.length(); ) {
            builder.append(input.charAt(i));
            int j = i + 1;
            while (j < input.length() && input.charAt(i) == input.charAt(j)) {
                ++j;
            }
            res[index++] = j - i;
            i = j;
        }
        String key = builder.toString();
        if (prev == null) {
            prev = key;
        } else if (!prev.equals(key)) {
            fail = true;
        }
        return Arrays.copyOfRange(res, 0, index);
    }
    
    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            fail = false;
            prev = null;
            int N = scan.nextInt();
            String[] arr = new String[N];
            for (int i = 0; i < N; ++i) {
                arr[i] = scan.nextToken();
            }
            int[][] map = new int[N][];
            for (int i = 0; i < N; ++i) {
                map[i] = parse(arr[i]);
            }
            System.out.print(String.format("Case #%d: ", taskIndex));
            if (fail) {
                System.out.println("Fegla Won");
            } else {
                int res = 0;
                for (int i = 0; i < map[0].length; ++i) {
                    int max = 1;
                    for (int j = 0; j < N; ++j) {
                        max = Math.max(max, map[j][i]);
                    }
                    int min = Integer.MAX_VALUE;
                    for (int j = 1; j <= max; ++j) {
                        int temp = 0;
                        for (int k = 0; k < N; ++k) {
                            temp += Math.abs(map[k][i] - j);
                        }
                        min = Math.min(min, temp);
                    }
                    res += min;
                }
                System.out.println(res);
            }
        }
    }
}

class FastScanner {
    BufferedReader in;
    StringTokenizer tok;
    
    public FastScanner(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
        tok = new StringTokenizer("");
    }
    
    private String tryReadNextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            throw new InputMismatchException();
        }
    }
    
    public String nextToken() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(next());
        }
        return tok.nextToken();
    }
    
    public String next() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }
    
    public int nextInt() {
        return Integer.parseInt(nextToken());
    }
    
    public double nextDouble() {
        return Double.parseDouble(nextToken());
    }
    
    public long nextLong() {
        return Long.parseLong(nextToken());
    }
    
}