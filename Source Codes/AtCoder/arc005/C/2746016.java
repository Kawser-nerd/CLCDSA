import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}

	static int H;
	static int W;

	void run() {
		Scanner sc = new Scanner(System.in);

		H = sc.nextInt();
		W = sc.nextInt();

		String[][] field = new String[H][W];

		for (int i = 0; i < H; i++) {
			field[i] = sc.next().split("");
		}

		//??????????

		int fx=-1;
		int fy=-1;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {

				if (field[i][j].equals("s")) {
					fy=i;
					fx=j;
				}

			}
		}

		//?????????
		Queue<Integer> nowq=new LinkedList<Integer>();

		nowq.add(encode(fy,fx));

		//??4???????????
		int[] dy= {1,0,-1,0};
		int[] dx= {0,1,0,-1};

		boolean[][] isReached=new boolean[H][W];
		isReached[fy][fx]=true;

		//???????????1??
		//???????????????2??
		//?????????????????3??

		for (int i = 0; i < 3; i++) {

			Queue<Integer> nextq=new LinkedList<Integer>();

			while(!nowq.isEmpty()) {
				int now=nowq.poll();

				int y=now/1000;
				int x=now%1000;

				for (int j = 0; j < 4; j++) {
					int ny=y+dy[j];
					int nx=x+dx[j];

					if(!isIn(ny, nx)) {
						continue;
					}

					if(isReached[ny][nx]) {
						continue;
					}

					isReached[ny][nx]=true;

					if(field[ny][nx].equals("g")) {
						pln("YES");
						return;
					}else if(field[ny][nx].equals("#")) {
						nextq.add(encode(ny,nx));
					}else {
						nowq.add(encode(ny,nx));
					}

				}
			}

			nowq=nextq;
		}

		pln("NO");
		return;

	}

	int encode(int y,int x) {
		return y*1000+x;
	}

	boolean isIn(int y,int x) {
		return y>=0 && y<H && x>=0 && x<W;
	}

	//????????


	static <T> void output(List<T> list) {

		for (int i = 0; i < list.size(); i++) {
			System.out.print(list.get(i));

			if (i != list.size() - 1) {
				System.out.print(" ");
			} else {
				nl();
			}
		}

	}

	static void output(String[][] str) {

		for (int i = 0; i < str.length; i++) {
			for (int j = 0; j < str[i].length; j++) {
				print(str[i][j]);
			}

			nl();
		}

	}

	static void output(boolean flg, String Yes, String No) {

		if (flg) {
			pln(Yes);
		} else {
			pln(No);
		}

	}

	static void output(String[][] str, int digit) {

		String dig = "%" + String.valueOf(digit) + "s";

		for (int i = 0; i < str.length; i++) {
			for (int j = 0; j < str[i].length; j++) {
				System.out.printf(dig, str[i][j]);
			}
			nl();
		}

	}

	static void output(int[] x) {

		for (int i = 0; i < x.length; i++) {

			print(x[i]);

			if (i != x.length - 1) {
				print(" ");
			} else {

				nl();
			}
		}

	}

	static void pln(String str) {
		System.out.println(str);
	}

	static void pln(int x) {
		System.out.println(x);
	}

	static void print(String str) {
		System.out.print(str);
	}

	static void print(int x) {
		System.out.print(x);
	}

	static void print(String str, int times) {
		for (int i = 0; i < times; i++) {
			print(str);
		}
	}

	static void print(int x, int times) {
		for (int i = 0; i < times; i++) {
			print(x);
		}
	}

	static void nl() {
		System.out.println();
	}

}