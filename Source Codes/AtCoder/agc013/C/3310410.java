import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int l = sc.nextInt();
		int t = sc.nextInt();
		int[] x = new int[n];
		int[] w = new int[n];
		for(int i=0; i<n; i++){
			x[i] = sc.nextInt();
			w[i] = sc.nextInt();
		}

		int cnt = 0;
		for(int i=1; i<n; i++){
			if(w[0]==1 && w[i]==2){
				if(t*2>=x[i]-x[0]){
					cnt += (1+(t*2-x[i]+x[0])/l);
				}
			}
			else if(w[0]==2 && w[i]==1){
				if(t*2>=l-x[i]+x[0]){
					cnt -= (1+(t*2-l+x[i]-x[0])/l);
				}
			}
		}
		if(w[0]==1){
			cnt %= n;
		}
		else{
			cnt = ((cnt%n)+n)%n;
		}

		for(int i=0; i<n; i++){
			if(w[i]==1){
				x[i] = (x[i]+t)%l;
			}
			else{
				x[i] = ((x[i]-t)%l+l)%l;
			}
		}
		int dist0 = x[0];
		Arrays.sort(x);
		int index0 = 0;
		if(w[0]==1){
			for(int i=n-1; i>=0; i--){
				if(x[i]==dist0){
					index0 = i;
					break;
				}
			}
		}
		else{
			for(int i=0; i<n; i++){
				if(x[i]==dist0){
					index0 = i;
					break;
				}
			}
		}
		for(int i=0; i<n; i++){
			System.out.println(x[(index0-cnt+n+i)%n]);
		}
	}
}