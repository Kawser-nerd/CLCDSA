import java.util.*;

public class Main {
	public static void main(String[] args) {
		int i;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] h = new int[n];
		int max = 0;
		for(i=0; i<n; i++) {
			h[i] = sc.nextInt();
			if(max < h[i]) max = h[i];
		}
		sc.close();
		sc = null;
		int ans = 0;
		for(i=1; i<=max; i++) {
			boolean f = false;
			for(int j=0; j<n; j++) {
				if(!f && h[j] >= i) {ans++;f = true;}
				else if(f &&  h[j] < i) {f = false;}
			}
		}
		System.out.println(ans);
	}
}