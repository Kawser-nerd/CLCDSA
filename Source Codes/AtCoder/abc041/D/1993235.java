import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

/**
 * https://abc041.contest.atcoder.jp/tasks/abc041_d
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.next());
		int M = Integer.parseInt(sc.next());
		
		Node[] nodes = new Node[N];
		for(int i=0; i<N; i++)  nodes[i] = new Node(i);
		for(int i=0; i<M; i++){
			Node x = nodes[Integer.parseInt(sc.next())-1];
			Node y = nodes[Integer.parseInt(sc.next())-1];
			x.neighbor.put(y,1);
		}
		sc.close();
		System.out.println(getCombinationOfTopologicalSort(nodes));
	}
	
	static long getCombinationOfTopologicalSort(Node[] nodeList){
		int N = nodeList.length;
		int S = 1<<N;
		long[] dp = new long[S];
		dp[0] = 1;
		Queue<Integer> que = new ArrayDeque<>();
		que.add(0);
		while(!que.isEmpty()) {
			int s = que.remove();
			for (int i = 0; i < N; i++) {
				if((1<<i&s)>0) continue;
				boolean check = true;
				for (int j = 0; j < N; j++){
					if((1<<j&s)>0 && nodeList[i].neighbor.containsKey(nodeList[j])) {
						check = false;
						break;
					}
				}
				if(!check) continue;
				if (dp[s+(1<<i)] == 0) que.add(s+(1<<i));
				dp[s+(1<<i)] += dp[s];
			}
        }
		return dp[S-1];
	}
	
	static class Node{
		int id;
		Map<Node,Integer> neighbor = new HashMap<>();
		Node(int id){
			this.id = id;
		}
	}

}