import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(f.readLine());
		int[] p = new int[n];
		StringTokenizer st = new StringTokenizer(f.readLine());
		for(int i = 0; i < n; i++) {
			p[i] = Integer.parseInt(st.nextToken()) - 1;
		}
		int counter = 0;
		for(int i = 0; i < n - 1; i++) {
			if(p[i] == i) {
				int temp = p[i + 1];
				p[i + 1] = p[i];
				p[i] = temp;
				counter++;
			}
		}
		if(p[n - 1] == n - 1) {
			counter++;
		}
		System.out.println(counter);
	}
}