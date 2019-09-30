import java.util.*;

public class Main {
	

	
	public static class Sushi{
		int t;
		int d;
		
		public Sushi(int t, int d) {
			this.t = t;
			this.d = d;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int K = sc.nextInt();
		Sushi[] sushis = new Sushi[N];
		
		for (int i = 0; i < N; i++) {
			int t = sc.nextInt();
			int d = sc.nextInt();
			sushis[i] = new Sushi(t, d);
		}
		
		Arrays.sort(sushis, new Comparator<Sushi>() {
			public int compare(Sushi s1, Sushi s2) {
				return s2.d - s1.d;
			}
		});
		
		ArrayList<Sushi> extras = new ArrayList<Sushi>();
		HashMap<Integer, Boolean> types = new HashMap<Integer, Boolean>();
		
		long typeCount = 0;
		long deliciousness = 0;
		for (int i = 0; i < K; i++) {
			Sushi s = sushis[i];
			if (!types.containsKey(s.t)) {
				types.put(s.t, true);
				typeCount++;
			} else {
				extras.add(s);
			}
			deliciousness += s.d;
		}
		
		long satisfaction = typeCount*typeCount + deliciousness;
		
		for (int i = K; i < N && extras.size() > 0; i++) {
			Sushi s = sushis[i];
			if (!types.containsKey(s.t)) {
				types.put(s.t, true);
				typeCount++;
				deliciousness -= extras.get(extras.size()-1).d;
				deliciousness += s.d;
				extras.remove(extras.size()-1);
				satisfaction = Math.max(satisfaction, typeCount*typeCount + deliciousness);
			}
		}
		
		System.out.println(satisfaction);
	}
}