//2019/3/14
import java.util.ArrayList;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		String s = sc.next();

		int max = 0;

		int a, j;

		ArrayList<Integer> c = new ArrayList<>();

		ArrayList<Integer> cc = new ArrayList<>();

		for(int i=0;i<N;i++) {

			j = 0;

			a = 0;

			while(j<=i) {

				int b = s.charAt(j);

				c.add(b);

				j++;
			}

			while(j<N) {

				int  d = s.charAt(j);

				//System.out.println((char)cc);

				if(c.contains(d) && !cc.contains(d)) {

					a++;

					cc.add(d);
				}

				j++;

			}

			if(a>max) max = a;

			c.clear();

			cc.clear();
		}

		System.out.println(max);
	}

}