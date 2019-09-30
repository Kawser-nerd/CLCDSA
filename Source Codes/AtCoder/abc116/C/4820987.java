import java.util.Scanner;


public class Main {
	static int N;
	static int[] flowers;
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		 N = sc.nextInt();
		 flowers = new int[N];

		 for(int i = 0 ; i < N ; i++){
			 flowers[i] = sc.nextInt();
			 }
		 sc.close();

		 int ans = 0;
		 int cur = 0;

			 for(int k = 0 ; k < N ; k++){
				if(flowers[k]>cur){
					ans += flowers[k] - cur;
				 }
			cur = flowers[k];
			 }
		 System.out.println(ans);


	}
}