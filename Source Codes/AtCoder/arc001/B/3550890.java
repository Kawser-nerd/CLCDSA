import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		// ?????
		int N = sc.nextInt();
		String c = sc.next();
		String c1="";
		int cnt1 = 0;
		int cnt2 = 0;
		int cnt3 = 0;
		int cnt4 = 0;

		for (int i = 0; i < N; i++) {
			c1= c.substring(i, i+1);

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
		int min = cnt1;
		int max = cnt1;
		
		if(min>cnt2) {
			min=cnt2;
		}
		if(min>cnt3) {
			min=cnt3;
		}
		if(min>cnt4) {
			min=cnt4;
		}
		
		if(max<cnt2) {
			max=cnt2;
		}
		if(max<cnt3) {
			max=cnt3;
		}
		if(max<cnt4) {
			max=cnt4;
		}
		
		System.out.println(max+" "+min);

	}
	
	
}