import java.util.Scanner;

class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan = new Scanner(System.in);
		long n = scan.nextInt();
		long m = scan.nextInt();
		long ans = 0;
		for (long i=1;i * i <= m;i++) {
			if (m % i != 0)continue;
			long j = m/i;

			if(n * j <= m)ans = Math.max(ans,j);
			if(n * i <= m)ans = Math.max(ans, i);
		}
		System.out.println(ans);
	}

}