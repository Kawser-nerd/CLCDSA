import java.util.Scanner;

/**
 * https://abc039.contest.atcoder.jp/tasks/abc039_d
 */
public class Main {

	static int W = 1;
	static int B = 2;
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int[][] field = new int[H][W];
		for(int y=0; y<H; y++){
			String s = sc.next();
			for(int x=0; x<W; x++){
				field[y][x] = s.charAt(x) == '#' ? B : W;
			}
		}
		sc.close();
		sc.close();
		
		int[][] before = new int[H][W];
		for(int y=0; y<H; y++){
			for(int x=0; x<W; x++){
				if(field[y][x]==W){
					before[y][x] = W;
					if(x>0) before[y][x-1] = W;			
					if(x<W-1) before[y][x+1] = W;
					if(y>0) before[y-1][x] = W;
					if(y<H-1) before[y+1][x] = W;
					if(x>0 && y>0) before[y-1][x-1] = W;
					if(x>0 && y<H-1) before[y+1][x-1] = W;
					if(x<W-1&& y>0) before[y-1][x+1] = W;
					if(x<W-1 && y<H-1) before[y+1][x+1] = W;
				}
			}
		}
		for(int y=0; y<H; y++){
			for(int x=0; x<W; x++)
				if(before[y][x]==0) before[y][x] = B;
		}
		
		int[][] after = new int[H][W];
		for(int y=0; y<H; y++){
			for(int x=0; x<W; x++){
				if(before[y][x]==B){
					after[y][x] = B;
					if(x>0) after[y][x-1] = B;
					if(x<W-1) after[y][x+1] = B;
					if(y>0) after[y-1][x] = B;
					if(y<H-1) after[y+1][x] = B;
					if(x>0 && y>0) after[y-1][x-1] = B;
					if(x>0 && y<H-1) after[y+1][x-1] = B;
					if(x<W-1&& y>0) after[y-1][x+1] = B;
					if(x<W-1 && y<H-1) after[y+1][x+1] = B;
				}
			}
		}
		for(int y=0; y<H; y++){
			for(int x=0; x<W; x++)
				if(after[y][x]==0) after[y][x] = W;
		}
		
		boolean ans = true;
		for(int y=0; y<H; y++){
			for(int x=0; x<W; x++){
				if(after[y][x]!=field[y][x]){
					ans = false;
					break;
				}
			}
			if(!ans) break;
		}
		
		
		if(ans){
			System.out.println("possible");
			for(int y=0; y<H; y++){
				StringBuilder sb = new StringBuilder();
				for(int x=0; x<W; x++){
					sb.append(before[y][x]==W ? "." : "#");
				}
				System.out.println(sb);
			}
		}else{
			System.out.println("impossible");
		}

	}

}