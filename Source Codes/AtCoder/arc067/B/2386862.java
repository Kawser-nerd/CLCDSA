import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long a = sc.nextLong();
		long b = sc.nextLong();
		long x = 0;
		long y = 0;
		long count = 0;
		for (int i=0;i<n;i++) {
			y = x;
			x = sc.nextInt();
			if (i>0) {
				count += Math.min((x-y)*a, b);
			}
		}
		System.out.println(count);
	}

}