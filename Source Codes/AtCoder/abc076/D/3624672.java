import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] t = new int[n];
		int[] v = new int[n+1];
		for(int i=0;i<n;i++) {
			t[i] = in.nextInt();
		}
		for(int i=0;i<n;i++) {
			v[i] = in.nextInt();
		}
		int limitSpeed = 0;
		for(int i=n-1;i>=0;i--) {
			if(v[i]>limitSpeed+t[i]) {
				v[i] = limitSpeed+t[i];
				limitSpeed = limitSpeed+t[i];
			}else {
				limitSpeed = v[i];
			}
		}
		int maxSpeed = 0;
		for(int i=0;i<n;i++) {
			if(v[i]>maxSpeed+t[i]) {
				v[i] = maxSpeed+t[i];
				maxSpeed = maxSpeed+t[i];
			}else {
				maxSpeed = v[i];
			}
		}
		double ans = 0;
		int vnow = 0;
		for(int i=0;i<n;i++) {
			if(v[i]>=vnow+t[i] && (v[i+1]>=vnow+t[i])) {
				ans += (double)vnow*t[i] + (double)t[i]*t[i]/2;
				vnow += t[i];
			}else if(v[i]>=((double)t[i]+vnow+v[i+1])/2) {
				ans += ((double)t[i]+vnow+v[i+1])*t[i]/2 - ((double)t[i]-vnow+v[i+1])*((double)t[i]-vnow+v[i+1])/8 - ((double)t[i]+vnow-v[i+1])*((double)t[i]+vnow-v[i+1])/8;
				vnow = v[i+1];
			}else {
				ans += v[i]*t[i] - ((double)v[i]-vnow)*((double)v[i]-vnow)/2 - (v[i]>v[i+1]?((double)v[i]-v[i+1])*((double)v[i]-v[i+1])/2:0);
				vnow = Math.min(v[i], v[i+1]);
			}
		}
		System.out.println(ans);
		in.close();

	}

}