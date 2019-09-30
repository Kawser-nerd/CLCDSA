import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in) ;

	int n = sc.nextInt();
	int m = sc.nextInt();

	int[][] st = new int[n][2];
	for (int i = 0; i < st.length; i++) {
		st[i][0] = sc.nextInt();
		st[i][1] = sc.nextInt();
	}

	int[][] ch = new int[m][2];
	for (int i = 0; i < ch.length; i++) {
		ch[i][0] = sc.nextInt();
		ch[i][1] = sc.nextInt();
	}

	for (int i = 0; i < st.length; i++) {
		int min = -1;
		int dis = 400_000_000;
		for (int j = 0; j < ch.length; j++) {
			int tmp = Math.abs(st[i][0] - ch[j][0]) + Math.abs(st[i][1] - ch[j][1]);
			if (dis > tmp) {
				min = j;
				dis = tmp;
			}
		}
		System.out.println(min + 1);
	}


	sc.close();
	}

}