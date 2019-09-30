import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Q2 {
	private static void run(int CASE) throws Exception {
		StringTokenizer st = new StringTokenizer(readLine());
		double totalDist = parseDouble(st.nextToken());
		int N = parseInt(st.nextToken());
		int A = parseInt(st.nextToken());
		double[] t = new double[N];
		double[] x = new double[N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(readLine());
			t[i] = parseDouble(st.nextToken());
			x[i] = parseDouble(st.nextToken());
		}
		st = new StringTokenizer(readLine());
		printf("Case #%d:\n", CASE);
		for (int a = 0; a < A; a++) {
			double accel = parseDouble(st.nextToken());
			double dist = 0;
			double time = 0;
			double vel = 0;
			for (int i = 0; i < N; i++) {
				// dist by accel
				double distByAccel = vel*t[i]+0.5*accel*t[i]*t[i];
				// dist other car
				double distOtherCar = x[i];
				
				if(dist+distOtherCar >= totalDist) {
					// last segment
					double factor = Math.sqrt(vel*vel+2*accel*(totalDist-dist));
					double finalTimeByAccel = (-vel+factor)/accel;
					if(finalTimeByAccel<0) finalTimeByAccel = (-vel-factor)/accel;
					
					// other car
					double finalTimeByOther = -1;
					if(i==0) {
						finalTimeByOther = 0;
					} else {
						finalTimeByOther = (totalDist-x[i-1])*(t[i]-t[i-1])/(x[i]-x[i-1]);
					}
					double finalTime = Math.max(finalTimeByAccel, finalTimeByOther);
					printf("%.7f\n", time+finalTime);
					break;
				}
				
				// middle segment
				if(distByAccel<=distOtherCar) {
					dist += distByAccel;
					time += t[i];
					vel += accel*t[i];

				} else {
					dist += distOtherCar;
					time += t[i];
					if(i==0) {
						vel = 0;
					} else {
						double v1 = (x[i]-x[i-1])/(t[i]-t[i-1]);
						double ti = Math.sqrt(2*accel*(x[i]-x[i-1]));
						double v2 = accel*ti;
						vel = Math.max(v1, v2);
					}
				}
			}
		}
	}

	//-- Supporting --//
	static BufferedReader in;
	static PrintWriter out;
	static {
		try {
			in = new BufferedReader(new FileReader("B-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("out.txt"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) throws Exception {
		int N = Integer.parseInt(readLine());
		for (int c = 1; c <= N; c++) {
			run(c);
		}
		in.close();
		out.close();
	}

	private static String readLine() throws IOException {
		return in.readLine();
	}

	private static void printf(String str, Object... o) {
		System.out.printf(str, o);
		out.printf(str, o);
	}

	private static double parseDouble(String t) {
		return Double.parseDouble(t);
	}
	
	private static int parseInt(String t) {
		return Integer.parseInt(t);
	}
}
