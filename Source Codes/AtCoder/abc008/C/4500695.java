import java.util.*;;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int c[] = new int[N];
		for(int i = 0; i < N; i++) {
			c[i] = sc.nextInt();
		}
		double ans = 0;
		for(int i = 0; i < N; i++){
			double s = 0;
			for(int j = 0; j < N; j++){
				if(c[i] % c[j] == 0 && i != j) s++;
			}
			if(s % 2 == 0){
				ans += (s + 2.0) / (2 * s + 2.0); 
			}else{
				ans += 0.5;
			}
		}
		System.out.println(ans);
	}
}
/*import java.util.*;
public class Main {
	static double ans = 0;
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int c[] = new int[n];
		for(int i = 0; i < n; i++) {
			c[i] = sc.nextInt();
		}
		boolean flag[] = new boolean[n];
		int perm[] = new int[n];
		makePerm(0, perm, flag, c);
		double d = 1;
		for(int i = 1; i <= n; i++) {
			d *= i;
		}
		//System.out.println(ans);
		ans /= d;
		System.out.println(ans);
	}
	
	static void makePerm(int n, int perm[], boolean flag[], int c[]) {
		if(n == perm.length) {
			boolean side[] = new boolean[n];
			Arrays.fill(side, true);
			for(int i = 0; i < perm.length; i++) {
				for(int j = i + 1; j < perm.length; j++) {
					if(perm[j] % perm[i] == 0) {
						side[j] = !side[j];
					}
				}
				//System.out.print(perm[i]);
			}
			//System.out.println();
			int cnt = 0;
			for(int i = 0; i < perm.length; i++) {
				if(side[i]) cnt++;
			}
			ans += cnt;
		//\System.out.println(ans);
		} else {
			for(int i = 0; i < perm.length; i++) {
				if(flag[i]) {
					continue;
				} else {
					perm[n] = c[i];
					flag[i] = true;
					makePerm(n + 1, perm, flag, c);
					flag[i] = false;
				}
			}
		}
	}
}*/