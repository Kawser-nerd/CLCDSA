import java.util.Scanner;

class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();

		int x = sc.nextInt();
		int y = sc.nextInt();

		int result = 0;

		Boolean h = false;

		if (a + b > 2 * c) {
			h = true;
		} else {
			h = false;
		}

		int low = Math.min(x, y);
		int high = Math.max(x, y);

		int sub = high - low;

		if (h) {
			if(low == x) {
				if(b > 2 * c) {
					result = 2 * high * c;
				} else {
					result = 2 * low * c + sub * b;
				}

			} else if(low == y){
				if(a > 2 * c) {
					result = 2 * high * c;
				} else {
					result = 2 * low * c + sub * a;
				}
			}
		} else {
			result = a * x + b * y;
		}

		System.out.println(result);

		sc.close();

	}
}