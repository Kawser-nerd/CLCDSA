import java.util.Scanner;
public class Main {
	public static long frac[] = new long[100020];
	public static final int ZYY = 1000000007;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int x = scan.nextInt();
		int y = scan.nextInt();
		scan.close();
		if (Math.abs(x - y) > 1) {
			System.out.println('0');
			return;
		}
		frac[0] = 1;
		for (int i = 1; i <= 100000; i++)
			frac[i] = frac[i - 1] * i % ZYY;
		long ans = frac[x] * frac[y] % ZYY;
		if (x == y) ans = ans * 2 % ZYY;
		System.out.println(ans);
		return;
	}
}