import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		String str = sc.next();
		String[] s = str.split("");
		int[] ans = new int[n];
		int count1 = 0;
		int count2 = 0;
		int count3 = 0;
		int count4 = 0;

		for(int i=0; i<n; i++) {
			ans[i] = Integer.parseInt(s[i]);
			if(ans[i] == 1) {
				count1++;
			}else if(ans[i] ==2) {
				count2++;
			}else if(ans[i] == 3) {
				count3++;
			}else if(ans[i] == 4) {
				count4++;
			}
		}

		int max = count1;
		int min = count1;
		for(int j=0; j<4; j++) {
			if(max<count2) {
				max = count2;
			}
			if(max<count3) {
				max = count3;
			}
			if(max<count4) {
				max = count4;
			}
			if(min>count2) {
				min = count2;
			}
			if(min>count2) {
				min = count3;
			}
			if(min>count3) {
				min = count3;
			}
			if(min>count4) {
				min = count4;
			}
		}
		System.out.println(max+" "+min);
	}

}