import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static int N, M, D;
	static int[] line;
	static int[] out;
	static ArrayList<ArrayList<Integer>> linegroup = new ArrayList<ArrayList<Integer>>();

	public static void main(String[] args) {
		scanning();
		int[] templine = new int[N];

		for(int i = 0;i < N;i++) templine[i] = i;

		for(int i = 0;i < M;i++) {
			int swapline = line[i];
			int temp = templine[swapline - 1];

			templine[swapline - 1] = templine[swapline];
			templine[swapline] = temp;
		}

		for(int i = 0;i < N;i++) {
			out[templine[i]] = i;
		}

		for(int i = 0;i < N;i++) {
			if(out[i] != (-1)) {
				ArrayList<Integer> loop = new ArrayList<Integer>();
				int start = i,next = i;
				do{
					int rev = next;
					loop.add(next);
					next = out[next];
					out[rev] = -1;
				}while(start != next);
				linegroup.add(loop);
			}
		}

		for(int i = 0;i < linegroup.size();i++) {
			int groupsize = linegroup.get(i).size();
			int kaisuu = D % groupsize;
			for(int j = 0;j < groupsize;j++) {
				out[linegroup.get(i).get(j)] = linegroup.get(i).get((j + kaisuu) % groupsize);
			}
		}

		for(int x:out) System.out.println(x + 1);

	}


	public static void scanning() {
		Scanner scan = new Scanner(System.in);

		N = scan.nextInt();
		M = scan.nextInt();
		D = scan.nextInt();

		line = new int[M];
		out = new int[N];

		for(int i = 0;i < M;i++) {
			line[i] = scan.nextInt();
		}

		scan.close();
	}

}