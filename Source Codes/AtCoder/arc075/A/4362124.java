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
		
		//10?????????????????????
		int n = nextInt();
		int[] ar = nextIntArray(n);
		Arrays.sort(ar);
		long sum = 0;
		long notTenMultiple = -1;
		for (int i=n-1; i>=0; i--) {
			sum += ar[i];
			if (ar[i]%10 != 0) {
				notTenMultiple = ar[i];
			}
		}
		
		if (notTenMultiple == -1) System.out.println(0);
		else if (sum%10 != 0) System.out.println(sum);
		else System.out.println(sum - notTenMultiple);
		
	}
}