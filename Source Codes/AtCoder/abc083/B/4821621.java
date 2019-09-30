import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		try(Scanner scan = new Scanner(System.in);){
			int N = Integer.parseInt(scan.next());
			int a = Integer.parseInt(scan.next());
			int b = Integer.parseInt(scan.next());
			int sum = 0;
			for(int i=0; i<=N; i++) {
				int tmpSum = 0;
				int num = i;
				while(num != 0) {
					tmpSum += num %10;
					num /= 10;
				}
				if(tmpSum >= a && tmpSum <= b) {
					sum += i;
				}
			}
          System.out.println(sum);
		}
	}
}