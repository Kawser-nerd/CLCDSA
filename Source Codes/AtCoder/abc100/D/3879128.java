import java.util.*;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);		
		int n = sc.nextInt();
		int m = sc.nextInt();
		Cake[] cakes = new Cake[n];
		for (int i = 0; i < n; i++) {
			cakes[i] = new Cake(sc.nextLong(), sc.nextLong(), sc.nextLong());
		}
		long max = 0;
		for (int type = 0; type < 4; type++) {
			Arrays.sort(cakes, new MyComparator(type));
			long x = 0;
			long y = 0;
			long z = 0;
			for (int i = 0; i < m; i++) {
				x += cakes[i].x;
				y += cakes[i].y;
				z += cakes[i].z;
			}
			long total = abs(x) + abs(y) + abs(z);
			if (total > max) {
				max = total;
			}
			x = 0;
			y = 0;
			z = 0;
			total = 0;
			for (int i = 0; i < m; i++) {
				x += cakes[n - i - 1].x;
				y += cakes[n - i - 1].y;
				z += cakes[n - i - 1].z;
			}
			total = abs(x) + abs(y) + abs(z);
			if (total > max) {
				max = total;
			}
		}
		System.out.println(max);
	}
	
	public static long abs(long x) {
		if (x > 0 ) {
			return x;
		} else {
			return -x;
		}
	}
	
	public static class MyComparator implements Comparator<Cake> {
		int type;
		
		public MyComparator(int type) {
			this.type = type;
		}
		
		public MyComparator() {
			this(0);
		}
		public int compare(Cake c1, Cake c2) {
			long a;
			long b;
			if (type == 0) {
				a = c1.x + c1.y + c1.z;
				b = c2.x + c2.y + c2.z;
			} else if (type == 1) {
				a = -c1.x + c1.y + c1.z;
				b = -c2.x + c2.y + c2.z;
			} else if (type == 2) {
				a = c1.x - c1.y + c1.z;
				b = c2.x - c2.y + c2.z;
			} else {
				a = c1.x + c1.y - c1.z;
				b = c2.x + c2.y - c2.z;
			}
			if (a == b) {
				return 0;
			} else if (a > b) {
				return 1;
			} else {
				return -1;
			}
		}
	}
	
	public static class Cake {
		public long x;
		public long y;
		public long z;
		
		public Cake (long x, long y, long z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}
	}
}