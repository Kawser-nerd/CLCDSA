import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		for(;;) {
			a-=500;
			if(a<500) {
				break;
			}
				
		}
		if(a<=b) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}