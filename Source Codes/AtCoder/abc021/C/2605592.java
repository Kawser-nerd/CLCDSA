import java.util.*;

public class Main {
    static int N;
    static int M;
    static int a, b;
    static ArrayList<Integer>[] E;
    static int INF = 1 << 30;
    static int MODP = 1000000007;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        N = Integer.parseInt(in.next());
        a = Integer.parseInt(in.next()) - 1;
        b = Integer.parseInt(in.next()) - 1;
        M = Integer.parseInt(in.next());
        E = new ArrayList[N];
        for(int i = 0; i < N; i++) {
            E[i] = new ArrayList<>();
        }

        for(int i = 0; i < M; i++) {
            int x = Integer.parseInt(in.next()) - 1;
            int y = Integer.parseInt(in.next()) - 1;
            E[x].add(y);
            E[y].add(x);
        }

        long[] cost = new long[N];
        long[] count = new long[N];
        boolean[] visited = new boolean[N];
        Arrays.fill(cost, INF);

        Queue<Integer> q = new ArrayDeque<>();
        q.add(a);
        cost[a] = 0;
        count[a] = 1;
        visited[a] = true;

        while(!q.isEmpty()) {
           int st = q.remove();
           for(int adj : E[st]) {
               if(cost[st] + 1 <= cost[adj]) {
                   cost[adj] = cost[st] + 1;
                   count[adj] += count[st];
                   if(!visited[adj]) {
                       q.add(adj);
                   }
                   visited[adj] = true;
               }
           }
        }

        System.out.println(count[b]%MODP);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.