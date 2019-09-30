import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int nokori = a;
		nokori -= b;
		boolean kaeru = true;
		while(kaeru == true) {
			if(nokori>=c) {
				nokori -= c;
			}else {
				kaeru = false;
			}
		}
		System.out.println(nokori);
	}

}