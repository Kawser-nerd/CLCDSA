import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = n;
		int i = 0;
		while(true) {
			i++;
			if(m <= 111) {
				System.out.println(i*111);
				break;
			}
			m-=111;
		}
		sc.close();
	}

}