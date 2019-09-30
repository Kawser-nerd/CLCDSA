import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
	    int N = sc.nextInt();
	    if(N%4 != 0)
			System.out.println("NO");
		else if(N%100 == 0 && N%400 != 0)
			System.out.println("NO");
		else if(N%100 == 0 && N%400 == 0)
			System.out.println("YES");
		else
			System.out.println("YES");
	    sc.close();
	}
}