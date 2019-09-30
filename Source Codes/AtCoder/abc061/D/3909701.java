import java.util.Scanner;

public class Main {
	static final int MAX = 1000;
    static final long INF = 1000000000000000l;
    static final int WHITE = 0;
    static final int GRAY = 1;
    static final int BLACK = 2;
    static int N, M;
    static Edge[]e;
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	N = sc.nextInt();
    	M = sc.nextInt();
    	e = new Edge[M];
    	for(int i = 0; i < M; i++) {
    		int a = sc.nextInt();
    		int b = sc.nextInt();
    		int c = sc.nextInt();
    		e[i] = new Edge(a - 1, b - 1, -c);
    	}
    	sc.close();
        //bellmanFord();
        if(bellmanFord()) {
            System.out.println("inf");
        }else {
        	System.out.println(-d[N - 1]);
        }
    }
    static long[]d = new long[MAX];
    static boolean bellmanFord() {
        for(int i = 0; i < MAX; i++) {
            d[i] = INF;
        }
        d[0] = 0;
        for(int i = 0; i < 2 * N; i++) {
            for(int j = 0; j < M; j++) {
                if(d[e[j].from] != INF && d[e[j].to] > d[e[j].from] + e[j].cost) {
                    d[e[j].to] = d[e[j].from] + e[j].cost;
                    if(i >= N - 1 && e[j].to == N - 1) return true;
                }
            }
        }
        return false;
    }
    static class Edge{
        int from, to;
        long cost;
        public Edge(int from, int to, long cost) {
            this.from = from;
            this.to= to;
            this.cost = cost;
        }
    }
}