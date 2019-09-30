import java.util.Scanner;


public class Main {
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int q = in.nextInt();
		int[] x = new int[n];
		int[] h = new int[n];
		int[] r = new int[n];
		for (int i = 0; i < n; i++){
			x[i] = in.nextInt();
			r[i] = in.nextInt();
			h[i] = in.nextInt();
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < q; i++){
			int a = in.nextInt();
			int b = in.nextInt();
			Double re = 0.0;
			for (int j = 0; j < n; j++){
				if (x[j] >= b || x[j] + h[j] <= a){
					continue;
				}
				if (x[j] >= a && x[j] + h[j] <= b){
					re += Math.PI * r[j] * r[j] * h[j] / 3;
					continue;
				}
				if (x[j] < a && x[j] + h[j] <= b) {
					Double hh = (double)(x[j] + h[j] - a);
					Double rr = hh * r[j] / h[j];
					re += Math.PI * rr * rr * hh / 3;
					continue;
				}
				if (x[j] >= a && x[j] + h[j] > b) {
					Double hh = (double)(h[j]- b + x[j]);
					Double rr = hh * r[j] / h[j];
					re += Math.PI / 3 * (r[j] * r[j] * h[j] - rr * rr * hh);
					continue;
				}
				if (x[j] < a && x[j] + h[j] > b) {
					Double h1 = (double)(h[j] - a + x[j]);
					Double r1 = h1 * r[j] / h[j];
					Double hh = (double)(x[j] + h[j] - b);
					Double rr = hh * r[j] / h[j];
					re += Math.PI / 3 * (r1 * r1 * h1 - rr * rr * hh);
					continue;
				}
			}
			sb.append(String.format("%.6f", re) + "\n");
		}
		in.close();
		System.out.println(sb.toString());
	}

}