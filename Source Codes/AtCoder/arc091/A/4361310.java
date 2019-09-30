import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int nextInt () {return Integer.parseInt(sc.next());}
	static int[] nextIntArray (int n) {return IntStream.range(0,n).map(i->nextInt()).toArray();}
	static int max (int... ar) {Arrays.sort(ar);return ar[ar.length-1];}
	static int min (int... ar) {Arrays.sort(ar);return ar[0];}
	static String yesno (boolean b) {return b?"Yes":"No";}
	public static void main(String[] args) {
		
		int n = nextInt(), m = nextInt();
		long h = min(n, m), w = max(n, m);
		long ans = 0;
		
		if (h==1 && w==1) {
			ans = 1;
		}
		else if (h==1 && w!=1) {
			ans =w-2;
		}
		else ans = (h-2) * (w-2);
		
		System.out.println(ans);
	}
}