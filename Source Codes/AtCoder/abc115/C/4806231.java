import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.next());
		int k = Integer.parseInt(sc.next());
		
		long[] h = new long[n];
		
		for(int i = 0; i < n ;i++) {
			h[i] = Long.parseLong(sc.next());
		}
		
		Arrays.sort(h);
		
		long res = Long.MAX_VALUE;
		
		for(int i = 0; i < n-(k-1); i++) {
			res = Math.min(h[i+(k-1)] - h[i], res);
		}
		
		System.out.println(res);
	}

}