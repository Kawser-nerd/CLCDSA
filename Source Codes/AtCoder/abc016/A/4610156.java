import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int month = sc.nextInt();
		int day = sc.nextInt();
		if (month % day == 0){
			System.out.println("YES");
		}else{
			System.out.println("NO");
		}
	}
}