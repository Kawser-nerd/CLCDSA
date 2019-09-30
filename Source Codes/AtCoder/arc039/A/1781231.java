import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String A = sc.next();
		String B = sc.next();
		int ans = -1001001001;
		for(int i = 0 ; i <= 9 ; i++) {
			// a?j???i??????
			for(int j = 0 ; j <= 2 ; j++) {
				if(i == 0 && j == 0) continue;
				char[] a = A.toCharArray();
				char[] b = B.toCharArray();
				a[j] = (char)(i + '0');
				ans = Math.max(ans, Integer.valueOf(String.valueOf(a)) - Integer.valueOf(String.valueOf(b)));
			}
		}
		for(int i = 0 ; i <= 9 ; i++) {
			// b?j???i??????
			for(int j = 0 ; j <= 2 ; j++) {
				if(i == 0 && j == 0) continue;
				char[] a = A.toCharArray();
				char[] b = B.toCharArray();
				b[j] = (char)(i + '0');
				ans = Math.max(ans, Integer.valueOf(String.valueOf(a)) - Integer.valueOf(String.valueOf(b)));
			}
		}
		System.out.println(ans);
	}
}