import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int count = 0;
		while(a>=3){
			a -= 3;
			count++;
		}
		System.out.println(count);
	}

}