import java.util.Scanner;

public class Main {

	private void solve() {
		Scanner in = new Scanner(System.in);
		int X = in.nextInt();
		int K = in.nextInt();
		int[] r = new int[K];
		for (int i = 0; i < K; i++) {
			r[i] = in.nextInt();
		}
		int Q = in.nextInt();
		int[] t = new int[Q];
		int[] a = new int[Q];
		for (int i = 0; i < Q; i++) {
			t[i] = in.nextInt();
			a[i] = in.nextInt();
		}
		int rp = 0;
		int tap = 0;
		
		int low = 0;
		int middle = 0;
		int high = X;
		int l_bound = 0;
		int h_bound = X;
		
		int prev_r = 0;
		while(tap<Q){
			if(rp>=K || t[tap]<=r[rp]){
				if(rp%2==0){ // now down
					if(a[tap]<=l_bound){
						System.out.println(Math.max(0,low-(t[tap]-prev_r)));
					}else if(a[tap]>=h_bound){
						System.out.println(Math.max(0, high-(t[tap]-prev_r)));
					}else{
						System.out.println(Math.max(0, a[tap]+middle-(t[tap]-prev_r)));
					}
				}else{// now up
					if(a[tap]<=l_bound){
						System.out.println(Math.min(X,low+(t[tap]-prev_r)));
					}else if(a[tap]>=h_bound){
						System.out.println(Math.min(X, high+(t[tap]-prev_r)));
					}else{
						System.out.println(Math.min(X, a[tap]+middle+(t[tap]-prev_r)));
					}
				}
				tap ++;
			}else{
				if(rp%2==0){//down
					middle -= r[rp]-prev_r;
					low = Math.max(0, low-(r[rp]-prev_r));
					high = Math.max(0, high-(r[rp]-prev_r));
				}else{// up
					middle += r[rp]-prev_r;
					low = Math.min(X, low+(r[rp]-prev_r));
					high = Math.min(X, high+(r[rp]-prev_r));
				}
				if(l_bound+middle<0){
					l_bound = -middle;
				}
				if(h_bound+middle>X){
					h_bound = X -middle;
				}
				prev_r = r[rp];
				rp ++;
			}
		}
	}
	
	public static void main(String[] args) {
		new Main().solve();
	}
}