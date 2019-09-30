import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Map.Entry;

/**
 * https://beta.atcoder.jp/contests/abc035/tasks/abc035_d
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int T = sc.nextInt();
		int[] A = new int[N];
		Node[] nodeListA = new Node[N];
		Node[] nodeListB = new Node[N];
		for(int i=0; i<N; i++){
			A[i] = sc.nextInt();
			nodeListA[i] = new Node(i);
			nodeListB[i] = new Node(i);
		}
		for(int i=0; i<M; i++){
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			int cost = sc.nextInt();
			nodeListA[a].neighbor.put(nodeListA[b], cost);
			nodeListB[b].neighbor.put(nodeListB[a], cost);
		}
		sc.close();
		long[] costsA = getFastSingleSourceMinimumCost(nodeListA, nodeListA[0]);
		long[] costsB = getFastSingleSourceMinimumCost(nodeListB, nodeListB[0]);
		
		long ans=0;
		for(int i=0; i<N; i++){
			ans = Math.max(ans, (T-costsA[i]-costsB[i])*A[i]);
		}
		System.out.println(ans);
		
	}
	
	static class Node{
		int id;
		int status = -1;
		long cost;
		Map<Node,Integer> neighbor = new HashMap<>();
		Node(int id){
			this.id = id;
		}
	}
	
	static long[] getFastSingleSourceMinimumCost(Node[] nodeList, Node start){
		long[] costs = new long[nodeList.length];
		for(Node n: nodeList){
			costs[n.id] = n == start ? 0 : Integer.MAX_VALUE;
			n.cost = n == start ? 0 : Integer.MAX_VALUE;
			n.status = -1;
		}
		PriorityQueue<Node> que = new PriorityQueue<>(new Comparator<Node>(){
			public int compare(Node n1, Node n2) {
				return n1.cost < n2.cost ? -1 : 1;
			}
		});
		que.add(start);
		while(que.size()>0){
			Node node = que.remove();
			node.status = 1;
			if(costs[node.id]<node.cost) continue;
			for(Entry<Node,Integer> entry: node.neighbor.entrySet()){
				Node n = entry.getKey();
				int cost = entry.getValue();
				if(costs[n.id]>costs[node.id]+cost){
					costs[n.id] = costs[node.id]+cost;
					n.cost = costs[n.id];
					que.add(n);
				}
			}
		}	
		return costs;	
	}

}