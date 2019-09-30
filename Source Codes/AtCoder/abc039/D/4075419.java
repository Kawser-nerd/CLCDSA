import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int H = scanner.nextInt();
		int W = scanner.nextInt();
		String[] s = new String[H];
		for(int i = 0; i < H; i++){
			s[i] = scanner.next();
		}
		char[][] fig1 = new char[H][W];
		char[][] fig2 = new char[H][W];
		char[][] fig3 = new char[H][W];
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				fig1[i][j] = s[i].charAt(j);
				fig2[i][j] = s[i].charAt(j);
			}
		}
		int[][] num1 = new int[H][W];
		int[][] num2 = new int[H][W];
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				for(int x = -1; x <= 1 ; x++){
					for(int y = -1; y <= 1 ; y++){
						if(i + x < 0 || i + x >= H || j + y < 0 || j + y >= W){
							continue;
						}
						if(fig1[i][j] == '#' && fig1[i+x][j+y] == '.'){
							num1[i][j] = 1;
						}
					}
				}
			}
		}
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				if(num1[i][j] == 1){
					fig2[i][j] = '.';
				}
				fig3[i][j] = fig2[i][j];
			}
		}
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				for(int x = -1; x <= 1 ; x++){
					for(int y = -1; y <= 1 ; y++){
						if(i + x < 0 || i + x >= H || j + y < 0 || j + y >= W){
							continue;
						}
						if(fig2[i][j] == '#'){
							num2[i+x][j+y] = 1;
						}
					}
				}
			}
		}
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				if(num2[i][j] == 1){
					fig2[i][j] = '#';
				}
			}
		}
		boolean flag = true;
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				if(fig1[i][j] != fig2[i][j]){
					flag = false;
					break;
				}
			}
		}
		if(flag){
			System.out.println("possible");
			for(int i = 0; i < H; i++){
				for(int j = 0; j < W; j++){
					System.out.print(fig3[i][j]);
				}
				System.out.println();
			}
		}else{
			System.out.println("impossible");
		}
	}
}