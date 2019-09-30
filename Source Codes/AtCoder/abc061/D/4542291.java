import java.util.Arrays;
import java.util.Scanner;

class Main {
    static int n;
    static int m;
    static Edge[] e;
    static long dis[];
    static final long inf = 1000000000000000l;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        e = new Edge[m];
        dis = new long[n];
        Arrays.fill(dis, inf);
        dis[0] = 0;

        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            e[i] = new Edge(a - 1, b - 1, -c);
        }

        sc.close();
        if (bellmanFord()) {
            System.out.print("inf");
        } else {
            System.out.println(-dis[n - 1]);
        }

    }

    public static boolean bellmanFord() {

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m; j++) {
                if (dis[e[j].from] != inf && dis[e[j].to] > dis[e[j].from] + e[j].cost) {
                    dis[e[j].to] = dis[e[j].from] + e[j].cost;
                    // 2???????????????? n ???????????????inf
                    if (i == n && e[j].to == n - 1) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}

class Edge {
    int from;
    int to;
    long cost;

    Edge(int from, int to, long cost) {
        this.from = from;
        this.to = to;
        this.cost = cost;
    }
}