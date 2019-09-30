import java.io.*;
import java.util.*;

public class A {
    PrintWriter out;
    Scanner in;
    String testCase = "a2";

    public static void main(String[] args) throws Exception {
        new A().solve();
    }

    void solve() throws Exception {
        Locale.setDefault(Locale.ENGLISH);
        out = new PrintWriter(new FileOutputStream(testCase + ".out"));
        in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream(testCase + ".in"))));

        int N = in.nextInt();
        for (int t = 1; t <= N; ++t) {
            out.print("Case #" + t + ": ");

            String num = in.next();
            Map<Character, Integer> map = new HashMap<Character, Integer>();
            for (char c : num.toCharArray()) {
                if (map.containsKey(c)) {
                    continue;
                }
                if (map.size() == 0) {
                    map.put(c, 1);
                } else if (map.size() == 1) {
                    map.put(c, 0);
                } else {
                    map.put(c, map.size());
                }
            }

            long result = 0;
            int base = map.size();
            if (base == 1) {
                base = 2;
            }
            for (char c : num.toCharArray()) {
                result = result * base + map.get(c);
            }

            out.println(result);
        }

        out.close();
    }
}
//1023
//3 + 8 + 0 + 64
//