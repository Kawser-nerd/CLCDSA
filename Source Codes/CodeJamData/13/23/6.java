
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {

    private static Node root;
    private static int nodeN;
    public static final int INF = 1000000000;
    private String s;
    private int n;
    private int[][] d;

    static class Node {
        Node[] children = new Node[26];
        boolean term;
    }

    public static void main(String[] args) throws FileNotFoundException {
        root = new Node();
        {
            Scanner in = new Scanner(new File("dictionary.txt"));
            while (in.hasNext()) {
                String s = in.next();
                Node node = root;
                for (int i = 0; i < s.length(); i++) {
                    int c = s.charAt(i) - 'a';
                    if (node.children[c] == null) {
                        node.children[c] = new Node();
                        nodeN++;
                    }
                    node = node.children[c];
                }
                node.term = true;
            }
            System.out.println(nodeN);
        }

        Scanner in = new Scanner(new File(C.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(C.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {


        s = in.next();
        n = s.length();
        d = new int[n + 1][5];
        for (int[] ints : d) {
            Arrays.fill(ints, INF);
        }
        d[0][4] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) if (d[i][j] < INF) {
                bt(root, i, j, d[i][j]);
            }
        }
        int res = INF;
        for (int i = 0; i < 5; i++) {
            res = Math.min(res, d[n][i]);
        }
        return "" + res;
    }

    private void bt(Node node, int pos, int err, int res) {
        if (node == null) return;
        if (node.term) {
            d[pos][err] = Math.min(d[pos][err], res);
        }
        if (pos == n) return;
        if (err < 4) {
            bt(node.children[s.charAt(pos) - 'a'], pos + 1, err + 1, res);
        } else {
            int c = s.charAt(pos) - 'a';
            for (int i = 0; i < 26; i++) {
                if (c == i) {
                    bt(node.children[i], pos + 1, 4, res);
                } else {
                    bt(node.children[i], pos + 1, 0, res + 1);
                }
            }
        }
    }
}