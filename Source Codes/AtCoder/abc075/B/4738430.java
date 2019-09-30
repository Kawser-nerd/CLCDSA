import java.util.Scanner;

class Main{
	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		sc.nextLine();
		String[] str = new String[H];
		String[][] S = new String[H][W];
		
		for(int i = 0; i < H; i++ ) {
			str[i]= sc.nextLine(); 
		}
		sc.close();
		
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				String s[] = str[i].split("");
				S[i][j] = s[j];
			}
		}
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				if(S[i][j].equals("#")) {
					System.out.print("#");
				}else {
					System.out.print(mineCount(i,j,S));
				}
			}
			System.out.println();
		}
	}
	public static int mineCount(int h, int w, String[][] S) {
		int count = 0;
		for(int i = h - 1; i <= h + 1; i++) {
			if( i < 0 || i >= S.length) {
				continue;
			}
			for(int j = w - 1; j <= w + 1; j++) {
				if( j < 0 || j >= S[0].length ) {
					continue;
				}
				if(S[i][j].equals("#")) {
					count++;
				}
			}
		}
		return count;
	}
}