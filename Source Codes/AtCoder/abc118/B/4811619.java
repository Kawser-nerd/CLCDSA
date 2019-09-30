import java.util.Scanner;


public class Main {
	static int N,M,K;
	static int[] foods;
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		 N = sc.nextInt();
		 M = sc.nextInt();
		 foods = new int[M];

		 for(int i = 0 ; i < N ; i++){
			 K = sc.nextInt();

			 for(int j = 0 ; j < K ; j++){
				 foods[sc.nextInt()-1] += 1;
			 }
		 }

		sc.close();

		int ans = 0 ;
		for(int k = 0 ; k < M ; k++){
			if(foods[k] == N){
				ans += 1;
			}
		}
		System.out.println(ans);
	}
}