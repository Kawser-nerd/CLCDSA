import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	Main m = new Main();
	m.answer();
    }

    private Scanner scan = new Scanner(System.in);
    private final int N;
    private final int M;
    private final int Q;
    private final Edge[] edges;
    private final Man[] mans;
    private final UnionFind uf;

    public Main() {
	N = Integer.parseInt(scan.next());
	M = Integer.parseInt(scan.next());

	uf = new UnionFind(N);
	
	edges = new Edge[M];
	for (int i = 0; i < M; i++) {
	    int a = Integer.parseInt(scan.next()) - 1;
	    int b = Integer.parseInt(scan.next()) - 1;
	    int y = Integer.parseInt(scan.next());
	    edges[i] = new Edge(a, b, y);
	}

	Q = Integer.parseInt(scan.next());
	
	mans = new Man[Q];
	for (int i = 0; i < Q; i++) {
	    int v = Integer.parseInt(scan.next()) - 1;
	    int w = Integer.parseInt(scan.next());
	    mans[i] = new Man(i, v, w);
	}

	Arrays.sort(edges, new Comparator<Edge>() {
		@Override
		public int compare(Edge a, Edge b) {
		    return -(a.year - b.year);
		}
	    });

	Arrays.sort(mans, new Comparator<Man>() {
		@Override
		public int compare(Man a, Man b) {
		    return -(a.year - b.year);
		}
	    });

	int edgeIndex = 0;
	for (int i = 0; i < Q; i++) {
	    while(edgeIndex < M) {
		Edge edge = edges[edgeIndex];
		if(edge.year > mans[i].year) {
		    uf.connect(edge.a, edge.b);
		    edgeIndex++;
		} else {
		    break;
		}
	    }
	    mans[i].result = uf.size(mans[i].city);
	}
	
	Arrays.sort(mans, new Comparator<Man>() {
		@Override
		public int compare(Man a, Man b) {
		    return a.index - b.index;
		}
	    });

	for (int i = 0; i < Q; i++) {
	    System.out.println(mans[i].result);
	}
	scan.close();
    }

    public final void answer() {
	
    }

    private static class Edge {

	int a;
	int b;
	int year;

	public Edge(int a, int b, int year) {
	    this.a = a;
	    this.b = b;
	    this.year = year;
	}
    }

    private static class Man {
	
	int index;
	int city;
	int year;
	int result;

	public Man(int index, int city, int year) {
	    this.index = index;
	    this.city = city;
	    this.year = year;
	}
    }

    private static class UnionFind {
	
	int[] u;

	public UnionFind(int n) {
	    u = new int[n];
	    for (int i = 0; i < n; i++) {
		u[i] = -1;
	    }
	}

	public final int root(int a) {
	    if(u[a] < 0) return a;

	    return u[a] = root(u[a]);
	}

	public final int size(int a) {
	    return -u[root(a)];
	}

	public final boolean connect(int a, int b) {
	    a = root(a);
	    b = root(b);
	    
	    if(a == b) return false;

	    if(u[a] > u[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	    }

	    u[a] += u[b];
	    u[b] = a;
	    return true;
	}
    }
}