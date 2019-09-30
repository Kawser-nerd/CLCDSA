import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int K = scanner.nextInt();
		long[] x = new long[N];
		long[] y = new long[N];
		long[] xx = new long[N];
		long[] yy = new long[N];
		for(int i = 0; i < N; i++){
			x[i] = scanner.nextLong();
			y[i] = scanner.nextLong();
			xx[i] = x[i];
			yy[i] = y[i];
		}
		Arrays.sort(xx);
		Arrays.sort(yy);
		long ans = Long.MAX_VALUE;;
		for(int x1 = 0; x1 < N; x1++){
			for(int x2 = x1 + 1; x2 < N; x2++){
				for(int y1 = 0; y1 < N; y1++){
					for(int y2 = y1 + 1; y2 < N; y2++){
						int count = 0;
						long lx = xx[x1];
						long rx = xx[x2];
						long by = yy[y1];
						long ty = yy[y2];
						for(int i = 0; i < N; i++){
							if(x[i] >= lx && x[i] <= rx && y[i] >= by && y[i] <= ty){
								count++;
							}
						}
						if(count >= K){
							ans = Math.min(ans, (rx-lx) * (ty-by));
						}
					}
				}
			}
		}
		System.out.println(ans);
  }
}