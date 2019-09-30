import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ESynchronizedSubsequence solver = new ESynchronizedSubsequence();
        solver.solve(1, in, out);
        out.close();
    }

    static class ESynchronizedSubsequence {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String s = in.nextString();

            int sum = 0;
            List<String> list = new ArrayList<>();
            int prev = 0;
            for (int i = 0; i < 2 * n; i++) {
                sum += s.charAt(i) == 'a' ? -1 : 1;
                if (sum == 0) {
                    list.add(exec(s.substring(prev, i + 1)));
                    prev = i + 1;
                }
            }

            String ans = list.get(list.size() - 1);
            for (int i = list.size() - 2; i >= 0; i--) {
                if (ans.compareTo(list.get(i) + ans) <= 0) {
                    ans = list.get(i) + ans;
                }
            }

            out.println(ans);
        }

        String exec(String s) {
            int n = s.length() / 2;

            int aCount = 0;
            int bCount = 0;
            int[] aIndex = new int[n];
            int[] bIndex = new int[n];
            for (int i = 0; i < 2 * n; i++) {
                if (s.charAt(i) == 'a') {
                    aIndex[aCount] = i;
                    aCount++;
                } else {
                    bIndex[bCount] = i;
                    bCount++;
                }
            }

            int[] pairIndex = new int[2 * n];
            for (int i = 0; i < n; i++) {
                pairIndex[aIndex[i]] = bIndex[i];
                pairIndex[bIndex[i]] = aIndex[i];
            }

            if (s.charAt(0) == 'a') {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < 2 * n; i++) {
                    if (s.charAt(i) == 'a') {
                        sb.append("ab");
                        i = pairIndex[i];
                    }
                }
                return sb.toString();
            } else {
                List<String> list = new ArrayList<>();
                for (int i = 1; i <= n; i++) {
                    boolean[] use = new boolean[2 * n];
                    int count = 0;
                    for (int j = 2 * n - 1; j >= 0; j--) {
                        if (s.charAt(j) == 'a') {
                            use[j] = true;
                            use[pairIndex[j]] = true;

                            count++;
                            if (count == i) break;
                        }
                    }
                    StringBuilder sb = new StringBuilder();
                    for (int j = 0; j < 2 * n; j++) {
                        if (use[j]) sb.append(s.charAt(j));
                    }
                    list.add(sb.toString());
                }
                Collections.sort(list);
                return list.get(list.size() - 1);
            }
        }

    }

    static class InputReader {
        private BufferedReader br;
        private StringTokenizer st;

        public InputReader(InputStream inputStream) {
            br = new BufferedReader(new InputStreamReader(inputStream));
            st = new StringTokenizer("");
        }

        public String nextString() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

    }
}