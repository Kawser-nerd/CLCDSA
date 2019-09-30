import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.next());
		
		long[] a = new long[n];
		
		for(int i = 0; i < n; i++) {
			a[i] = Long.parseLong(sc.next());
		}
		
		Arrays.sort(a);
		
		System.out.println(a[a.length-1]-a[0]);
		
	}
}