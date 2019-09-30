import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;

    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);

    private static class Node {
        List<Node> nodeList = new ArrayList<>();
        int no;
        boolean visited;
        public Node(int no) {
            this.no = no;
        }
    }
    private void solve(Scanner sc) {
        int N = sc.nextInt();
        int M = sc.nextInt();
        Map<Integer, Node> nodes = new HashMap<>();
        for (int i = 0; i < N; ++i) {
            nodes.put(i + 1, new Node(i + 1));
        }
        for (int i = 0; i < M; ++i) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            Node nodeA = nodes.get(a);
            Node nodeB = nodes.get(b);
            nodeA.nodeList.add(nodeB);
            nodeB.nodeList.add(nodeA);
        }

        List<Integer> path = new ArrayList<>();
        path.add(1);
        nodes.get(1).visited = true;
        while (true) {
            boolean found = false;
            for (Node node : nodes.get(path.get(0)).nodeList) {
                if (!node.visited) {
                    path.add(0, node.no);
                    node.visited = true;
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
        }
        while (true) {
            boolean found = false;
            for (Node node : nodes.get(path.get(path.size() - 1)).nodeList) {
                if (!node.visited) {
                    path.add(node.no);
                    node.visited = true;
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
        }

        _out.println(path.size());
        StringBuilder sb = new StringBuilder();
        for (int node : path) {
            sb.append(" ").append(node);
        }
        _out.println(sb.substring(1));
    }
    private static BigInteger C(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        for (long i = r; i > 1; --i) {
            res = res.divide(BigInteger.valueOf(i));
        }
        return res;
    }
    private static BigInteger P(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        return res;
    }
    /*
     * 10^10 > Integer.MAX_VALUE = 2147483647 > 10^9
     * 10^19 > Long.MAX_VALUE = 9223372036854775807L > 10^18
     */
    public static void main(String[] args) {
        long S = System.currentTimeMillis();

        Scanner sc = new Scanner(System.in);
        new Main().solve(sc);
        _out.flush();

        long G = System.currentTimeMillis();
        if (elapsed) {
            _err.println((G - S) + "ms");
        }
        _err.flush();
    }
}