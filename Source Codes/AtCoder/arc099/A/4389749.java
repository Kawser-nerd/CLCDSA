import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt(), k = sc.nextInt();
		int[] ar = new int[n];
		for (int i=0; i<n; i++) ar[i] = sc.nextInt();
		
		System.out.println((int)Math.ceil((double)(n-1)/(double)(k-1)));
		
	}
}