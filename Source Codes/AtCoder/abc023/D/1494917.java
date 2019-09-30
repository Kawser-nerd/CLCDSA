import java.util.Arrays;
import java.util.Scanner;

/**
 * http://abc023.contest.atcoder.jp/tasks/abc023_d
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		Target[] t = new Target[N];
		for(int i=0; i<N; i++) t[i] = new Target(sc.nextLong(),sc.nextLong());
		sc.close();
		
		long ans=0;
		long left = 1;
		long right = 2 * (long)Math.pow(10, 14);
		while(left<right){
			long mid = (left+right)/2;
			long[] time = new long[N];
			boolean can = true;
			for(int i=0; i<N; i++){
				if(mid - t[i].h < 0) {
					can = false;
					break;
				}
				time[i] = (mid - t[i].h)/t[i].s;
			}
			if(can){
				Arrays.sort(time);
				for(int i=0; i<N; i++){
					if(time[i]<i){
						can = false;
						break;
					}
				}
			}
			
			if(can){
				ans = mid;
				right = mid;
			}else{
				left = mid+1;	
			}
		}
		
		System.out.println(ans);

	}
	
	static class Target{
		long h;
		long s;
		Target(long h, long s){
			this.h = h;
			this.s = s;
		}
	}

}