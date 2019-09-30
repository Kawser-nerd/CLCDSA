import java.io.*;
import java.util.StringTokenizer;
import java.util.Set;
import java.util.HashSet;
import java.util.regex.Pattern;

public class A implements Runnable {

    class Tree {
        double weight;

        String feature;
        Tree l, r;
    }

    private class TestCaseSolver {

        private Set<String> features;
        private String name;

        private void solve() {
            int l = nextInt();
            String treeDef = "";
            for (int i = 0; i < l; i++) {
                treeDef += nextLine() + " ";
            }

            Tree root = parseTree(treeDef);
            int q = nextInt();
            for (int i = 0; i < q; i++) {
                name = nextToken();
                features = new HashSet<String>();
                int fNum = nextInt();
                for (int j = 0; j < fNum; j++) {
                    features.add(nextToken());
                }

                double result = 1.0;
                Tree t = root;
                for (;;) {
                    result *= t.weight;
                    if (t.feature == null) {
                        break;
                    }

                    if (features.contains(t.feature)) {
                        t = t.l;
                    } else {
                        t = t.r;
                    }
                }

                out.println();
                out.printf("%.7f", result);
            }
        }

        private Tree parseTree(String s) {
            s = s.trim();
            if (s.charAt(0) != '(') {
                throw new IllegalStateException();
            }
            if (s.charAt(s.length() - 1) != ')') {
                throw new IllegalStateException();
            }

            s = s.substring(1, s.length() - 1).trim();

            Tree result = new Tree();

            int spaceIdx;

            // get space
            spaceIdx = findSpaceIdx(s);

            // no space - just a weight node
            if (spaceIdx < 0) {
                result.weight = Double.parseDouble(s.trim());
                return result;
            }

            // set weight
            result.weight = Double.parseDouble(s.substring(0, spaceIdx).trim());
            s = s.substring(spaceIdx).trim();

            // get space
            spaceIdx = findSpaceIdx(s);
            if (spaceIdx < 0) {
                throw new IllegalStateException();
            }

            result.feature = s.substring(0, spaceIdx).trim();
            s = s.substring(spaceIdx).trim();

            // get other trees
            spaceIdx = findSpaceIdx(s);

            result.l = parseTree(s.substring(0, spaceIdx));
            result.r = parseTree(s.substring(spaceIdx));

            return result;
        }

        private int findSpaceIdx(String s) {
            int balance = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '(') {
                    balance++;
                } else if (s.charAt(i) == ')') {
                    balance--;
                } else if (s.charAt(i) == ' ' && balance == 0) {
                    return i;
                }

            }
            return -1;
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

        int tCount = nextInt();
        for (int tc = 0; tc < tCount; tc++) {
            System.out.print("Solving test case #" + (tc + 1) + "/" + tCount);
            if (tc > 0) {
                System.out.print(", estimated time left: " + estimatedTimeLeft(tc, tCount, timeStart) + " sec");
            }
            System.out.println();

            out.print("Case #" + (tc + 1) + ":");
            new TestCaseSolver().solve();
            out.println();
        }

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