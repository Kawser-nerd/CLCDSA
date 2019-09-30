import java.util.Scanner;
public class Main{

	int N;
	int A;
	int B;
	int C;
	int imihu;
	int [] list;

	public static void main (String[] args) {

		Main main = new Main();
		main.solve();
	}

	private void solve() {

		Scanner sc = new Scanner (System.in);

		N = sc.nextInt();
		A = sc.nextInt();
		B = sc.nextInt();
		C = sc.nextInt();

		 list = new int [N];

		for (int index=0; index<N; index++) {
			list[index]=sc.nextInt();
		}

		imihu = (int) Math.pow(10, 9);

		int answer = calculate (0,0,0,0);

		System.out.println(answer);
	}

	private int calculate (int nowTake, int aTake, int bTake, int cTake) {

		if (nowTake==N) {
			int min = aTake;
			if (min>bTake) {
				min=bTake;
			}
			if (min>cTake) {
				min=cTake;
			}
			if (min>0) {
				return Math.abs(A-aTake)+Math.abs(B-bTake)+Math.abs(C-cTake)-30;
			} else {
				return imihu;
			}
		}
		int first = calculate (nowTake+1, aTake, bTake, cTake);
		int second = calculate (nowTake+1,aTake+list[nowTake],bTake,cTake)+10;
		int third = calculate (nowTake+1,aTake,bTake+list[nowTake],cTake)+10;
		int fourth = calculate (nowTake+1,aTake,bTake,cTake+list[nowTake])+10;

		int min=first;
		if (min>second) {
			min=second;
		}
		if (min>third) {
			min=third;
		}
		if (min>fourth) {
			min=fourth;
		}
		return min;
	}
}