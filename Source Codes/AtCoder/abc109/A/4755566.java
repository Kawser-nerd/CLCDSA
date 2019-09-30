import java.util.*;
public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt(), B = sc.nextInt();
		int x = A * B;
		if(x%2 != 0)System.out.println("Yes");
		else if((x*3)%2 != 0)System.out.println("Yes");
		else System.out.println("No");
	}

}