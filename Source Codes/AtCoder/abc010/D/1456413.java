import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 * http://abc010.contest.atcoder.jp/tasks/abc010_4
 */
public class Main {
	
	private static Map<Integer,Set<Integer>> neighborsMap = new HashMap<>();
	private static Set<Integer> p = new HashSet<Integer>();
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		final int G = sc.nextInt();
		final int E = sc.nextInt();
		for(int i=0; i<=N; i++) neighborsMap.put(i, new HashSet<Integer>());
		for(int i=0; i<G; i++) p.add(sc.nextInt());
		for(int i=0; i<E; i++){
			int id1 = sc.nextInt();
			int id2 = sc.nextInt();
			neighborsMap.get(id1).add(id2);
			neighborsMap.get(id2).add(id1);
		}
		sc.close();
		
		int ans = 0;
		while( p.size()>0 && calcMaxFlow(0, new HashSet<Integer>())){
			ans++;
		}
		System.out.println(ans);

	}
	private static boolean calcMaxFlow(int currentId, Set<Integer> visited) {
		
		visited.add(currentId);
		
		if(p.contains(currentId)){
			p.remove(currentId);
			return true;
		}
		
		Integer[] neighbors = neighborsMap.get(currentId).toArray(new Integer[neighborsMap.get(currentId).size()]);
		if(neighbors.length==0){
			return false;
		}
		
		for(int n: neighbors){
			if(visited.contains(n)){
				continue;
			}
			neighborsMap.get(currentId).remove(n);
			if(!calcMaxFlow(n, visited)){
				neighborsMap.get(currentId).add(n);
			}else{
				return true;
			}
		}
		
		visited.remove(currentId);
		
		return false;
		
	}

}