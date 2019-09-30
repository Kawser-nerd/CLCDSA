import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int nextInt () {return Integer.parseInt(sc.next());}
	static int[] nextIntArray (int n) {return IntStream.range(0,n).map(i->nextInt()).toArray();}
	static int max (int... ar) {Arrays.sort(ar);return ar[ar.length-1];}
	static int min (int... ar) {Arrays.sort(ar);return ar[0];}
	static int maxInt = Integer.MAX_VALUE;
	static int minInt = Integer.MIN_VALUE;
	public static void main(String[] args) {

		int a = nextInt(), b = nextInt(), n = nextInt();
		int lcm = lcm(a, b);
		out.println((lcm*(int)Math.ceil((double)n/(double)lcm)));

	}

	static int gcd (int a, int b) {return b>0?gcd(b,a%b):a;}
	static int lcm (int a, int b) {return a*b/gcd(a,b);}

}