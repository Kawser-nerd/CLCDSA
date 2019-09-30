import java.util.Scanner;

public class Main {
	private static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int n = sc.nextInt();
		StringBuffer sb = new StringBuffer();
		for (int i = 0;i < (n-1)/9+1;i++) {
			sb.append((n-1)%9+1);
		}
		System.out.println(sb.toString());
	}
}