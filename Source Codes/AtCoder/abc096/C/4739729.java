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
					if(isOK(i,j,S) == true) {
						continue;
					}else {
						System.out.print("No");
						System.exit(0);
					}
				}
			}
		}
		System.out.println("Yes");
	}
	public static boolean isOK(int h, int w, String[][] S) {
		boolean isOK = false;
		if( h-1 >= 0 && S[h-1][w].equals("#") ) {
			isOK =true;
		}else if(h+1 < S.length && S[h+1][w].equals("#")) {
			isOK = true;
		}else if(w-1 >= 0 && S[h][w-1].equals("#")) {
			isOK = true;
		}else if(w+1 < S[0].length && S[h][w+1].equals("#")) {
			isOK = true;
		}else {
			
		}
		return isOK;
	}
}