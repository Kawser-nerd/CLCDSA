import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();

		sc.close();

		int[] yaku = new int[15];
		int l = 1 ;

		for(int i = 100 ; i > 0 ; i--){
			if(A % i == 0 && B % i == 0){
				yaku[l] = i;
				l += 1;
			}
		}

		/*
		for(int j = 0 ; j < 15 ; j++){
			System.out.println(yaku[j]);
		}
*/
		System.out.println(yaku[K]);

	}

}