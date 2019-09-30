import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int X = sc.nextInt();
		int A = sc.nextInt() * -1;
		int B = sc.nextInt();
		if(A + B > X) {
			System.out.println("dangerous");
		} else if(A + B > 0){
			System.out.println("safe");
		} else {
			System.out.println("delicious");
		}
	}
}