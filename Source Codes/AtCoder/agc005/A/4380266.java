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
		
		String s = sc.next();
		ArrayDeque<Character> dq = new ArrayDeque<>();
		for (int i=0; i<s.length(); i++) {
			char c = s.charAt(i);
			if (c == 'T') {
				if (dq.peekFirst()==null || dq.peekFirst()=='T') {
					dq.addFirst(c);
				}
				else if (dq.peekFirst() == 'S') {
					dq.removeFirst();
				}
			}
			else if (c == 'S') {
				dq.addFirst(c);
			}
		}
		
		System.out.println(dq.size());
		
	}
}