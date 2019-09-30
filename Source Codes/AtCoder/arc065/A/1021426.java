import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    void init() throws FileNotFoundException {
        try {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        } catch (Exception e) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }
    }

    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            try {
                tok = new StringTokenizer(in.readLine(), " :");
            } catch (Exception e) {
                return null;
            }
        }
        return tok.nextToken();
    }

    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    int[] readIntArray(int size) throws IOException {
        int[] res = new int[size];
        for (int i = 0; i < size; i++) {
            res[i] = readInt();
        }
        return res;
    }

    long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }

    <T> List<T>[] createGraphList(int size) {
        List<T>[] list = new List[size];
        for (int i = 0; i < size; i++) {
            list[i] = new ArrayList<>();
        }
        return list;
    }

    public static void main(String[] args) {
        new Thread(null, new Main(), "", 1l * 200 * 1024 * 1024).start();
    }

    long timeBegin, timeEnd;

    void time() {
        timeEnd = System.currentTimeMillis();
        System.err.println("Time = " + (timeEnd - timeBegin));
    }

    long memoryTotal, memoryFree;

    void memory() {
        memoryFree = Runtime.getRuntime().freeMemory();
        System.err.println("Memory = " + ((memoryTotal - memoryFree) >> 10)
                + " KB");
    }

    public void run() {
        try {
            timeBegin = System.currentTimeMillis();
            memoryTotal = Runtime.getRuntime().freeMemory();
            init();
            solve();
            out.close();
            if (System.getProperty("ONLINE_JUDGE") == null) {
                time();
                memory();
            }
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    long gcd(long a, long b) {
        return a == 0 ? b : gcd(b % a, a);
    }

    long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    String[] temps = {"dream", "dreamer", "erase", "eraser"};

    boolean eq(char[] a, int from, String s) {
        if (from < 0) return false;
        for (int i = 0; i < s.length(); i++) {
            if (a[from + i] != s.charAt(i)) return false;
        }
        return true;
    }

    void solve() throws IOException {
        char[] a = readString().toCharArray();
        boolean[] dp = new boolean[a.length + 1];
        dp[0] = true;
        for (int i = 1; i <= a.length; i++) {
            boolean ok = false;
            for (String s : temps) {
                if (eq(a, i - s.length(), s) && dp[i - s.length()]) ok = true;
            }
            dp[i] = ok;
        }
        out.println(dp[a.length] ? "YES" : "NO");
    }


} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.