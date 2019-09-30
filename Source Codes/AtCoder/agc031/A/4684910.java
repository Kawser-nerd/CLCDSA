import java.util.Scanner;
import java.util.BitSet;

public class Main{
	
	static final int N = 100000 + 10, mod = 1000000007;
	static int n;
	static int cnt[] = new int[30];
	static String s;
	
	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		n = inp.nextInt();	
		s = inp.next();
		for(int i = 0; i < s.length(); ++i) {
			cnt[ s.charAt(i) - 'a' ] ++;
			//System.out.println(s.charAt(i) + " " + (s.charAt(i) - 'a'));
		}
		long res = 1;
		for(int i = 0; i < 26; ++i) {
			res = res * (cnt[i] + 1) % mod;
		}
		System.out.print((res + mod - 1) % mod);
	}
}