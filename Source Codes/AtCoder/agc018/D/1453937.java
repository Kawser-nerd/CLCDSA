import java.util.*;
import java.lang.*;

public class Main{
    static int [] head;
    static int [] next;
    static int [] to;
    static long [] cost;
    static int [] size;
    static int edgeCount = 0;
    static long ans = 0;
    static int N;

    public static void main(String [] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        head = new int  [N + 1];
        size = new int  [N + 1];
        next = new int  [N + N + 1];
        to   = new int  [N + N + 1];
        cost = new long [N + N + 1];
        for(int i = 0; i < N - 1; i++) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            int C = sc.nextInt();
            addEdge(A,B,C);
            addEdge(B,A,C);
        }
        calcSize(1);
        dfs(1);
        System.out.println(ans);
    }

    public static void dfs(int root) {
        int maxNodeSize = N - size[root];
        long minEdgeCost = Long.MAX_VALUE;

        for(int e = head[root]; e != 0; e = next[e]) {
            int destination = to[e];
            minEdgeCost = Math.min(minEdgeCost,cost[e]);

            if(size[destination] < size[root]) {
                maxNodeSize = Math.max(maxNodeSize,size[destination]);

                long min = Math.min(size[destination], N - size[destination]);
                ans = ans + min * cost[e] * 2;
                dfs(destination);

                if(min + min == N) {
                    ans = ans - cost[e];
                }
            }
        }

        if(maxNodeSize * 2 < N) {
            ans = ans - minEdgeCost;
        }
    }

    public static int calcSize(int root) {
        size[root] = 1;
        for(int e = head[root]; e != 0; e = next[e]) {
            if(size[to[e]] == 0) {
                size[root] += calcSize(to[e]);
            }
        }
        return size[root];
    }

    public static void addEdge(int A, int B, int C) {
        edgeCount += 1;
        to[edgeCount] = B;
        cost[edgeCount] = C;
        next[edgeCount] = head[A];
        head[A] = edgeCount;
    }
}