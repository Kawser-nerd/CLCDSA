import java.util.regex.Pattern;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.io.*;

/**
 * @author Roman
 */
public class C implements Runnable {

    public static final String PROBLEM_ID = "C";

    final long MODULO = 1000000009;

    // START of shared data between test cases

    // END of shared data between test cases

    /**
     * New instance is created for each test case
     */
    private class TestCaseSolver {

        int n;
        long k;

        class NodeList {
            ArrayList<Integer> list = new ArrayList<Integer>();
            ArrayList<Integer> children = new ArrayList<Integer>();
        }

        class Tree {

            int n;
            NodeList[] nodes;

            public Tree(int n) {
                this.n = n;
                this.nodes = new NodeList[n];
                for (int i = 0; i < n; i++) {
                    this.nodes[i] = new NodeList();
                }
            }

            public void connect(int u, int v) {
                nodes[u].list.add(v);
                nodes[v].list.add(u);
            }

            public boolean isLeaf(int u, int uPrev) {
                if (nodes[u].list.size() == 0) {
                    return true;
                }
                if (nodes[u].list.size() == 1) {
                    return nodes[u].list.iterator().next() == uPrev;
                }
                return false;
            }
        }

        Tree a;        

        private void recChildren(int u, int uPrev) {

            if (a.isLeaf(u, uPrev)) {
                return;
            }

            for (int v : a.nodes[u].list) {
                if (v != uPrev) {
                    a.nodes[u].children.add(v);
                    recChildren(v, u);
                }
            }
        }


        private long rec(int u, int uPrev, int edgesUp) {

            if (a.isLeaf(u, uPrev)) {
                return 1;
            }

            long result = 1L;

            long mulF = k;
            mulF -= Math.min(edgesUp, 2);
            if (uPrev >= 0) {
                mulF -= (a.nodes[uPrev].children.size() - 1);
/*
                for (int v : a.nodes[uPrev].children) {
                    if (v != u) {
                        mulF -= a.nodes[v].children.size();
                    }
                }
*/
            }

            for (int v : a.nodes[u].list) {
                if (v != uPrev) {
                    mulF = Math.max(mulF, 0);
                    
                    long intermediate = mulF * rec(v, u, edgesUp + 1);
                    intermediate %= MODULO;

                    result *= intermediate;
                    result %= MODULO;

                    mulF--;
                }
            }

            return result % MODULO;
        }

        // Solves test case
        public void solve() throws Throwable {
            n = nextInt();
            k = nextLong();
            a = new Tree(n);
            for (int i = 0; i < n - 1; i++) {
                int u = nextInt() - 1;
                int v = nextInt() - 1;
                a.connect(u, v);
            }

            recChildren(0, -1);
            long result = rec(0, -1, 0);
            out.print(result);
        }

    }

    // Template goes below
    public static final String PROBLEM_IN_SUFFIX = ".in";
    public static final String PROBLEM_OUT_SUFFIX = ".out";
    public static final Pattern PROBLEM_FILE_PATTERN = Pattern.compile("^" + PROBLEM_ID + ".*" + PROBLEM_IN_SUFFIX + "$", Pattern.CASE_INSENSITIVE);

    static {
        Locale.setDefault(Locale.ENGLISH);
    }


    BufferedReader in;
    PrintWriter out;
    StringTokenizer tokenizer;

    private String nextLine() throws IOException {
        return in.readLine();
    }

    private String nextToken() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            String line = nextLine();
            if (line == null) {
                return null;
            }
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    private int nextInt() throws IOException {
        String token = nextToken();
        return Integer.parseInt(token);
    }

    private long nextLong() throws IOException {
        String token = nextToken();
        return Long.parseLong(token);
    }

    private void solveFile() throws Throwable {
        tokenizer = new StringTokenizer("");
        int tc = nextInt();
        for (int t = 0; t < tc; t++) {
            System.out.println("Progress: #" + (t + 1) + " out of " + tc);

            out.print("Case #" + (t + 1) + ": ");
            new C.TestCaseSolver().solve();
            out.println();
        }
    }

    private void solve(String fileName) {
        try {
            System.out.println("Solving " + fileName);

            in = new BufferedReader(new FileReader(fileName));
            out = new PrintWriter(new FileWriter(fileName + PROBLEM_OUT_SUFFIX));

            solveFile();

            in.close();
            out.close();
        } catch (Throwable t) {
            t.printStackTrace();
            System.out.flush();
            System.err.flush();
            System.exit(-1);
        }
    }

    public void run() {
        File dir = new File(".");
        FilenameFilter filter = new FilenameFilter() {
            public boolean accept(File file, String name) {
                return PROBLEM_FILE_PATTERN.matcher(name).matches();
            }
        };
        String[] children = dir.list(filter);
        if (children != null) {
            for (String file : children) {
                solve(file);
            }
        }
    }

    public static void main(String[] args) {
        new Thread(new C()).start();
    }

}
