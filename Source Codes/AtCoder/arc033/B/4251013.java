import java.util.*;
import java.io.*;

public class Main {
	public static void main (String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] arr = br.readLine().split(" ", 2);
		int na = Integer.parseInt(arr[0]);
		int nb = Integer.parseInt(arr[1]);
		HashSet<Integer> set = new HashSet<>();
		arr = br.readLine().split(" ", na);
		for (String s : arr) {
			set.add(Integer.parseInt(s));
		}
		int in = 0;
		int out = 0;
		arr = br.readLine().split(" ", nb);
		for (String s : arr) {
			int x = Integer.parseInt(s);
			if (set.contains(x)) {
				in++;
			} else {
				out++;
			}
		}
		System.out.println((double) in / (double)(na + out));
	}
}