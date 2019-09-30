
import java.io.*;
import java.util.StringTokenizer;

public class D {

    private String solveTest() throws IOException {
        int n = nextInt();
        int l = nextInt();
        String[] g = new String[n];
        for (int i = 0; i < n; i++) {
            g[i] = next();
        }
        String b = next();
        for (int i = 0; i < n; i++) {
            if (g[i].equals(b)) {
                return "IMPOSSIBLE";
            }
        }

        String x = "";
        for (int i = 0; i < l; i++) {
            x += b.charAt(i) == '0' ? '1' : '0';
            x += "?";
        }

        int[] s = new int[l];
        int m = 0;
        for (int i = 0; i < l; i++) {
            if (i == 0 || b.charAt(i) != b.charAt(i - 1)) {
                s[m++] = 1;
            } else {
                s[m - 1]++;
            }
        }

        String y = "";
        char c = b.charAt(0);
//        for (int i = 0; i < m; i++) {
//            System.out.println(s[i]);
//        }
//        System.out.println(b);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < s[i] - 1; j++) {
                y += c;
            }
            if (i < m - 1) {
                for (int j = 0; j < s[i + 1]; j++) {
                    y += c == '0' ? '1' : '0';;
                }
                y += c;
            }
            c = c == '0' ? '1' : '0';
        }

        if (y.length() == 0) {
            y += x.charAt(0);
            System.out.println("!!!!!!" + x + " " + y);
        }

        if (x.length() + y.length() > 200) throw new RuntimeException();
        if (x.length() == 0 || y.length() == 0) throw new RuntimeException();

        return x + " " + y;
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            String res = solveTest();
            System.out.println("Case #" + (i + 1) + ": " + res);
            out.println("Case #" + (i + 1) + ": " + res);
        }
    }


    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws FileNotFoundException {
        new D().run();
    }

    private void run() throws FileNotFoundException {
        br = new BufferedReader(new FileReader(this.getClass().getSimpleName().substring(0, 1) + ".in"));
        out = new PrintWriter(this.getClass().getSimpleName().substring(0, 1) + ".out");
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

}