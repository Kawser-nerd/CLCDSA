import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

class Main {

	static Scanner sc = new Scanner(System.in);
	static int maxInt = Integer.MAX_VALUE;
	static int minInt = Integer.MIN_VALUE;

	public static void main(String[] args) {
		//---------------------------------------------------------

		int one = min(nextInt()*4, nextInt()*2, nextInt());
		int two = nextInt();
		int n = nextInt();
		
		if (one*2 <= two) {
			System.out.println((long)one*n);
		}
		else {
			System.out.println((long)n/2*two + (long)n%2*one);
		}
		
		
		//---------------------------------------------------------
	}

	static int nextInt () {return Integer.parseInt(sc.next());}
	static long nextLong () {return Long.parseLong(sc.next());}
	static int[] nextIntArray (int n) {return IntStream.range(0,n).map(i->nextInt()).toArray();}
	static int max (int... ar) {Arrays.sort(ar);return ar[ar.length-1];}
	static int min (int... ar) {Arrays.sort(ar);return ar[0];}
	static String yesno (boolean b) {return b?"Yes":"No";}

}