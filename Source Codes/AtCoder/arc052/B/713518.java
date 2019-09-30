import java.util.Scanner;

class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		int N = in.nextInt();
		int Q = in.nextInt();
		int[] x = new int[N];
		int[] r = new int[N];
		int[] h = new int[N];
		int[] A = new int[Q];
		int[] B = new int[Q];

		for (int i = 0; i < N; i++) {
			String dummy = in.nextLine();
			x[i] = in.nextInt();
			r[i] = in.nextInt();
			h[i] = in.nextInt();
		}
		for (int i = 0; i < Q; i++) {
			String dummy = in.nextLine();
			A[i] = in.nextInt();
			B[i] = in.nextInt();
		}
		double[] v = new double[N];
		double[] htmp = new double[N];
		double[] vtmp = new double[N];
		double output;

		for (int i = 0; i < N; i++) {
			v[i] = Math.PI * h[i] * r[i] * r[i] / 3;
		}

		for (int j = 0; j < Q; j++) {

			for (int i = 0; i < N; i++) {
				vtmp[i] = v[i];
			}

			for (int i = 0; i < N; i++) {
				if (x[i] > B[j]) {// ??iii--
					vtmp[i] = 0;
				} else if (x[i] < A[j]) {// ??i--
					htmp[i] = h[i] - A[j] + x[i];
					if (x[i] + h[i] < A[j]) {// ??iI
						vtmp[i] = 0;
					} else {// ??iII
						vtmp[i] = v[i] * Math.pow(htmp[i] / h[i], 3);
						if (x[i] + h[i] > B[j]) {// ??iIII
							htmp[i] = h[i] - B[j] + x[i];
							vtmp[i] = vtmp[i] - (v[i] * Math.pow(htmp[i] / h[i], 3));
						}
					}
				} else {// ??ii--
					// ?????
					if (x[i] + h[i] > B[j]) {// ??iiIII
						htmp[i] = h[i] - B[j] + x[i];
						vtmp[i] = v[i] -( v[i] * Math.pow(htmp[i] / h[i], 3));

					}
				}

			}
			output = 0;
			for (int i = 0; i < N; i++) {
				output += vtmp[i];
			}

			System.out.println(output);

		}

		in.close();

	}

}