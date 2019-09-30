import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		sc.close();

		String[] a = s.split("\\+");
		int ans = 0;
		for (String s2 : a) {
			String[] b = s2.split("\\*");
			int min = Integer.MAX_VALUE;
			for (String s3 : b) {
				if ("0".equals(s3)) {
					min = 0;
					break;
				}
				min = Math.min(min, s3.length());
			}
			ans += min;
		}
		System.out.println(ans);
	}
}