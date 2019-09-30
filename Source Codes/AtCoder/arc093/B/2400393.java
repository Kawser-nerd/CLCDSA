import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();

		System.out.println("100 100");
		for (int i=0;i<50;i++) {
			String str = "";;
			for (int j=0;j<100;j++) {
				if (a>1 && i%2==0 && j%2==0) {
					str = str+".";
					a--;
				} else {
					str = str+"#";
				}
			}
			System.out.println(str);
		}
		for (int i=0;i<50;i++) {
			String str = "";;
			for (int j=0;j<100;j++) {
				if (b>1 && i%2==1 && j%2==1) {
					str = str+"#";
					b--;
				} else {
					str = str+".";
				}
			}
			System.out.println(str);
		}
	}

}