import java.util.*;
public class A {
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=T; ++ii) {
			//Something
			long N = sc.nextLong();
			int PD = sc.nextInt();
			int PG = sc.nextInt();
			boolean broken = (PG == 100 && PD < 100);
			broken |= (PG == 0 && PD > 0);
			int K = (PD == 0) ? 100 : gcd(PD, 100);
			broken |= (N < 100 / K);
			System.out.printf("Case #%d: %s\n",ii, (broken) ? "Broken" : "Possible");
		}
	}
	public static int gcd (int a, int b) {
		while (b != 0) {
			int tmp = b;
			b = a % b;
			a = tmp;
		}
		return a;
	}
}