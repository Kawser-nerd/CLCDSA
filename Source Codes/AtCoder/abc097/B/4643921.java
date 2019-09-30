import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int X = sc.nextInt();
		sc.close();
		int[] Array = new int[1000];
		Arrays.fill(Array,0);
		int max = 1;
		if(X <= 3) {
			System.out.println(1);
		}
		else {
			for (int i = 2; i <= X; i++) {
				int num = i * i;
				while (num <= X) {
					max = Math.max(max, num);
					num *= i;
				}
			}
			System.out.println(max);
		}	
	}
}