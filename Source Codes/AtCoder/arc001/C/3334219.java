import java.util.*;
public class Main {
	public static void main(String[] args){


		Scanner sc = new Scanner(System.in);

		//????
		int befor = sc.nextInt();
		int after = sc.nextInt();

		//????
		int tmp;
		if (after > befor) {
			tmp = after - befor;
		} else {
			tmp = befor - after;
		}

		//??
		int count = 0;
		while (tmp != 0) {

			if (tmp >= 10) {
				tmp -= 10;
				count++;

			} else if (tmp == 9 || tmp == 6 || tmp == 4 || tmp == 2) {
				count += 2;
				break;
			} else if (tmp == 8 || tmp == 7 || tmp == 3) {
				count += 3;
				break;
			} else if (tmp == 5 || tmp == 1) {
				count++;
				break;
			}
		}
		System.out.println(count);
	}
}