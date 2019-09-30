import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int maxInt = Integer.MAX_VALUE;
	static int minInt = Integer.MIN_VALUE;
	public static void main(String[] args) {
		
		int a = nextInt(), b = nextInt();
		int ans = maxInt;
		
		if (a <= b) {
			ans = Math.min(ans, b - a);
		}
		if (-a <= b) {
			ans = Math.min(ans, b - (-a) + 1);
		}
		if (a <= -b) {
			ans = Math.min(ans, (-b) - a + 1);
		}
		if (-a <= -b) {
			ans = Math.min(ans, (-b) - (-a) + 2);
		}
		
		System.out.println(ans);
		
	}
	
	static int nextInt () {return Integer.parseInt(sc.next());}
	static long nextLong () {return Long.parseLong(sc.next());}
	static int[] nextIntArray (int n) {return IntStream.range(0,n).map(i->nextInt()).toArray();}
	static int max (int... ar) {Arrays.sort(ar);return ar[ar.length-1];}
	static int min (int... ar) {Arrays.sort(ar);return ar[0];}
	static String yesno (boolean b) {return b?"Yes":"No";}
	
}