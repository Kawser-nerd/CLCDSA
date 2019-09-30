import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N;
		int Z;
		N = scanner.nextInt();
		Z = N;
		int ans = 0;
		while(N > 0){
			ans += N % 10;
			N /= 10;
		}
		if (Z % ans == 0){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}
	}
}