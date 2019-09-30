import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		char[] s = sc.next().toCharArray();
		
		boolean[] isSheep = solve(s);
		
		if(isSheep==null) {
			System.out.println(-1);
		} else {
			char[] ans = new char[N];
			for(int i=0; i<N; i++) {
				ans[i] = isSheep[i] ? 'S' : 'W';
			}
			System.out.println(ans);
		}
		sc.close();
	}
	
	static boolean[] solve(char[] s) {
		int N = s.length;
		boolean[] v = new boolean[N];
		for(int i=0; i<4; i++) {
			boolean ok = true;
			v[0] = i%2==0;
			v[1] = i/2==0;
			for(int j=0; j<N; j++) {
				boolean next = v[j]^v[(j+1)%N]^s[(j+1)%N]=='o';
				if(N-2<=j) {
					if(v[(j+2)%N]!=next) {
						ok = false;
						break;
					}
				}
				v[(j+2)%N] = next;
			}
			if(ok)
				return v;
		}
		return null;
	}
}