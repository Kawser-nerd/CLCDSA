import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		long a = sc.nextLong();
		int n = (int)Math.sqrt(a);
		int min = Integer.MAX_VALUE;
		for (int i=1; i<=n; i++) {
			if (a%i==0) min = Math.max(String.valueOf(i).length(), String.valueOf(a/i).length());
		}
		System.out.println(min);
		
	}
}