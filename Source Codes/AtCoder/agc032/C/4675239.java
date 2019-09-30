import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;

public class Main {
	Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		Main m = new Main();
		m.run();
	}
	
	void run() {
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		List<Set<Integer>>g = new ArrayList<Set<Integer>>();
		
		for(int i = 0 ;i < n+1 ; i ++) {
			g.add(new HashSet<Integer>());
		}
		for(int i = 0 ; i < m; i++) {
			int a = sc.nextInt() ;
			int b = sc.nextInt() ;
			g.get(a).add(b);
			g.get(b).add(a);
		}
		
		if(!removeCircuit(g)) {
			System.out.println("No");
			return ;
		}
		if(!removeCircuit(g)) {
			System.out.println("No");
			return ;
		}
		if(!removeCircuit(g)) {
			System.out.println("No");
			return ;
		}
		
		while(true) {
			boolean f = true;
			for(int i = 0 ;i < n+1 ; i++) {
				if(g.get(i).size() != 0) {
					f = false;
					if(!removeCircuit2(g)) {
						System.out.println("No");
						return ;
					}
					break;
				}
			}
			if(f) break;
		}
		System.out.println("Yes");
	}
	
	boolean removeCircuit(List<Set<Integer>> g) {
		
		int start = -1;
		int goal = -1;
		
		for(int i = 0; i < g.size(); i++) {
			start = i;
			for(int j : g.get(i)) {
				goal = j;
			}
			if(goal != -1) {
				break;
			}
		}
		if(goal == -1) {
			return false;
		}
		
		g.get(start).remove(goal);
		g.get(goal).remove(start);
		

		Set<Integer> visited = new HashSet<Integer>();

		PriorityQueue<int[]> queue = new PriorityQueue<int[]>((a1,a2)->Integer.compare(a1[1],a2[1]));
		queue.add(new int[]{start,0,-1});
		
		int prev[] = new int[g.size()];

		while(true) {
			if(queue.isEmpty()) {
				return false;
			}
			int[] now = queue.poll();

			if(visited.contains(now[0])) {
				continue;
			}
			visited.add(now[0]);
			prev[now[0]] = now[2];

			if(now[0] == goal) {
				break;
			}
			
			for(int j: g.get(now[0])) {
				if(!visited.contains(j)) {
					queue.add(new int[] {j,now[1]+1, now[0]});
				}
			}
		}
		
		int now = goal;
		for(;now != start;) {
			int p = prev[now];
			g.get(now).remove(p);
			g.get(p).remove(now);

			now = p;
		}
		
		return true;
	}

	
	boolean removeCircuit2(List<Set<Integer>> g) {
		
		int start = -1;
		int goal = -1;
		
		for(int i = 0; i < g.size(); i++) {
			start = i;
			for(int j : g.get(i)) {
				goal = j;
			}
			if(goal != -1) {
				break;
			}
		}
		if(goal == -1) {
			return false;
		}
		
		g.get(start).remove(goal);
		g.get(goal).remove(start);
		
		int now = start;

		while(now != goal) {
			int next = -1;

			for(int j: g.get(now)) {
				next = j;
				break;
			}
			
			if(next == -1) {
				return false;
			}
			
			g.get(now).remove(next);
			g.get(next).remove(now);

			now = next;
		}
		
		return true;
	}

}