import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.HashSet;

public class A implements Runnable {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;
    String filename = A.class.getName().substring(0, 1);

    static class CharSeq {
        String s;
        int index;

        CharSeq(String s) {
            this.s = s;
            this.index = 0;
        }

        char curr() {
            return s.charAt(index);
        }

        void next() {
            ++index;
        }
    }

    static class DTree {
        final double probability;
        final String property;
        final DTree trueTree, falseTree;

        public DTree(double probability) {
            this.probability = probability;
            property = null;
            trueTree = null;
            falseTree = null;
        }

        public DTree(double probability, String property, DTree trueTree, DTree falseTree) {
            this.probability = probability;
            this.property = property;
            this.trueTree = trueTree;
            this.falseTree = falseTree;
        }

        static boolean[] numberSet = new boolean[255];
        
        static {
            for (int i = 0; i < 10; ++i) {
                numberSet['0' + i] = true;
            }
            numberSet['.'] = true;
        }

        public static DTree parse(CharSeq s) {
            while (s.curr() != '(') {
                s.next();
            }
            s.next();
            while (!numberSet[s.curr()]) {
                s.next();
            }
            int from = s.index;
            while (numberSet[s.curr()]) {
                s.next();
            }
            double prob = Double.parseDouble(s.s.substring(from, s.index));
            while (s.curr() <= ' ') {
                s.next();
            }
            if (s.curr() == ')') {
                return new DTree(prob);
            } else {
                int fFrom = s.index;
                while (s.curr() > ' ') {
                    s.next();
                }
                String feature = s.s.substring(fFrom, s.index);
                DTree trueTree = parse(s);
                DTree falseTree = parse(s);
                return new DTree(prob, feature, trueTree, falseTree);
            }
        }

        public String toString() {
            if (property == null) {
                return "(" + probability + ")";
            } else {
                return "(" + probability + " " + property + " " + trueTree + " " + falseTree + ")";
            }
        }
    }

    void preSolve() {

    }

    void solve(int testNumber) throws IOException {
        int lines = nextInt();
        StringBuilder treeS = new StringBuilder();
        for (int i = 0; i < lines; ++i) {
            treeS.append(nextLine()).append(" ");
        }
        DTree tree = DTree.parse(new CharSeq(treeS.toString()));


        int ani = nextInt();
        out.println("Case #" + testNumber + ":");
        for (int i = 0; i < ani; ++i) {
            next(); //animal
            int paramCount = nextInt();
            Set<String> params = new HashSet<String>();
            for (int j = 0; j < paramCount; ++j) {
                params.add(next());
            }

            DTree curr = tree;
            double prob = 1;
            while (true) {
                prob *= curr.probability;
                if (curr.property != null) {
                    curr = params.contains(curr.property) ? curr.trueTree : curr.falseTree;
                } else {
                    break;
                }
            }
            out.printf("%.09f%n", prob);
        }
    }

    public void run() {
        try {
            in = new BufferedReader(new FileReader(filename + ".in"));
            out = new PrintWriter(filename + ".out");
            eat(null);

            preSolve();
            int nt = nextInt();
            for (int i = 1; i <= nt; ++i) {
                long t0 = System.currentTimeMillis();
                solve(i);
                t0 = System.currentTimeMillis() - t0;
                System.out.println(i + "/" + nt + " done in " + t0 + " ms.");
            }

            out.close();
            in.close();
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
    }

    void eat(String s) {
        st = s == null ? null : new StringTokenizer(s);
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            eat(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    int[] nextIntArray() throws IOException {
        int n = nextInt();
        int[] rv = new int[n];
        for (int i = 0; i < n; ++i) {
            rv[i] = nextInt();
        }
        return rv;
    }

    int[] nextIntArrayFromLine() throws IOException {
        StringTokenizer st = new StringTokenizer(nextLine());
        int[] rv = new int[st.countTokens()];
        for (int i = 0; i < rv.length; ++i) {
            rv[i] = Integer.parseInt(st.nextToken());
        }
        return rv;
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    String nextLine() throws IOException {
        eat(null);
        return in.readLine();
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new Thread(new A()).start();
    }
}