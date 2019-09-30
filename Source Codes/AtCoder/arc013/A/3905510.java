import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		int L = scanner.nextInt();
		int P = scanner.nextInt();
		int Q = scanner.nextInt();
		int R = scanner.nextInt();

		int[] volume = new int[6];
		volume[0] = (N/P) * (M/Q) * (L/R);
		volume[1] = (N/P) * (M/Q) * (L/R);
		volume[2] = (M/P) * (N/Q) * (L/R);
		volume[3] = (M/P) * (L/Q) * (N/R);
		volume[4] = (L/P) * (M/Q) * (N/R);
		volume[5] = (L/P) * (N/Q) * (M/R);
		int max = Integer.MIN_VALUE;
		for(int i = 0; i < 6; i++){
			if(volume[i]>max){
				max = volume[i];
 			}
		}
		System.out.println(max);
  }
}