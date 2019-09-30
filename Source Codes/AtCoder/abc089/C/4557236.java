import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt();
		long[] num = new long[5];
		scn.nextLine();
		for (int i = 0; i < N; i++) {
			char[] buf = scn.nextLine().toCharArray();
			switch (buf[0]) {
			case 'M':
				num[0]++;
				break;
			case 'A':
				num[1]++;
				break;
			case 'R':
				num[2]++;
				break;
			case 'C':
				num[3]++;
				break;
			case 'H':
				num[4]++;
				break;
			default:
				break;
			}
		}
		long ans = 0;
		for(int i = 0;i < 3;i++) {
			for(int j = i+1;j < 4;j++) {
				for(int k = j+1;k < 5;k++) {
					ans += num[i] * num[j] * num[k];
				}
			}
		}
		System.out.println(ans);
	}

}