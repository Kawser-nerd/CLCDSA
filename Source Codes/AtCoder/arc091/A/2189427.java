import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int N = in.nextInt();
		int M = in.nextInt();
		
		long ans = 0;
		if (N >= 3 && M >= 3) {
			ans = (long) (N - 2) * (long) (M - 2);
		} else if (N == 1 && M == 1) {
			ans = 1;
		} else if ((N == 1 && M == 2) || (N == 2 && M == 1) || (N == 2) && (M == 2)) {
			ans = 0;
		} else if (N == 1) {
			ans = M - 2;
		} else if (M == 1) {
			ans = N - 2;
		} else if (N == 2) {
			ans = 0;
		} else if (M == 2) {
			ans = 0;
		}
		
		System.out.println(ans);
	}
}