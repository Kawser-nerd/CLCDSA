import java.io.*;
import java.util.*;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

/**
 * @author Ivan Romanov
 */
public class A {

    private static final String PROBLEM = "A";

    //private static final String TEST = "small-attempt0";
    private static final String TEST = "large";

    private static final Pattern pat = Pattern.compile("\\(|\\)|[\\d\\.]+|[a-z]+");

    private ArrayList<String> tokens;

    private int parseIndex;

    private static class Tree {
        double weight;
        String feature;
        Tree left, right;

        private Tree(double weight) {
            this.weight = weight;
        }

        public double go(Set<String> features) {
            if (feature == null) {
                return weight;
            }
            if (features.contains(feature)) {
                return weight * left.go(features);
            } else {
                return weight * right.go(features);
            }
        }
    }

    private Tree parse() {
        if (tokens.get(parseIndex).equals("(")) {
            double weight = Double.parseDouble(tokens.get(++parseIndex));
            Tree res = new Tree(weight);
            if (!tokens.get(++parseIndex).equals(")")) {
                res.feature = tokens.get(parseIndex++);
                res.left = parse();
                res.right = parse();
            }
            if (!tokens.get(parseIndex++).equals(")")) {
                throw null;
            }
            return res;
        } else {
            throw null;
        }
    }

    private String solve() throws IOException {
        int lines = nextInt();
        StringBuffer buf = new StringBuffer();
        for (int i = 0; i < lines; i++) {
            buf.append(reader.readLine());
        }
        Matcher m = pat.matcher(buf.toString());
        tokens = new ArrayList<String>();
        while (m.find()) {
            tokens.add(m.group());
        }
        parseIndex = 0;
        Tree t = parse();


        int a = nextInt();
        buf = new StringBuffer();
        for (int it = 0; it < a; it++) {
            double p = 1.0;
            nextToken(); // name
            int f = nextInt();
            Set<String> features = new HashSet<String>();
            for (int i = 0; i < f; i++) {
                features.add(nextToken());
            }
            buf.append(String.format("\n%.7f", t.go(features)));
        }

        return buf.toString();
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
        Locale.setDefault(Locale.US);
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
            new A().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}