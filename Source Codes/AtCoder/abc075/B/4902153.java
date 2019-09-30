import java.util.*;

public class Main {
	public static void main(String[] args) {
		B();
		return;
	}
	
	public static void A() {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		
		if(A==B) System.out.println(C);
		else if(B==C) System.out.println(A);
		else System.out.println(B);
	}

	// #????????????????
	// -1?#????? ??O(n)
	//???????????????????O(n)???O(1?
	
	public static void calc8(char[][] cell ,int h, int w) {
		if(cell[h][w] == '#') System.out.print('#');
		else {
			int[] hs = new int[] {h-1,h,h+1};
			int[] ws = new int[] {w-1,w,w+1};
			int sum = 0;
			for(int nh: hs) {
				for(int nw : ws) {
					if(nh<cell.length && nh>=0 && nw >=0 && nw < cell[0].length) {
						if(cell[nh][nw]=='#') sum++;
					}
				}
			}
			System.out.print(sum);
		}
		if(w == cell[0].length-1) System.out.println("");
	}
	
	public static void B() {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		char[][] cell = new char[H][W];
		for(int i=0;i<H;i++) {
			String s = sc.next();
			for(int j=0; j<W;j++) {
				cell[i][j] = s.charAt(j);
			}
		}
		for(int i=0;i<H;i++) {
			for(int j=0;j<W;j++) {
				calc8(cell,i,j);
			}
		}
	}
	
	

}