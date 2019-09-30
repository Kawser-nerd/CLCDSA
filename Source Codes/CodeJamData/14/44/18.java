package com.google.codejam2014.round2;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TrieSharding {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    StringTokenizer stringTokenizer;

    TrieSharding() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter(new FileWriter("output.txt"));
    }

    String next() throws IOException {
        while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
            stringTokenizer = new StringTokenizer(reader.readLine());
        }
        return stringTokenizer.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    void solveTestCase(int testNumber) throws IOException {
        writer.printf("Case #%d: ", testNumber);
        final int m = nextInt();
        final int n = nextInt();
        final char[][] s = new char[m][];
        for(int i = 0; i < m; i++) {
            s[i] = next().toCharArray();
        }
        class Node {
            Node[] children = new Node[26];

            int size() {
                int size = 1;
                for (Node child : children) {
                    if(child != null) {
                        size += child.size();
                    }
                }
                return size;
            }

            Node getChild(char c) {
                int i = c - 'A';
                if(children[i] == null) {
                    children[i] = new Node();
                }
                return children[i];
            }
        }
        class Utils {
            int worst = 0;
            int count = 0;
            int[] server = new int[m];

            void rec(int k) {
                if(k == m) {
                    Node[] tries = new Node[n];
//                    for(int i = 0; i < n; i++) {
//                        tries[i] = new Node();
//                    }
                    for(int i = 0; i < m; i++) {
                        Node trie = tries[server[i]];
                        if(trie == null) {
                            tries[server[i]] = new Node();
                            trie = tries[server[i]];
                        }
                        char[] string = s[i];
                        for(char c : string) {
                            trie = trie.getChild(c);
                        }
                    }
                    int totalSize = 0;
                    for (Node trie : tries) {
                        if(trie == null) {
                            return;
                        }
                        totalSize += trie.size();
                    }
                    if(totalSize > worst) {
                        worst = totalSize;
                        count = 0;
                    }
                    if(totalSize == worst) {
                        count++;
                    }
                    return;
                }
                for(int i = 0; i < n; i++) {
                    server[k] = i;
                    rec(k + 1);
                }
            }
        }
        Utils utils = new Utils();
        utils.rec(0);
        writer.println(utils.worst + " " + utils.count);
    }

    void solve() throws IOException {
        int testsNumber = nextInt();
        for(int i = 1; i <= testsNumber; i++) {
            solveTestCase(i);
            writer.flush();
        }
        writer.close();
    }

    public static void main(String[] args) throws IOException {
        new TrieSharding().solve();
    }
}
