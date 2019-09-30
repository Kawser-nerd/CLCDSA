import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] ary = new int[sc.nextInt()];
		int count = sc.nextInt();
		for(int i = 0; i < count; i++) {

			int f = sc.nextInt();
			int l = sc.nextInt();
			int num = sc.nextInt();

			for (int e = 0; e < ary.length; e++) {
				if(f <= (e+1) && l > e) ary[e] = num;
			}
		}

		for (int i : ary) {
			System.out.println(i);
		}
	}
}