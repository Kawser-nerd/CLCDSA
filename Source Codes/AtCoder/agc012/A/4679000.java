import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws Exception {

		// --- input ---
		int num = Integer.parseInt(in.readLine());
		long[] vals = getNums(in.readLine().split(" "), num*3);
		in.close();

		Arrays.parallelSort(vals);
		long sum = 0;
		for(int i=num; i < num*3; i+=2) {
			sum+=vals[i];
		}

		// --- resolv ---
		System.out.println(sum);
	}
	public static long[] getNums(String[] vals, int num) {
		long[] vAry = new long[num];
		for(int i=0; i < num; i++) {
			vAry[i] = Integer.parseInt(vals[i]);
		}
		return vAry;
	}
}