import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int T = sc.nextInt();
		int A = sc.nextInt();
		double b = 1000;
		int best = 0;
		
		for(int i = 1 ; i <= N ; i++) {
			int H = sc.nextInt();
			double a = Math.abs(A - (T - H * 0.006));
			if(a < b) {
				b = a;
				best = i;
			}
		}
		
		System.out.println(best);
	}

}