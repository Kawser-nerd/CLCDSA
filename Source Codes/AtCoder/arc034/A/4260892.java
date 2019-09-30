import java.util.*;
import java.io.*;

public class Main {
	public static void main (String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		double max = 0;
		for (int i = 0; i < n; i++) {
			String[] arr = br.readLine().split(" ", 5);
			double sum = 0;
			for (int j = 0; j < 5; j++) {
				int x = Integer.parseInt(arr[j]);
				if (j < 4) {
					sum += x;
				} else {
					sum += (double)x * (110.0 / 900.0);
				}
			}
			if (max < sum) {
				max = sum;
			}
		}
		System.out.println(max);
	}
}