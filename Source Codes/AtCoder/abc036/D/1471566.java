import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	Main m = new Main();
	m.answer();
    }

    private Scanner scan = new Scanner(System.in);
    private static final long MOD = 1000_000_007;
    private final int N;
    private final Node[] nodes;
    private final long[] dpW;
    private final long[] dpB;

    public Main() {
	N = Integer.parseInt(scan.next());
	nodes = new Node[N];
	for (int i = 0; i < N; i++) {
	    nodes[i] = new Node(i);
	}
	
	for (int i = 0; i < N-1; i++) {
	    int a = Integer.parseInt(scan.next()) - 1;
	    int b = Integer.parseInt(scan.next()) - 1;
	    nodes[a].next.add(b);
	    nodes[b].next.add(a);
	}

	List<Integer> tmp = new ArrayList<Integer>();
	tmp.add(0);
	int rank = 0;
	while(tmp.size() > 0) {
	    int node = tmp.get(0);
	    tmp.remove(0);
	    nodes[node].rank = rank;
	    rank++;
	    for(int next: nodes[node].next) {
		nodes[next].next.remove(Integer.valueOf(node));
		tmp.add(next);
	    }
	}
	Arrays.sort(nodes);

	dpW = new long[N];
	dpB = new long[N];

	scan.close();
    }

    public final void answer() {
	for (int i = 0; i < N; i++) {
	    Node node = nodes[i];
	    if(node.next.size() == 0) {
		dpW[node.name] = dpB[node.name] = 1;
	    } else {
		dpW[node.name] = 1;
		dpB[node.name] = 1;
		for(int tmp: node.next) {
		    dpW[node.name] = (dpW[tmp] + dpB[tmp]) % MOD * dpW[node.name] % MOD;
		    dpB[node.name] = dpW[tmp] * dpB[node.name] % MOD;
		}
	    }
	}
	System.out.println((dpW[0] + dpB[0]) % MOD);
    }

    private static class Node implements Comparable<Node> {
	final int name;
	final List<Integer> next;
	int rank;

	public Node(int name) {
	    this.name = name;
	    next = new ArrayList<Integer>();
	}

	@Override
	public int compareTo(Node n) {
	    return -(this.rank - n.rank);
	}
    }
}