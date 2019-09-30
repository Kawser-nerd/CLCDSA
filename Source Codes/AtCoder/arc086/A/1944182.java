import java.util.*;
public class Main{
	
	public static class Pair implements Comparable<Pair>{
		int id, val;
		public Pair(int id, int val) {
			this.id = id; this.val = val;
		}
		@Override
		public int compareTo(Pair o) {
			return Integer.compare(this.val, o.val);
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt(), K = sc.nextInt();
		
		int arr[] = new int[200001];
		HashSet<Integer> set = new HashSet<Integer>();

		for(int i = 1; i<=N; i++) {
			int n = sc.nextInt();
			arr[n]++;
			set.add(n);
		}

		PriorityQueue<Pair> queue = new PriorityQueue<Pair>();
		for(int i = 1; i<=N; i++) {
			if(arr[i] != 0) queue.add(new Pair(i, arr[i]));
		}
		
		int count = 0;
		while(set.size() > K) {
			count += queue.peek().val;
			set.remove(queue.poll().id);
		}
		
		System.out.println(count);
	}

}