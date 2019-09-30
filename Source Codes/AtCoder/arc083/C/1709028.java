import java.io.*;
import java.util.*;

public class Main
{
    static class Node{
        int b = 0;
        int w = 0;
        List<Integer> child;
    }
    static int subsetSum(int[] arr, int target){
        int n = arr.length;
        int m = target + 1;
        boolean[][] dp = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            if (arr[i] > target) continue;
            dp[i][arr[i]] = true;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i-1][j]){
                    dp[i][j] = true;
                    if (j + arr[i] <= target){
                        dp[i][j+arr[i]] = true;
                    }
                }
            }
        }
        for (int i = m-1; i >= 0;i--) {
            if (dp[n-1][i]){
                return i;
            }
        }
        return 0;
    }

    static Node[] nodes;
    static int[] X;
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc= new Scanner(System.in);
        int N = sc.nextInt();
        nodes = new Node[N];
        X = new int[N];
        for (int i = 0; i < N; i++) {
            nodes[i] = new Node();
            nodes[i].child = new ArrayList<>();
        }
        for (int i = 1; i < N; i++) {
            int par = sc.nextInt();
            nodes[par - 1].child.add(i);
        }
        for (int i = 0; i < N; i++) {
            X[i] = sc.nextInt();
        }
        System.out.println(recur(0) ? "POSSIBLE": "IMPOSSIBLE");
    }

    public static boolean recur(int nodeIdx){
        Node cur = nodes[nodeIdx];
        if (cur.child == null || cur.child.size() == 0){
            cur.b = 0; cur.w = X[nodeIdx];
            return true;
        }
        for (int i = 0; i < cur.child.size(); i++) {
            if (!recur(cur.child.get(i))) {
                return false;
            }
        }
        int b = 0, w = 0;
        int[] swap = new int[cur.child.size()];
        for (int i = 0; i < cur.child.size(); i++) {
            int black = nodes[cur.child.get(i)].b;
            int white = nodes[cur.child.get(i)].w;
            b += Math.min(white, black);
            w += Math.max(white, black);
            swap[i] = Math.max(white, black) - Math.min(white, black);
        }
        if (b > X[nodeIdx]) {
            return false;
        }
        int sww = subsetSum(swap, X[nodeIdx] - b);
        cur.b = X[nodeIdx];
        cur.w = w - sww;
        return true;
    }

}