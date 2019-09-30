import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		String[] sp = line.split(" ");
		int n = Integer.parseInt(sp[0]);
		line = br.readLine();
		sp = line.split(" ");
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = Long.parseLong(sp[i]);
		}

		long min = Integer.MAX_VALUE;
		long max = 0;
		int count = 0;
		for (int i = 0; i < n; i++) {
			min = Math.min(min, a[i]);
			if (a[i] - min > max) {
				max = a[i] - min;
				count = 1;
			}
			else if (a[i] - min == max) {
				max = a[i] - min;
				count++;
			}
		}
		System.out.println(count);
	}
}