import java.util.ArrayList;
import java.util.Scanner;

public class Main{
	static ArrayList<Integer>[] list;
	static int a,b,N,M;
	static int sum = 0;
	static long[][] keiro;
	static ArrayList<Integer> que = new ArrayList<Integer>();

	public static void main(String[] args) {
		scan();
		que.add(a);


		while(!que.isEmpty()) {
			ArrayList<Integer> temp = list[que.get(0)];
			for(int i = 0;i < temp.size();i++) {

				if(keiro[temp.get(i)][0] > keiro[que.get(0)][0] + 1) {
					keiro[temp.get(i)][0] = keiro[que.get(0)][0] + 1;
					keiro[temp.get(i)][1] += keiro[que.get(0)][1] % 1000000007;
					que.add(temp.get(i));
				}
				else if(keiro[temp.get(i)][0]  == keiro[que.get(0)][0] + 1) {
					keiro[temp.get(i)][1] += keiro[que.get(0)][1] % 1000000007;
				}

			}

			que.remove(0);
		}

		System.out.println(keiro[b][1]);
	}

	public static void scan() {
		Scanner scan = new Scanner(System.in);

		N = scan.nextInt();
		a = scan.nextInt() - 1;
		b = scan.nextInt() - 1;
		M = scan.nextInt();

		list = new ArrayList[N];
		keiro = new long[N][2];

		for(int i = 0;i < N;i++){
			list[i] = new ArrayList<Integer>();
			keiro[i][0] = 200;
			keiro[i][1] = 0;
		}

		keiro[a][0] = 0;
		keiro[a][1] = 1;

		for(int i = 0;i < M;i++) {
			int x = scan.nextInt() - 1;
			int y = scan.nextInt() - 1;

			list[x].add(y);
			list[y].add(x);
		}

		scan.close();

	}

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.