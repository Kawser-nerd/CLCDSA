import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int value = N;
		int sum=0;
		for(int i=0;i<9;i++){
			sum +=  (value % 10);
			value /= 10;
			if(value == 0)break;
		}
		if(N%sum == 0) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}