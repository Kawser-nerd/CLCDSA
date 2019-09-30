import java.util.Scanner;

public class C {
	private static int[] SET = {4, 5, 3, 2, 1};
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int cases = scan.nextInt();
		int r, n, m, k, count;
		int[] res;
		long lcmAll;
		for (int c = 1; c <= cases; c++) {
			r = scan.nextInt();
			n = scan.nextInt();
			m = scan.nextInt();
			k = scan.nextInt();
			res = new int[n];
			System.out.println("Case #" + c + ": ");
			for (int i = 0; i < r; i++)
			{
				lcmAll = 1;
				for (int j = 0; j < k; j++)
					lcmAll = lcm(lcmAll, scan.nextInt());
				count = 0;
				for (int j : SET) {
					while (count < n && (lcmAll % j) == 0) {
						lcmAll /= j;
						res[count] = j;
						count++;
					}
				}
				if (res[0] == 4 && res[n-1] == 1)
				{
					res[0] = 2;
					res[n-1] = 2;
				}
				for (int j : res)
					System.out.print(j == 1 ? 2 : j);
				System.out.println();
			}
		}
	}
	private static long gcd(long a, long b)
	{
		if (b == 0)
			return a;
		return gcd(b, a%b);
	}
	private static long lcm(long a, long b) {
		return a / gcd(a, b) * b;
	}
}
