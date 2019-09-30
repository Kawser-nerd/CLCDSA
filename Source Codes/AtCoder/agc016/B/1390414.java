import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Main main = new Main();
		main.solveB();
	}

	private void solveB() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int minK = N;
		int minKnum = 0;
		int maxK = 0;
		int maxKnum = 0;
		for (int i = 0; i < N; i++) {
			int num = sc.nextInt();
			if (minK > num) {
				minK = num;
				minKnum = 0;
			}
			if (maxK < num) {
				maxK = num;
				maxKnum = 0;
			}
			if (minK == num) {
				minKnum++;
			}
			if (maxK == num) {
				maxKnum++;
			}
		}
		if (judge(minK, minKnum, maxK, maxKnum)) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}

	private boolean judge(int minK, int minKnum, int maxK, int maxKnum) {
		if (minK + 1 < maxK) {
			return false;
		}
		if (minK == maxK) {
			if (minK + 1 == minKnum) {
				return true;
			}
			return minK <= minKnum / 2;
		}
		if (maxKnum < 2) {
			return false;
		}
		return (minKnum < maxK) && (maxK <= minKnum + maxKnum / 2);
	}
}