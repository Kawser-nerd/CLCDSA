import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	
	private static final int RESULT_SCALE = 6;
	
	private static final int MID_SCALE = 20;

	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in) ) {
			//read n, q
			int n = sc.nextInt();
			int q = sc.nextInt();
			//read cones
			Cone[] cones = new Cone[n];
			for ( int i = 0; i < n; i++ ) {
				int x = sc.nextInt();
				int r = sc.nextInt();
				int h = sc.nextInt();
				cones[i] = new Cone(x, r, h);
			}
			//read queries and solve
			for ( int i = 0; i < q; i++ ) {
				int a = sc.nextInt();
				int b = sc.nextInt();
				if ( a > b ) throw new IllegalStateException("a=" + a + ",b=" + b);
				BigDecimal answer = BigDecimal.ZERO;
				if ( a != b ) {
					for ( Cone cone : cones ) {
						answer = answer.add(cone.calcIntersectionVolume(a, b));
					}
				}
				System.out.println(answer.setScale(RESULT_SCALE, BigDecimal.ROUND_HALF_UP));
			}
		}
		finally {
			
		}
	}
	
	private static class Cone {
		
		private final int x;
		private final int r;
		private final int h;
		
		private Cone(int x, int r, int h) {
			this.x = x;
			this.r = r;
			this.h = h;
		}

		public BigDecimal calcIntersectionVolume(int a, int b) {
			if ( a >= b ) return BigDecimal.ZERO;
			if ( a >= x + h || b <= x ) return BigDecimal.ZERO;
			
			int left = Math.max(a, x);
			int right = Math.min(b, x+h);
			BigDecimal radius = BigDecimal.valueOf(r);
			BigDecimal height = BigDecimal.valueOf(h);
			int tmp1 = (x+h) - left;
			tmp1 = tmp1 * tmp1 * tmp1;
			int tmp2 = (x+h) - right;
			tmp2 = tmp2 * tmp2 * tmp2;
			int tmp3 = tmp1 - tmp2;
			BigDecimal ratio = radius.divide(height, MID_SCALE, BigDecimal.ROUND_HALF_UP);
			return BigDecimal.valueOf(tmp3).multiply(ratio).multiply(ratio)
					.multiply(BigDecimal.valueOf(Math.PI)).divide(BigDecimal.valueOf(3), MID_SCALE, BigDecimal.ROUND_HALF_UP);
		}
	}
	
}