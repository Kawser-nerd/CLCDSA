//2019/3/14
import java.util.ArrayList;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int s = sc.nextInt();

		int n = 1;

		int Fn = s;

		ArrayList<Integer> array = new ArrayList<>();

		array.add(s);

		while(true) {

			if(Fn%2==0) Fn /= 2;

			else Fn = 3*Fn+1;

			if(array.contains(Fn)) {

				System.out.println(n+1);

				break;
			}

			array.add(Fn);

			n++;
		}
	}

}