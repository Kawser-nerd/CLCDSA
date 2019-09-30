//2019/3/14
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int H = sc.nextInt();

		int W = sc.nextInt();

		char[][] a = new char[H][W];

		ArrayList<Integer> h = new ArrayList<>();

		ArrayList<Integer> w = new ArrayList<>();

		boolean flag = false;


		//?????????
		for(int i=0;i<H;i++) {

			String s = sc.next();

			flag = false;

			for(int j=0;j<W;j++) {

				a[i][j] = s.charAt(j);

				if(a[i][j] == '#') flag = true;
			}

			if(!flag) h.add(i);
		}

		//?
		for(int j=0;j<W;j++) {

			flag = false;

			for(int i=0;i<H;i++) {

				if(a[i][j] == '#') flag = true;
			}

			if(!flag) w.add(j);
		}

		//?? flag????...
		for(int i=0;i<H;i++) {

			flag = false;

			for(int j=0;j<W;j++) {

				if(!h.contains(i) && !w.contains(j)) {

					System.out.print(a[i][j]);

					flag = true;
				}
			}
			if(flag)System.out.println();
		}

	}
}