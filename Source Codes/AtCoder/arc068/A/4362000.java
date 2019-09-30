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
		
		//6,5,6,5......???
		
		long n = nextLong();
		if (n%11 == 0) {
			System.out.println(n/11*2);
		}
		else if (n%11 <= 6) {
			System.out.println(n/11*2 + 1);
		}
		else {
			System.out.println(n/11*2 + 2);
		}
		
	}
}