
import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class A {

    String[][] letters = {{"zero", "z", "0"},
            {"eight", "g", "8"},
            {"four", "u", "4"},
            {"five", "f", "5"},
            {"seven", "v", "7"},
            {"two", "w", "2"},
            {"three", "t", "3"},
            {"six", "x", "6"},
            {"one", "o",  "1"},
            {"nine", "i", "9"}};


    private String solveTest() throws IOException {
        String s = next();
        int[] l = new int[26];
        for (int i = 0; i < s.length(); i++) {
            l[s.charAt(i) - 'A']++;
        }
        char[] res = new char[s.length()];
        int m = 0;
        for (int i = 0; i < 10; i++) {
            int c = l[letters[i][1].charAt(0) - 'a'];
            for (int j = 0; j < letters[i][0].length(); j++) {
                l[letters[i][0].charAt(j) - 'a'] -= c;
            }
            for (int j = 0; j < c; j++) {
                res[m++] = letters[i][2].charAt(0);
            }
        }
        Arrays.sort(res, 0, m);
        return new String(res, 0, m);
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
        new A().run();
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