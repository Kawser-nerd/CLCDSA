import java.util.*;

// ARC 79-C
// http://arc079.contest.atcoder.jp/tasks/arc079_a

public class Main {
	
	public static void main (String[] args) throws InterruptedException {
		Scanner in = new Scanner(System.in);
		
		int N = in.nextInt();
		int M = in.nextInt();
		
		Set<Integer> from1 = new TreeSet<Integer>();
		Set<Integer> toN = new TreeSet<Integer>();
		
		for (int i = 0; i < M; i++) {
			int s = in.nextInt();
			int g = in.nextInt();
			
			if (s == 1 && !from1.contains(g)) {
				from1.add(g);
			} else if (g == N && !toN.contains(s)) {
				toN.add(s);
			}
		}
		
		String answer = "IMPOSSIBLE";

		for (int island: from1) {
			if (toN.contains(island)) {
				answer = "POSSIBLE";
				break;
			}
		}
				
		System.out.println(answer);
	}
}