import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		long sum = 0;
		for (int i=0; i<n; i++) sum += sc.nextInt();
		System.out.println(sum%2==0? "YES" : "NO");
		
	}
}