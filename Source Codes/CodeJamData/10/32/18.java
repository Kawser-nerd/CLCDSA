import java.util.Scanner;


public class B {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			long L = sc.nextInt();
			long P = sc.nextInt();
			long C = sc.nextInt();
			
			int step = 1;
			long N = L * C;
			while (N < P) {
				step++;
				N *= C;
			}
			int ans = 0;
			ans = (int)Math.ceil(Math.log(step) / Math.log(2));
			System.out.println("Case #" + t + ": " + ans);
//			System.out.println(L + " " + P + " " + C + " " + ans);
		}
	}

}
