import java.util.Scanner;
import java.util.ArrayList;;

public class Main {


	public static void main(String[] args) {
		// TODO ???????????????
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int M = sc.nextInt();
		ArrayList<int[]> data = new ArrayList<int[]>();
		
		long res = 0;
		for(int i = 0;i<N;i++) {
			int[] input = new int[2];
			input[0]=sc.nextInt();
			input[1]=sc.nextInt();
			data.add(input);
		}
		data.sort((a,b)->Integer.compare(a[0], b[0]));
		
		int i = 0;
		int count_m = 0;
		int count = 0;
		
		while(M != count_m) {
			res += data.get(i)[0];
			count++;
			count_m++;
			
			int next_i = count/data.get(i)[1];
			count = count%data.get(i)[1];
			i += next_i;
		}
		System.out.println(res);
	}
}