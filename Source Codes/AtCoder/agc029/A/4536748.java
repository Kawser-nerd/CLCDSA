import java.util.*;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		long ret = 0;
		long countB = 0;
		int N = S.length();
		for(int i=0;i<N;i++) {
			if(S.charAt(i)=='B') {
				ret += (long)N-1-i;
				countB++;
			}
		}
		System.out.println(ret-(countB*(countB-1))/2);
	}
}