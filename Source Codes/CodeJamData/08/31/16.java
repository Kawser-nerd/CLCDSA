import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Gcj1 {

	/**
	 * @param args
	 */

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader In = new BufferedReader(new FileReader(new File("c:\\in.txt")));
		BufferedWriter Out = new BufferedWriter(new FileWriter(new File("c:\\out")));
		int N = Integer.parseInt(In.readLine());
		for (int num = 1; num <= N; num++) {
			Scanner sc = new Scanner(In.readLine());
			int P = sc.nextInt();
			int K = sc.nextInt();
			int L = sc.nextInt();
			int[] data = new int[L];
			sc = new Scanner(In.readLine());
			for (int i = 0; i < L; i++) {
				data[i] = sc.nextInt();
			}
			Arrays.sort(data);
			int count = 0;
			int step = 1;
			long res = 0;
			for (int i = L - 1; i >= 0; i--) {
				if (count == K) {
					count = 0;
					step++;
				}
				res += (long)data[i] * step;
				count++;
			}
			Out.write("Case #" + num + ": " + res + "\n");
		}
		Out.flush();
	}
}
