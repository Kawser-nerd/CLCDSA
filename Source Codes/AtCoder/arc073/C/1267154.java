import java.util.*;

public class Main {
	static class Pair {
		int x,y;

		public Pair(int x, int y) {
			this.x = Math.min(x, y);
			this.y = Math.max(x, y);
		}
		
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		Pair[] v = new Pair[N];
		int min = Integer.MAX_VALUE;
		int max = 0;
		for(int i=0; i<N; i++) {
			v[i] = new Pair(sc.nextInt(), sc.nextInt());
			min = Math.min(min, v[i].x);
			max = Math.max(max, v[i].y);
		}
		
		long min1=Long.MAX_VALUE;
		long max1=0;
		long min2=Long.MAX_VALUE;
		long max2=0;
		for(int i=0; i<N; i++) {
			min1 = Math.min(min1, v[i].x);
			max1 = Math.max(max1, v[i].x);
			min2 = Math.min(min2, v[i].y);
			max2 = Math.max(max2, v[i].y);
		}
		long ans = (max1-min1)*(max2-min2);

		Arrays.sort(v, new Comparator<Pair>() {
			public int compare(Pair p1, Pair p2) {
				return p1.x-p2.x;
			}
		});
		long mindiff = v[N-1].x-v[0].x;
		
		long min3=Long.MAX_VALUE;
		long max3=0;
		for(int i=0; i<N; i++) {
			min3 = Math.min(min3, v[i].y);
			max3 = Math.max(max3, v[i].y);
			mindiff = Math.min(mindiff, i==N-1 ? max3-min3: Math.max(max3, v[N-1].x) - Math.min(min3, v[i+1].x));
		}
		
		ans = Math.min(ans, mindiff*(max-min));
		
		System.out.println(ans);
		sc.close();
	}
}