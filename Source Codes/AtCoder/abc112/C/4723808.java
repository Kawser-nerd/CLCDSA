import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] x = new int[n];
		int[] y = new int[n];
		int[] h = new int[n];
		int H = 0, a = 0;
		for(int i = 0; i < n; i++) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
			h[i] = sc.nextInt();
			if(h[i] > 0) a = i;
		}
		LOOP:for(int i = 0; i <= 100; i++) {
			for(int j = 0; j <= 100; j++) {
				boolean isok = true;
				H = h[a] + Math.abs(x[a]-i) + Math.abs(y[a]-j);
				for(int k = 0; k < n; k++) {
					if(h[k] != Math.max(H - Math.abs(x[k]-i) - Math.abs(y[k]-j), 0)) {
							isok = false;
							break;
					}
				}
				if(isok) {
					System.out.println(i + " " + j + " " + H);
					break LOOP;
				}
			}
		}
	}

}