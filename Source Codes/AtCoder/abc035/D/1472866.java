import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	Main m = new Main();
	m.answer();
    }

    private Scanner scan = new Scanner(System.in);
    private static final long INF = 10_000_000_000L;
    private final int N;
    private final int M;
    private final int T;
    private final int[] A;
    private final Edge[] edges;
    private final List<List<Edge>> edgeList;

    public Main() {
	N = Integer.parseInt(scan.next());
	M = Integer.parseInt(scan.next());
	T = Integer.parseInt(scan.next());
	A = new int[N];
	for (int i = 0; i < N; i++) {
	    A[i] = Integer.parseInt(scan.next());
	}
	edges = new Edge[M];
	edgeList = new ArrayList<List<Edge>>(N);
	for (int i = 0; i < N; i++) {
	    edgeList.add(new ArrayList<Edge>());
	}
	for (int i = 0; i < M; i++) {
	    int a = Integer.parseInt(scan.next()) - 1;
	    int b = Integer.parseInt(scan.next()) - 1;
	    int c = Integer.parseInt(scan.next());
	    edges[i] = new Edge(a, b, c);
	    edgeList.get(a).add(edges[i]);
	}

	scan.close();
    }

    public final void answer() {
	long[] forwardTime = dijkstra();

	edgeList.clear();
	for (int i = 0; i < N; i++) {
	    edgeList.add(new ArrayList<Edge>());
	}
	for (int i = 0; i < M; i++) {
	    edges[i].reverse();
	    edgeList.get(edges[i].source).add(edges[i]);
	}
	
	long[] backwardTime = dijkstra();

	long ans = 0;
	for (int i = 0; i < N; i++) {
	    if(forwardTime[i] < INF && backwardTime[i] < INF) {
		long money = A[i] * (T - forwardTime[i] - backwardTime[i]);
		if(money > ans) ans = money;
	    }
	}

	System.out.println(ans);
    }

    private final long[] dijkstra() {
	boolean[] checked = new boolean[N];
	checked[0] = true;
	
	long[] cost = new long[N];
	for (int i = 1; i < N; i++) {
	    cost[i] = INF;
	}
	
	Heap heap = new Heap(N);

	int source = 0;
	for (int step = 0; step < N-1; step++) {
	    for(Edge edge: edgeList.get(source)) {
		if(!checked[edge.target]) {
		    cost[edge.target] = Long.min(cost[edge.target], cost[source] + edge.cost);
		    heap.update(edge.target, cost[edge.target]);
		}
	    }

	    Node node = heap.pop();
	    if(node == null) return cost;
	    else {
		checked[node.index] = true;
		source = node.index;
	    }
	}

	return cost;
    }

    private static class Edge {
	int source;
	int target;
	int cost;

	public Edge(int source, int target, int cost) {
	    this.source = source;
	    this.target = target;
	    this.cost = cost;
	}

	public final void reverse() {
	    int tmp = source;
	    source = target;
	    target = tmp;
	}
    }

    private static class Node {
	final int index;
	long value;

	public Node(int index, long value) {
	    this.index = index;
	    this.value = value;
	}
    }

    private static class Heap {
	Node[] nodes;
	private int count = 0;
	private final Map<Integer, Integer> map = new HashMap<Integer, Integer>();

	public Heap(int n) {
	    nodes = new Node[n];
	}

	public final void add(Node node) {
	    map.put(node.index, count);
	    
	    nodes[count] = node;
	    upward(count);
	    count++;
	}

	public final void update(int nodeIndex, long value) {
	    int index = search(nodeIndex);
	    if(index < 0) {
		add(new Node(nodeIndex, value));
	    } else {
		Node node = nodes[index];
		if(value < node.value) {
		    node.value = value;
		    upward(index);
		    
		} else if(value > node.value) {
		    node.value = value;
		    downward(index);
		}
	    }
	}

	public final Node pop() {
	    if(count == 0) return null;
	    
	    int nodeIndex = nodes[0].index;
	    map.remove(nodeIndex);
	    
	    Node ret = nodes[0];
	    nodes[0] = nodes[count-1];
	    count--;
	    downward(0);
	    return ret;
	}

	private final int search(int nodeIndex) {
	    Integer tmp = map.get(nodeIndex);
	    return tmp != null ? tmp.intValue() : -1;
	}

	private final void upward(int index) {
	    if(index == 0) return;
	    
	    int parent = (index-1)/2;
	    if(nodes[index].value < nodes[parent].value) {
		replace(index, parent);
		upward(parent);
	    }
	}

	private final void downward(int index) {
	    int left = 2*index+1;
	    int right = 2*index+2;

	    if(right < count) {
		int smaller = (nodes[left].value < nodes[right].value ? left : right);
		if(nodes[index].value > nodes[smaller].value) {
		    replace(index, smaller);
		    downward(smaller);
		}
	    } else if(left < count) {
		if(nodes[index].value > nodes[left].value) {
		    replace(index, left);
		    downward(left);
		}
	    }
	}

	private final void replace(int index1, int index2) {
	    int nodeIndex1 = nodes[index1].index;
	    int nodeIndex2 = nodes[index2].index;
	    map.put(nodeIndex1, index2);
	    map.put(nodeIndex2, index1);
	    
	    Node tmp = nodes[index1];
	    nodes[index1] = nodes[index2];
	    nodes[index2] = tmp;
	}
	    
    }
}