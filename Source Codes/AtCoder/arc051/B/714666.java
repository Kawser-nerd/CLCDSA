import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
	static BufferedReader br;

	static final double PHI = (1 + Math.sqrt(5)) / 2;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		int k = Integer.parseInt(br.readLine());
		System.out.println((int) (pow(k) / Math.sqrt(5) + 0.5) + " "
				+ (int) (PHI * pow(k) / Math.sqrt(5) + 0.5));
	}

	private static double pow(int k) {
		double d = 0.0;
		if (k == 0)
			return 1;
		if (k % 2 == 0) {
			d = pow(k / 2);
			return d * d;
		}
		d = pow(k / 2);
		return PHI * d * d;
	}
}