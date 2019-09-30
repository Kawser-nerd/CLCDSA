import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int m = sc.nextInt();
		int n = sc.nextInt();
		int N = sc.nextInt();

		int sum = N;
		int temp;
		int pen = 0;

		while(true){

			temp = N / m * n;

			pen = N % m;

			N = temp + pen;

			sum += temp;

			if(N < m){
				break;
			}
		}

		System.out.println(sum);
	}
}