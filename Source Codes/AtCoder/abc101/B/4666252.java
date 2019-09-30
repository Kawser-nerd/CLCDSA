import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int sum = 0;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = n;
		int i = 100000000;
		
		while(true) {
			if(i <= m) {
				m = m - i;
				sum++;
			}else{
				if(m == 0)break;
				i = i / 10;
			}
		}
		
		if(n % sum == 0) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
		
		sc.close();
	}

}