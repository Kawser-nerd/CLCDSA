import java.util.*;
import java.io.*;

public class Main {
	public static void main (String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] arr = br.readLine().split(" ", 2);
		int n = Integer.parseInt(arr[0]);
		int k = Integer.parseInt(arr[1]);
		int prev = 0;
		int count = 0;
		int sum = 0;
		ArrayList<Integer> list = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int a = Integer.parseInt(br.readLine());
			if (i == 0) {
				count = 1;
			} else if (prev >= a) {
				count = 1;
			} else {
				count++;
			}
			if (count >= k) {
				sum++;
			}
			prev = a;
		}
		System.out.println(sum);
	}
}