import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int nextInt () {return Integer.parseInt(sc.next());}
	static long nextLong () {return Long.parseLong(sc.next());}
	static int[] nextIntArray (int n) {return IntStream.range(0,n).map(i->nextInt()).toArray();}
	static int max (int... ar) {Arrays.sort(ar);return ar[ar.length-1];}
	static int min (int... ar) {Arrays.sort(ar);return ar[0];}
	static String yesno (boolean b) {return b?"Yes":"No";}
	static int maxInt = Integer.MAX_VALUE;
	static int minInt = Integer.MIN_VALUE;
	public static void main(String[] args) {
		
		int n = nextInt();
		int[] ar = new int[n+2];
		for (int i=1; i<n+1; i++) {
			ar[i] = nextInt();
		}
		long sum = 0;
		for (int i=1; i<n+2; i++) {
			sum += Math.abs(ar[i]-ar[i-1]);
		}
		for (int i=1; i<n+1; i++) {
			System.out.println(sum + Math.abs(ar[i+1]-ar[i-1]) - (Math.abs(ar[i+1]-ar[i])+Math.abs(ar[i]-ar[i-1])));
		}
		
	}
}