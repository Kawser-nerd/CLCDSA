import gcj.GCJ;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class GarbledEmail {

    public Node root = new Node();

    public class Node {
        Node[] children = new Node[26];

        boolean end;
    }

    public GarbledEmail() {
        try {
            BufferedReader br = new BufferedReader(new FileReader(
                    "C:/Users/wzzhang/Downloads/garbled_email_dictionary.txt"));
            String line = br.readLine();
            while (line != null) {
                add(line, 0, root);
                line = br.readLine();
            }
            br.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private void add(String word, int idx, Node cur) {
        int k = word.charAt(idx) - 'a';
        if (cur.children[k] == null) {
            cur.children[k] = new Node();
        }
        if (idx + 1 < word.length()) {
            add(word, idx + 1, cur.children[k]);
        } else {
            cur.children[k].end = true;
        }
    }

    public int calc(int[][] memo, int[] a, int idx, int change, Node cur) {
        if (idx == a.length) {
            if (cur.end) {
                return 0;
            } else {
                return -1;
            }
        }
        if (cur == root) {
            // memo cache
            if (memo[idx][change] > -2) {
                return memo[idx][change];
            }
        }
        int min = -1;
        if (idx >= change) {
            for (int k = 0; k < cur.children.length; k++) {
                int offset = (a[idx] == k ? 0 : 1);
                int nextChange = (a[idx] == k ? change : idx + 5);
                if (cur.children[k] != null) {
                    // try this one
                    int res = calc(memo, a, idx + 1, nextChange, cur.children[k]);
                    if (res != -1) {
                        if (min == -1) {
                            min = res + offset;
                        } else {
                            min = Math.min(min, res + offset);
                        }
                    }
                    if (cur.children[k].end) {
                        int resNew = calc(memo, a, idx + 1, nextChange, root);
                        if (resNew != -1) {
                            if (min == -1) {
                                min = resNew + offset;
                            } else {
                                min = Math.min(min, resNew + offset);
                            }
                        }
                    }
                }
            }
        } else {
            int k = a[idx];
            if (cur.children[k] != null) {
                // try this one
                int res = calc(memo, a, idx + 1, change, cur.children[k]);
                if (res != -1) {
                    if (min == -1) {
                        min = res;
                    } else {
                        min = Math.min(min, res);
                    }
                }
                if (cur.children[k].end) {
                    int resNew = calc(memo, a, idx + 1, change, root);
                    if (resNew != -1) {
                        if (min == -1) {
                            min = resNew;
                        } else {
                            min = Math.min(min, resNew);
                        }
                    }
                }
            }
        }
        if (cur == root) {
            memo[idx][change] = min;
        }
        return min;
    }

    public static void main(String[] args) {
        GarbledEmail ge = new GarbledEmail();
        Scanner s = GCJ.createScanner('C', true);
        int T = s.nextInt();
        s.nextLine();
        for (int i = 1; i <= T; i++) {
            String S = s.nextLine();
            int n = S.length();
            int[][] memo = new int[n][n + 10];
            int[] a = new int[n];
            for (int k = 0; k < n; k++) {
                a[k] = S.charAt(k) - 'a';
                Arrays.fill(memo[k], -2);
            }
            int min = ge.calc(memo, a, 0, 0, ge.root);
            GCJ.out(i, Integer.toString(min));
        }
    }

}
