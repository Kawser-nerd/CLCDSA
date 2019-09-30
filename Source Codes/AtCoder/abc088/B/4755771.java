import java.util.*;
 
public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int n = sc.nextInt();
		int alice = 0;
		int bob = 0;
		Integer[] ar = new Integer[n];
		for (int i=0; i<n; i++) {
			ar[i] = sc.nextInt();
		}
		Arrays.sort(ar,Comparator.reverseOrder());
		for (int i=0; i<n; i++) {
			int a = ar[i];
			if (i%2==0) {alice += a;}
			else {bob += a;}
		}
		System.out.println(Math.abs(alice-bob));
	}
}