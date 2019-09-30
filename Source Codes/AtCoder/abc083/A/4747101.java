import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int l = sc.nextInt() + sc.nextInt();
		int r = sc.nextInt() + sc.nextInt();
		if(l > r) {
			System.out.println("Left");
		}else if(l < r){
			System.out.println("Right");
		}else {
			System.out.println("Balanced");
		}
		sc.close();
	}
}