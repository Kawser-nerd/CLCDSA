import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		// ?????
		int N = sc.nextInt();
		String c = sc.next();
		String c1 = "";
		int cnt1 = 0;
		int cnt2 = 0;
		int cnt3 = 0;
		int cnt4 = 0;

		for (int i = 0; i < N; i++) {
			c1 = c.substring(i, i + 1);

			if (c1.equals("1")) {
				cnt1++;
			} else if (c1.equals("2")) {
				cnt2++;
			} else if (c1.equals("3")) {
				cnt3++;
			} else if (c1.equals("4")) {
				cnt4++;
			}
		}

		int[] numCnt = { cnt1, cnt2, cnt3, cnt4 };

		int min = cnt1;
		int max = cnt1;

		for(int i=0;i<numCnt.length;i++) {
			max = Math.max(max, numCnt[i]);
			min = Math.min(min, numCnt[i]);
		}
		
		System.out.println(max + " " + min);

	}

}