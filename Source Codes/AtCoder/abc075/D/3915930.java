import java.util.*;

public class Main {
	static long[] arrX;
	static long[] arrY;
	static int n;
	static int k;

	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k = sc.nextInt();
		arrX = new long[n];
		arrY = new long[n];
		for (int i = 0; i < n; i++) {
			arrX[i] = sc.nextLong();
			arrY[i] = sc.nextLong();
		}
		long min = Long.MAX_VALUE;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = 0; k < n - 1; k++) {
					for (int l = k + 1; l < n; l++) {
						long sqr = Math.abs(arrX[i] - arrX[j]) * Math.abs(arrY[k] - arrY[l]);
						if (sqr > min) {
							continue;
						}
						if (isOver(Math.min(arrX[i], arrX[j]), Math.max(arrX[i], arrX[j]), Math.min(arrY[k], arrY[l]), Math.max(arrY[k], arrY[l]))) {
							min = sqr;
						}
					}
				}
			}
		}
		System.out.println(min);
	}
	
	static boolean isOver(long x1, long x2, long y1, long y2) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (arrX[i] >= x1 && arrX[i] <= x2 && arrY[i] >= y1 && arrY[i] <= y2) {
				count++;
			}
		}
		return (count >= k);
	}
	
}