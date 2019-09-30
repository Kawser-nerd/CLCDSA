import java.io.*;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

/**
 * @author Ivan Romanov
 */
public class B {

    private static final String PROBLEM = "B";

    //private static final String TEST = "small-attempt1";
    private static final String TEST = "large";

    private String solve() throws IOException {
        char[] a = nextToken().toCharArray();
        for (int pref = a.length - 2; pref >= 0; pref--) {
            char ch = '9' + 1;
            int index = -1;
            for (int i = pref + 1; i < a.length; i++) {
                if (a[i] > a[pref] && ch > a[i]) {
                    ch = a[i];
                    index = i;
                }
            }
            if (ch <= '9') {
                a[index] = a[pref];
                a[pref] = ch;
                if (pref + 1 < a.length) {
                    Arrays.sort(a, pref + 1, a.length);
                }
                return new String(a);
            }
        }
        a = (new String(a) + "0").toCharArray();
        Arrays.sort(a);
        for (int i = 0; i < a.length; i++) {
            if (a[i] != '0') {
                a[0] = a[i];
                a[i] = '0';
                break;
            }
        }
        return new String(a);
    }

    private BufferedReader reader;

    private StringTokenizer tt = new StringTokenizer("");

    private String nextToken() throws IOException {
        while (!tt.hasMoreTokens()) {
            tt = new StringTokenizer(reader.readLine());
        }
        return tt.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private void run() throws IOException {
        reader = new BufferedReader(new FileReader(PROBLEM + "-" + TEST + ".in"));
        PrintWriter writer = new PrintWriter(new File(PROBLEM + "-" + TEST + ".out"));
        try {
            int n = nextInt();
            for (int i = 0; i < n; i++) {
                writer.print("Case #" + (i + 1) + ": ");
                writer.print(solve());
                writer.println();
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new B().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}