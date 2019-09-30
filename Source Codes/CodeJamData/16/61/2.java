
import java.io.*;
import java.util.*;

public class A {

    private String s;
    private int cur;

    private String solveTest() throws IOException {
        long A = Long.parseLong(next());
        long B = Long.parseLong(next());
        s = next();
        cur = 0;
        Automat a = parseSeq();
//        System.out.println("parsed");

        Automat b = determ(a);
        for (int i = 0; i < 20; i++) {
            precalc(b.start, i);
        }
        return "" + (calc(b, B + 1) - calc(b, A));
    }

    private void precalc(Node node, int i) {
        if (node.d == null) {
            node.d = new long[20];
            Arrays.fill(node.d, -1);
        }
        if (node.d[i] >= 0) {
            return;
        }
        node.d[i] = 0;
        if (i == 0) {
            node.d[0] = node.terminal ? 1 : 0;
        } else {
            for (int j = 0; j < 10; j++) {
                if (node.next[j] != null) {
                    precalc(node.next[j], i - 1);
                    node.d[i] += node.next[j].d[i - 1];
                }
            }
        }
    }

    private long calc(Automat b, long a) {
        String s = "" + a;
        long res = 0;
        for (int i = 1; i < s.length(); i++) {
            for (int j = 1; j < 10; j++) {
                if (b.start.next[j] != null) {
                    res += b.start.next[j].d[i - 1];
                }
            }
        }
        for (int i = 0; i < s.length(); i++) {
            Node node = b.start;
            for (int j = 0; j < i; j++) {
                node = node.next[s.charAt(j) - '0'];
            }
            for (int j = 0; j < s.charAt(i) - '0'; j++) {
                if (i == 0 && j == 0) continue;
                if (node.next[j] != null) {
                    res += node.next[j].d[s.length() - i - 1];
                }
            }
        }
        return res;
    }

    Node tt;

    private Automat determ(Automat a) {
        Set<Node> start = new HashSet<>();
        nodeMap = new HashMap<>();
        tt = a.terminal;
        dfsEps(a.start, start, mark++);
        Automat res = new Automat();
        res.start = dfs(start);
        return res;
    }

    Map<Long, Node> nodeMap;
    long mark = 0;

    private Node dfs(Set<Node> nodes) {
        long id = 0;
        for (Node node : nodes) {
            id ^= node.id;
        }
        Node node = nodeMap.get(id);
        if (node == null) {
            node = new Node();
            node.id = id;
            nodeMap.put(id, node);
            node.terminal = nodes.contains(tt);
//            System.out.println(node + " " + nodes + " " + node.terminal);
            for (int i = 0; i < 10; i++) {
                Set<Node> next = new HashSet<>();
                for (Node nn : nodes) {
                    dfsEps(nn.next[i], next, mark++);
                }
                node.next[i] = dfs(next);
//                if (next.size() > 0)
//                    System.out.println(node + " " + i + " " + node.next[i]);
            }
        }
        return node;
    }

    private void dfsEps(Node node, Set<Node> next, long mark) {
        if (node == null) return;
        if (node.mark == mark) return;
        node.mark = mark;
        next.add(node);
        for (Node nn : node.eps) {
            dfsEps(nn, next, mark);
        }
    }

    private Automat parseExpr() {
        Automat res = new Automat();
        Node start = new Node();
        Node terminal = new Node();
        res.start = start;
        res.terminal = terminal;
        while (true) {
            Automat a = parseSeq();
            start.eps.add(a.start);
            a.terminal.eps.add(terminal);
            if (s.charAt(cur) == '|') {
                cur++;
            } else {
                break;
            }
        }
        return res;
    }

    private Automat parseSeq() {
        Node start = new Node();
        Automat a = new Automat();
        a.start = start;
        a.terminal = start;
        while (cur < s.length() && s.charAt(cur) != ')' && s.charAt(cur) != '|') {
            Automat aa = parseUnit();
            a.terminal.eps.add(aa.start);
            a.terminal = aa.terminal;
        }
        return a;
    }

    private Automat parseUnit() {
        if (s.charAt(cur) == '(') {
            cur++;
            Automat a = parseExpr();
            cur++;
            if (cur < s.length() && s.charAt(cur) == '*') {
                Node node = new Node();
                a.terminal.eps.add(a.start);
                a.terminal.eps.add(node);
                a.start.eps.add(a.terminal);
                a.terminal = node;
                cur++;
            }
            return a;
        } else {
            Node start = new Node();
            Node terminal = new Node();
            Automat a = new Automat();
            a.start = start;
            a.terminal = terminal;
            a.start.next[s.charAt(cur) - '0'] = a.terminal;
            cur++;
            return a;
        }
    }

    class Automat {
        Node start;
        Node terminal;
    }

    Random random = new Random(123123213123L);

    char ccid = 'A';

    class Node {
        char cid = ccid++;
        long id = random.nextLong();
        long mark = -1;
        boolean terminal;
        Node[] next = new Node[10];
        List<Node> eps = new ArrayList<>();
        public long[] d;

        @Override
        public String toString() {
            return "" + cid;
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