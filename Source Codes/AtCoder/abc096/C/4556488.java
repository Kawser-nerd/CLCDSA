import java.util.Scanner;

public class Main{
	static int H, W;
	static char[][] map;

	public static void main(String args[]) {
		Scanner scn = new Scanner(System.in);
		H = scn.nextInt();
		W = scn.nextInt();
		map = new char[H][W];
		boolean ans = true;

		scn.nextLine();
		for (int i = 0; i < H; i++) {
			map[i] = scn.nextLine().toCharArray();
		}
		for (int i = 0; i < H; i++) {
			if(!ans)break;
			for (int j = 0; j < W; j++) {
				ans &= check(i,j);
			}
		}
		System.out.println(ans?"Yes":"No");
	}

	public static boolean check(int h, int w) {
		if (map[h][w] == '#') {
			boolean ans = false;
			if(h!=0)ans |= map[h-1][w] == '#';
			if(h!=H-1)ans |= map[h+1][w] == '#';
			if(w!=0)ans |= map[h][w-1] == '#';
			if(w!=W-1)ans |= map[h][w+1] == '#';
			return ans;

		} else {
			return true;
		}

	}
}