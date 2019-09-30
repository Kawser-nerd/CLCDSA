import java.io.*;
import java.util.regex.Pattern;
import java.util.StringTokenizer;

public class A implements Runnable {

    private class TestCaseSolver {

        private void solve() {
            int l = nextInt();
            int d = nextInt();
            int n = nextInt();

            String[] words = new String[d];
            for (int i = 0; i < d; i++) {
                words[i] = nextToken();
            }

            for (int k = 0; k < n; k++) {
                char[] chars = nextToken().toCharArray();
                StringBuilder pattern = new StringBuilder();
                pattern.append('^');
                for (char c : chars) {
                    if (c == '(') {
                        pattern.append('[');
                    } else if (c == ')') {
                        pattern.append(']');
                    } else {
                        pattern.append(c);
                    }
                }
                pattern.append('$');

                int result = 0;
                Pattern p = Pattern.compile(pattern.toString());
                for (int i = 0; i < d; i++) {
                    if (p.matcher(words[i]).matches()) {
                        result++;
                    }
                }

                out.println("Case #" + (k + 1) + ": " + result);
            }
        }

    }

    private BufferedReader in;
    private PrintWriter out;

    private StringTokenizer tokenizer = new StringTokenizer("");

    private String nextToken() {
        while (!tokenizer.hasMoreTokens()) {
            String line;
            try {
                line = in.readLine();
            } catch (IOException e) {
                throw new IllegalStateException(e);
            }
            if (line == null) {
                return null;
            }
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    private String nextLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }
    }

    private int nextInt() {
        return Integer.parseInt(nextToken());
    }

    private int estimatedTimeLeft(int tc, int tCount, long timeStart) {
        long time = System.currentTimeMillis();
        double timePerTest = (1.0 * (time - timeStart)) / tc;
        return (int) (timePerTest * (tCount - tc) / 1000.0);
    }

    private void solve(File inFile) {
        long timeStart = System.currentTimeMillis();

        try {
            in = new BufferedReader(new FileReader(inFile));
            out = new PrintWriter(new FileWriter(inFile.getName() + ".out"));
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }

        new TestCaseSolver().solve();

        try {
            in.close();
            out.close();
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }
    }

    public void run() {
        final Pattern inPattern = Pattern.compile("^" + Pattern.quote(getClass().getSimpleName()) + "\\-.*\\.in$", Pattern.CASE_INSENSITIVE);
        final File[] inFiles = new File(".").listFiles(
            new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return inPattern.matcher(name).matches();
                }
            }
        );
        for (File inFile : inFiles) {
            System.out.println("Solving [" + inFile.getName() + ']');
            solve(inFile);
        }
    }

    public static void main(String[] args) {
        new Thread(new A()).start();
    }
}