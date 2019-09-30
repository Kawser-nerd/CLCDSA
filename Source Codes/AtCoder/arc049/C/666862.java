import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int A = sc.nextInt();
		int[] x = new int[A];
		int[] y = new int[A];
		boolean[][] m = new boolean[N][N];
		for(int i=0; i<A; i++) {
			x[i] = sc.nextInt()-1;
			y[i] = sc.nextInt()-1;
			m[x[i]][y[i]] = true;
		}
		int B = sc.nextInt();
		int[] u = new int[B];
		int[] v = new int[B];
		for(int i=0; i<B; i++) {
			u[i] = sc.nextInt()-1;
			v[i] = sc.nextInt()-1;
		}
		
		int ans = 0;
		boolean[] used = new boolean[N];
		for(int t=0; t<1<<B; t++) {
			int cnt = 0;
			Arrays.fill(used, false);
			boolean updated = true;
			while(updated) {
				updated = false;
				for(int i=0; i<N; i++) {
					if(used[i])
						continue;
					boolean ng = false;
					for(int j=0; j<B; j++) {
						if(((t>>j)&1)==0) {
							if(u[j]==i) {
								ng=true;
								break;
							}
						} else {
							if(v[j]==i && !used[u[j]]) {
								ng=true;
								break;
							}
						}
					}
					if(ng)
						continue;
					for(int j=0; j<A; j++) {
						if(x[j]==i && !used[y[j]]) {
							ng=true;
							break;
						}
					}
					if(!ng) {
						used[i] = true;
						cnt++;
						updated = true;
					}
				}
			}
			
			ans = Math.max(ans, cnt);
		}
		
		System.out.println(ans);
		sc.close();
	}
}