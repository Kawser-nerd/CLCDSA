import java.util.Scanner;

public class iCode2012OutofGas {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int index = 1; index <= T; index++) {
			System.out.println("Case #" + index + ":");
			double D = in.nextDouble();
			int N = in.nextInt();
			int A = in.nextInt();
			double[] time = new double[N+1];
			double[] pos = new double[N+1];
			for (int i = 1; i <= N; i++) {
				time[i] = in.nextDouble();
				pos[i] = in.nextDouble();
			}
			for (int acc = 0; acc < A; acc++) {
				double a = in.nextDouble();
				//if (N == 1)
					//System.out.println(Math.sqrt(2*D/a));
				double startmovingat = 0;
				for (int i = 1; i < N; i++) {
					startmovingat = Math.max(startmovingat,
							time[i] - Math.sqrt(2*pos[i]/a));
				}
				double effectivetime = time[N-1] +
						(time[N] - time[N-1])/(pos[N] - pos[N-1])
						* (D - pos[N-1]);
				startmovingat = Math.max(startmovingat,
						effectivetime - Math.sqrt(2*D/a));
				System.out.println(Math.max(effectivetime,
						startmovingat + Math.sqrt(2*D/a)));
			}
		}
	}

}
/*
1
1000.000000 2 3
0.000000 20.500000
50.000000 1979.500000
1.00 5.00 9.81
50.000000 2 2
0.000000 0.000000
100000.000000 100.000000
1.00 1.01
10000.000000 3 1
0.000000 0.000000
10000.000000 0.100000
10000.100000 100000.000000
1.00
*/