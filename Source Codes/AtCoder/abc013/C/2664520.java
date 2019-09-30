import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long N = scan.nextLong();
		long H = scan.nextLong();
		long A = scan.nextLong();
		long B = scan.nextLong();
		long C = scan.nextLong();
		long D = scan.nextLong();
		long E = scan.nextLong();
		scan.close();


		if(H - N * E > 0) {
			System.out.println(0);
			System.exit(0);
		}


		long ans = N * A;
		for(long i = 0; i <= N; i++) {
			long x = i;
			double y1 = (double)(N * E - H -(B + E) * x) / (D + E);
			long y;
			if(y1 < 0) {
				y = 0;
			}else {
				y = (N * E - H -(B + E) * x) / (D + E) + 1;
			}
			long t = A * x + C * y;
			if(ans > t) {
				ans = t;
			}
		}
		System.out.println(ans);
	}
}