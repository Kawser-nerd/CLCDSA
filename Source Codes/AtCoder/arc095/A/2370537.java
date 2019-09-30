import static java.lang.System.*;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(in);
		
		int n = sc.nextInt();
		int[] num = new int[n];
		int[] num_org = new int[n];
		
		for(int i=0; i<n; i++) num[i] = num_org[i] = sc.nextInt();
		Arrays.sort(num);
		
		int mid_s = num[n/2-1];
		int mid_l = num[n/2];
		for(int i: num_org) {
			if(i <= mid_s) out.println(mid_l);
			else out.println(mid_s);
		}
		
		return;
	}

}