import java.awt.geom.Point2D;
import java.util.*;

// Foobar Level 4: bringing_a_gun_to_a_guard_fight

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int N = in.nextInt();
		int Z = in.nextInt();
		int W = in.nextInt();
		
		int[] a = new int[N];
		for (int i = 0; i < N; i++) {
			a[i] = in.nextInt();
		}
		
		if (N == 1) {
			System.out.println(Math.abs(a[0] - W));
		} else {
			System.out.println(Math.max(Math.abs(a[N - 1] - a[N - 2]), Math.abs(a[N - 1] - W)));
		}
   }
}