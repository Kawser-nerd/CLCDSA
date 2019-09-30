import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		int n=s.nextInt(),sum=0;
		for(;n>0;n--) {
			sum+=Math.max(0, 80-s.nextInt());
		}
		System.out.println(sum);
	}
}