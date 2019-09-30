import java.util.Arrays;
import java.util.Scanner;


public class Main {
	static int N,K;
	static int[] trees;
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		 N = sc.nextInt();
		 K = sc.nextInt();
		 trees = new int[N];

		 for(int i = 0 ; i < N ; i++){
			 trees[i] = sc.nextInt();
			 }
		 sc.close();

		 Arrays.sort(trees);

		 int current = trees[K-1] - trees[0];
		 int height = 0 ;
		 for(int i = 1 ; i < N-K+1 ; i++){
			 height = trees[i+K-1]-trees[i];
			 
			 if(current > height){
				 current = height;
			 }
			 
		 }
	System.out.println(current);
	}
}