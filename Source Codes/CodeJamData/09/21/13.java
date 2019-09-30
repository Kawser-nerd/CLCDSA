import java.io.*;
import java.util.*;

public class A implements Runnable {
	private static String fileName = "a";
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";

    private Scanner in;
	private PrintWriter out;
    private String unread;
    private static final String PREFIX = "(";
    private static final String SUFFIX = ")";

    private class Node {
        Node left;
        Node right;
        String feature;
        double probability;

        public Node(double prob) {
            this.probability = prob;
        }

        public Node(double prob, String feature, Node left, Node right) {
            this.probability = prob;
            this.feature = feature;
            this.left = left;
            this.right = right;
        }

        public double getCuteness(Collection<String> features) {
            if (feature == null) {
                return probability;
            }

            if (features.contains(feature)) {
                return probability * left.getCuteness(features);
            } else {
                return probability * right.getCuteness(features);
            }
        }
    }

    private String nextToken() {
        String current;
        if (unread != null) {
            current = unread;
            unread = null;
        } else {
            current = in.next();
        }
        
        if (current.length() == 1) {
            return current;
        }

        if (current.startsWith(PREFIX)) {
            unread = current.substring(1);
            return PREFIX;
        }
        if (current.endsWith(SUFFIX)) {
            unread = SUFFIX;
            return current.substring(0, current.length() - 1);
        }
        return current;
    }

    private Node nextNode() {
        String token = nextToken();
        if (!token.equals(PREFIX)) {
            throw new IllegalStateException();
        }

        double prob = Double.parseDouble(nextToken());
        String feature = nextToken();
        if (!feature.equals(SUFFIX)) {
            Node left = nextNode();
            Node right = nextNode();
            String end = nextToken();
            if (!end.equals(SUFFIX)) {
                throw new IllegalStateException();
            }
            return new Node(prob, feature, left, right);
        } else {
            return new Node(prob);
        }
    }

    private A() throws FileNotFoundException {
        in = new Scanner(new File(inputFileName));
        out = new PrintWriter(outputFileName);
    }

    private void solve() {
        in.nextInt(); // skip
        Node root = nextNode();

        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            String name = in.next();
            int count = in.nextInt();
            Set<String> features = new HashSet<String>();
            for (int j = 0; j < count; j++) {
                String feature = in.next();
                features.add(feature);
            }
            out.println(root.getCuteness(features));
        }
    }

	public void run() {
		try {
            int tests = in.nextInt();
            in.nextLine();
            for (int t = 1; t <= tests; t++) {
                out.println("Case #" + t + ": ");
                solve();
            }
        } finally {
            in.close();
            out.close();
        }
    }

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.US);
		new Thread(new A()).start();
	}
}