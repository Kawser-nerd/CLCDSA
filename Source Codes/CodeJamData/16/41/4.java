
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class A {

    private String solveTest() throws IOException {
        int n = nextInt();
        int r = nextInt();
        int p = nextInt();
        int s = nextInt();

        List<Node>[] layer = new ArrayList[3];

        for (int i = 0; i < 3; i++) {
            layer[i] = new ArrayList<>();
        }
        for (int i = 0; i < p; i++) {
            layer[0].add(new Node('P', null, null));
        }
        for (int i = 0; i < r; i++) {
            layer[1].add(new Node('R', null, null));
        }
        for (int i = 0; i < s; i++) {
            layer[2].add(new Node('S', null, null));
        }

        try {
            for (int i = 0; i < n; i++) {
                List<Node>[] nlayer = new ArrayList[3];

                for (int j = 0; j < 3; j++) {
                    nlayer[j] = new ArrayList<>();
                }

                int[] pp = new int[3];

                for (int k = 0; k < 3; k++) {
                    int x = (layer[k].size() + layer[(k + 1) % 3].size() - layer[(k + 2) % 3].size()) / 2;
                    for (int j = 0; j < x; j++) {
                        Node left = layer[k].get(pp[k]++);
                        Node right = layer[(k + 1) % 3].get(pp[(k + 1) % 3]++);
                        Node node = new Node(' ', left, right);
                        nlayer[k].add(node);
                    }
                }
                layer = nlayer;
            }
        } catch (Exception e) {
            return "IMPOSSIBLE";
        }

        for (int i = 0; i < 3; i++) if (layer[i].size() > 0) {
            return layer[i].get(0).string();
        }

        return null;
    }

    class Node {
        String s;
        char c;
        Node left, right;

        public Node(char c, Node left, Node right) {
            this.c = c;
            this.left = left;
            this.right = right;
        }

        public String string() {
            if (c != ' ') return "" + c;
            String ll = left.string();
            String rr = right.string();
            if ((ll + rr).compareTo(rr + ll) < 0) {
                return ll + rr;
            } else {
                return rr + ll;
            }
        }
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