import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		double R = sc.nextDouble();
		double G = sc.nextDouble();
		System.out.println((int)(G + (G - R)));
	}
}