import java.util.Scanner;

public class Main{


	public static int[][] dp=new int[1000][1000];

	public static void main(String[] args) {
		Main main=new Main();
		main.run();
	}

	void run() {
		Scanner sc=new Scanner(System.in);

		String[][] field=new String[8][8];

		for (int i = 0; i < 8; i++) {
			field[i]=sc.next().split("");
		}

		if(dfs(0,8,field)) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					print(field[i][j]);
				}

				nl();
			}
		}else {
			pln("No Answer");
		}
	}

	boolean dfs(int pos,int nokori,String[][] field) {

		if(nokori==0)return true;

		if(pos==64)return false;

		int y=pos/8;
		int x=pos%8;

		if(field[y][x].equals("Q")) {

			if(canPut(y,x,field)) {
				if(dfs(pos+1,nokori-1,field)) {
					return true;
				}
			}

		}else {

			if(canPut(y,x,field)) {
				field[y][x]="Q";
				if(dfs(pos+1,nokori-1,field)) {return true;}
				field[y][x]=".";
			}

			if(dfs(pos+1,nokori,field))return true;

		}

		return false;

	}

	boolean isIn(int y,int x) {
		return y>=0 && y<8 && x>=0 && x<8;
	}

	boolean canPut(int y,int x,String[][] field) {

		for (int dy = -1; dy <= 1; dy++) {
			for (int dx = -1; dx <= 1; dx++) {

				if (dy == 0 && dx == 0) {
					continue;
				}

				int ty=y;
				int tx=x;

				while(true) {

					ty+=dy;
					tx+=dx;

					if(!isIn(ty, tx)) {
						break;
					}

					if(field[ty][tx].equals("Q"))return false;

				}

			}
		}

		return true;

	}

	static void pln(String str) {
		System.out.println(str);
	}

	static void print(String str) {
		System.out.print(str);
	}

	static void nl() {
		System.out.println();
	}




}