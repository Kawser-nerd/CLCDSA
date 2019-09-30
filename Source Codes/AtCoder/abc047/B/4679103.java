import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws Exception {

		// --- input ---
		int[] L1 = getNums(in.readLine().split(" "));
		int[][] data = getData(L1[2]);
		in.close();

		// --- resolv ---
		int white_w_start = 0;
		int white_h_start = 0;
		int white_w_end = L1[0];
		int white_h_end = L1[1];

		for(int[] d : data) {
			if(d[2] == 1) {
				if(white_w_start < d[0])white_w_start = d[0];
			} else if(d[2] == 2) {
				if(white_w_end > d[0])white_w_end = d[0];
			} else if(d[2] == 3) {
				if(white_h_start < d[1])white_h_start = d[1];
			} else if(d[2] == 4) {
				if(white_h_end > d[1])white_h_end = d[1];
			}
		}

		if( (white_w_end - white_w_start < 0) || (white_h_end - white_h_start) < 0) {
			System.out.println(0);
		} else {
			System.out.println((white_w_end - white_w_start) * (white_h_end - white_h_start));
		}
	}

	public static int[][] getData(int num) throws Exception{

		int[][] data = new int[num][];
		for(int i=0; i < num; i++) {
			data[i] = getNums(in.readLine().split(" "));
		}
		return data;
	}

	public static int[] getNums(String[] vals) {
		int[] vAry = new int[vals.length];
		for(int i=0; i < vals.length; i++) {
			vAry[i] = Integer.parseInt(vals[i]);
		}
		return vAry;
	}
}