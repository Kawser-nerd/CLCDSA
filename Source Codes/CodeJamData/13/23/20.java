package google.codejam2013.round1b;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class GarbledEmail {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));

    GarbledEmail() throws IOException {
        reader = new BufferedReader(new FileReader("C-large.in"));
        writer = new PrintWriter(new FileWriter("C-large.out"));
    }

    int[] readInts() throws IOException {
        String line = reader.readLine();
        String []s = line.split(" ");
        int[] ret = new int[s.length];
        for(int i = 0; i < s.length; i++) {
            ret[i] = Integer.parseInt(s[i]);
        }
        return ret;
    }

    int[] tt = null;
    int ti = 0;
    int readInt() throws IOException {
        if(tt == null || ti == tt.length) {
            tt = readInts();
            ti = 0;
        }
        return tt[ti++];
    }

    void solveTest(int test) throws IOException {
        writer.printf("Case #%d:", test);
        final char[] s = reader.readLine().toCharArray();
        final int n = s.length;
        final int[][] dp = new int[n + 1][5];
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < 5; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        dp[0][4] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 5; j++) {
                if(dp[i][j] == Integer.MAX_VALUE) continue;

                final int fi = i;
                final int fj = j;
                class Traverser {
                    void traverse(int pos, Node node, int d, int e) {
                        if(node == null) return;
                        if(node.leaf) {
                            dp[pos][d] = Math.min(dp[pos][d], dp[fi][fj] + e);
                        }
                        if(pos == n) return;
                        for(char c = 'a'; c <= 'z'; c++) {
                            if(c == s[pos]) traverse(pos + 1, Node.getChild(node, c), Math.min(4, d + 1), e);
                            else if(d == 4) {
                                traverse(pos + 1, Node.getChild(node, c), 0, e + 1);
                            }
                        }
                    }
                }
                new Traverser().traverse(i, root, j, 0);

            }
        }
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < 5; i++) {
            ans = Math.min(ans, dp[s.length][i]);
        }
        writer.println(" " + ans);
    }

    List<char[]> dict = new ArrayList<char[]>();

    static class Node {
        Node[] children = new Node[26];
        Node getChild(char c) {
            int i = c - 'a';
            if(children[i] == null) children[i] = new Node();
            return children[i];
        }
        boolean leaf;
        static Node getChild(Node node, char c) {
            if(node == null) return null;
            return node.children[c - 'a'];
        }
    }
    Node root = new Node();

    void solve() throws IOException {
        BufferedReader dictReader = new BufferedReader(new FileReader("garbled_email_dictionary.txt"));
        while(true) {
            String s = dictReader.readLine();
            if(s == null) break;
            Node node = root;
            for(char c: s.toCharArray()) {
                node = node.getChild(c);
            }
            node.leaf = true;
//            dict.add(s.toCharArray());
        }

        int t = readInt();
        for(int i = 1; i <= t; i++) {
            solveTest(i);
        }
        writer.flush();
    }

    public static void main(String[] args) throws IOException {
        new GarbledEmail().solve();
    }
}
