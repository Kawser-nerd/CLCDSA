import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int x = sc.nextInt();
		int sum = 0;
		for(int i = 0; i <= a; i++) {
			for(int j = 0; j <= b; j++) {
				for(int k = 0; k <= c; k++) {
					int way = i*500 + j*100 + k*50;
					if(way == x) sum++;
				}
			}
		}
		System.out.println(sum);
		sc.close();
	}
}