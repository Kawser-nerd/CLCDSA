import java.util.ArrayList;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// ??????
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		
		ArrayList<Integer> list = new ArrayList<Integer>();
		int max = Math.max(A, B);
		for(int i=1;i<=max;i++) {
			if(A % i == 0 && B % i ==0) {
		        list.add(new Integer(i));
			}
		}
		System.out.println(list.get(list.size()-K));
	}
}