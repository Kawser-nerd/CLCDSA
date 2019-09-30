import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    private static final PrintWriter sysout = new PrintWriter(System.out, false);

    private static StringTokenizer buffer;

    private static String readLine() {
        buffer = null;
        try {
            return br.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private static String read() {
        if (buffer == null || !buffer.hasMoreTokens()) {
            buffer = new StringTokenizer(readLine());
        }
        return buffer.nextToken();
    }

    private static int readInt() {
        return Integer.parseInt(read());
    }

    private static int[] readIntArray(int loop) {
        int[] result = new int[loop];
        for (int i = 0; i < loop; i++) {
            result[i] = readInt();
        }
        return result;
    }

    private static int[] splitInt() {
        String[] tmp = read().split("");
        int[] result = new int[tmp.length];
        for (int i = 0, n = tmp.length; i < n; i++) {
            result[i] = Integer.parseInt(tmp[i]);
        }
        return result;
    }

    private static long readLong() {
        return Long.parseLong(read());
    }

    private static double readDouble() {
        return Double.parseDouble(read());
    }

    public static void main(String[] args){
        run();
    }

    private static void run() {
        int gohyaku = readInt();
        int hyaku = readInt();
        int goju = readInt();
        int total = readInt();
        int count = 0;
        for (int i = 0; i <= gohyaku; i++) {
            for (int j = 0; j <= hyaku; j++) {
                for (int k = 0; k <= goju; k++) {
                    int result = 500*i + 100*j + 50*k;
                    if (total == result) count++;
                }
            }
        }
        System.out.println(count);
    }
}