import java.util.*;
public class Main{
	static void sortpoint(int[] x, int[] y, int n){
		for(int i=0; i<n-1; i++){
			for(int j=n-1; j>i; j--){
				if(x[j-1]>x[j]){
					int t = x[j-1];
					x[j-1] = x[j];
					x[j] = t;
					t = y[j-1];
					y[j-1] = y[j];
					y[j] = t;
				}
			}
		}
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n];
		int[] d = new int[n];
		for(int i=0; i<n; i++){
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
		}
		for(int i=0; i<n; i++){
			c[i] = sc.nextInt();
			d[i] = sc.nextInt();
		}
		sortpoint(a, b, n);
		sortpoint(c, d, n);
		int ans = 0;
		for(int i=0; i<n; i++){
			int j = 0;
			int ymax = -1;
			int index = -1;
			while(j<n && a[j]<c[i]){
				if(a[j]>=0 && b[j]<d[i]){
					if(b[j]>=ymax){
						ymax = b[j];
						index = j;
					}
				}
				j++;
			}
			if(index>=0){
				ans++;
				a[index] = -1;
			}
		}
		System.out.println(ans);
	}
}