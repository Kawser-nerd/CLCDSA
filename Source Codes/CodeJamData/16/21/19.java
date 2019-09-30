import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
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
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "A-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("a.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            System.err.println(testNumber);

            String s = in.next();
            int[] cnt = new int[256];
            add(cnt, s, 1);

            List<Character> res = new ArrayList<>();

            cut(cnt, "EIGHT", 'G', 8, res);
            cut(cnt, "FOUR", 'U', 4, res);
            cut(cnt, "ZERO", 'Z', 0, res);
            cut(cnt, "TWO", 'W', 2, res);
            cut(cnt, "SIX", 'X', 6, res);

            cut(cnt, "THREE", 'H', 3, res);
            cut(cnt, "ONE", 'O', 1, res);
            cut(cnt, "FIVE", 'F', 5, res);
            cut(cnt, "SEVEN", 'S', 7, res);

            cut(cnt, "NINE", 'N', 9, res);

            for (int x : cnt) {
                if (x != 0) {
                    System.err.println("botva");
                    break;
                }
            }
            Collections.sort(res);

            out.printf("Case #%d: ", testNumber);
            for (Character c : res) {
                out.print(c);
            }
            out.println();
        }

        void add(int[] cnt, String s, int x) {
            for (char c : s.toCharArray()) {
                cnt[c] += x;
            }
        }

        void cut(int[] cnt, String s, char c, int d, List<Character> res) {
            while (cnt[c] > 0) {
                add(cnt, s, -1);
                char x = (char) (d + '0');
                res.add(x);
            }
        }

    }

    static class InputReader {
        BufferedReader bufReader;
        StringTokenizer stringTokenizer;
        boolean isEof = false;

        public InputReader(InputStream stream) {
            bufReader = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
                try {
                    String line = bufReader.readLine();
                    if (line == null) {
                        isEof = true;
                        return null;
                    }
                    stringTokenizer = new StringTokenizer(line);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return stringTokenizer.nextToken();
        }

    }
}

