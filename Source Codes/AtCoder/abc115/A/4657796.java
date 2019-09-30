import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int D = sc.nextInt();
		System.out.print("Christmas");
		while(D < 25) {
			System.out.print(" Eve");
			D++;
		}
		System.out.println();
	}
}