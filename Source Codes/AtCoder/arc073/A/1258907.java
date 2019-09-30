import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int t = scanner.nextInt();
		int total = 0;
		int now = scanner.nextInt();//0
		for(int i = 0; i < n - 1; i++){
			int next = scanner.nextInt();
			if((next - now) < t){
				total += next - now;
			} else {
				total += t;
			}
			now = next;
		}
		total += t;
		System.out.println(total);
	}
}