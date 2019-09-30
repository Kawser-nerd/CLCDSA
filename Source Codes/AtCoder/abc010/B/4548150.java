import java.util.Scanner;

class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int flowern = sc.nextInt();
		int count = 0;
		for (int i = 0; i < flowern; i++) {
			int flower = sc.nextInt();
			if (flower % 2 == 0) {

				if (flower == 6) {
					count += 3;
				} else {
					count++;
				}
			}else if (flower == 5) {
				count += 2;
			} 

		}
		System.out.println(count);
	}
}