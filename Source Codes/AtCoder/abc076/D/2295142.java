import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] time = new int[n + 3];
		int[] maxv = new int[n + 2];
		time[0] = 0;
		time[1] = 0;
		for (int i = 0, k = 2; i < n; i++, k++) {
			time[k] = sc.nextInt();
			time[k] += time[k-1];
		}
		time[n + 2] = time[n + 1];
		int totalTime = time[n+2];
		maxv[0] = 0;
		maxv[n + 1] = 0;
		for (int i = 1; i <= n; i++) {
			maxv[i] = sc.nextInt();
		}

//		System.out.println(Arrays.toString(time));
//		System.out.println(Arrays.toString(maxv));
//		System.out.println(totalTime);

		double[] maxV_Every_0_5_seconds = new double[totalTime * 2+1];
		Arrays.fill(maxV_Every_0_5_seconds, Integer.MAX_VALUE);
		for (double i = 0; i < totalTime * 2+1; i++) {
			for(int j = 0; j < n+2; j++) {
				//j??????time[j+1]-time[j]?????????max[v]
				if(i <= 2*time[j]) {
					maxV_Every_0_5_seconds[(int) i] = Math.min(maxV_Every_0_5_seconds[(int) i], maxv[j]+time[j]-(i/2));
				}
				if(i >= 2*time[j+1]) {
					maxV_Every_0_5_seconds[(int) i] = Math.min(maxV_Every_0_5_seconds[(int) i], maxv[j]-time[j+1]+(i/2));
				}
				if(i >= 2*time[j] && i <= 2*time[j+1]) {
					maxV_Every_0_5_seconds[(int) i] = Math.min(maxV_Every_0_5_seconds[(int) i], maxv[j]);
				}
			}
		}
//		System.out.println(Arrays.toString(maxV_Every_0_5_seconds));
		double ans = 0;
		for(int i = 0; i < totalTime*2; i++) {
			ans += 0.25 * (maxV_Every_0_5_seconds[i]+maxV_Every_0_5_seconds[i+1]);
		}
		System.out.println(ans);
	}
}