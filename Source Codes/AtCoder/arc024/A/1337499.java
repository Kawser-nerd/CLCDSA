import java.util.Scanner;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		
		int l_n = scan.nextInt();
		int r_n = scan.nextInt();
		int[] l_sizes = new int[l_n];
		int[] r_sizes = new int[r_n];
		
		//System.out.println(l_n);
		//System.out.println(r_n);
		
		for(int i = 0; i < l_n; i++) {
			l_sizes[i]  = scan.nextInt();
		}
		
		for (int i = 0; i < r_n; i++) {
			r_sizes[i] = scan.nextInt();
		}

		Arrays.sort(l_sizes);
		Arrays.sort(r_sizes);
		
		/*
		for(int i = 0; i < l_n; i++) {
			System.out.println(l_sizes[i]);
		}
		
		for (int i = 0; i < r_n; i++) {
			System.out.println(r_sizes[i]);
		}
		*/
		
		
		int l_index = 0;
		int r_index = 0;
		int ans = 0;
		
		while (l_index < l_n && r_index < r_n) {
			if (l_sizes[l_index] == r_sizes[r_index]) {
				ans++;
				l_index++;
				r_index++;
			} else if (l_sizes[l_index] > r_sizes[r_index]) {
				r_index++;
			} else {
				l_index++;
			}
		}
		
		System.out.println(ans);
		
		return;
	}
}