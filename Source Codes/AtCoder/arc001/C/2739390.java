import java.util.Scanner;

public class Main{


	public static int[][] dp=new int[1000][1000];

	public static void main(String[] args) {
		Main main=new Main();
		main.run();
	}

	void run() {
		//??

		Scanner sc=new Scanner(System.in);

		String[][] field=new String[8][8];

		for (int i = 0; i < 8; i++) {
			field[i]=sc.next().split("");
		}


		//dfs?????

		if(dfs(0,8,field)) {

			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					System.out.print(field[i][j]);
				}

				System.out.println();
			}

		}else {
			System.out.println("No Answer");
		}

		//??
	}

	//dfs??
	boolean dfs(int pos,int nokori,String[][] field) {

		//?????
		if(nokori==0) return true;

		if(pos==64) return false;

		//pos??x,y?????

		int y=pos/8;
		int x=pos%8;

		//??

			//?????Q???????
			//8??????????????????????????????????????????

		if(field[y][x].equals("Q")) {

			if(canPut(y, x, field)) {
				if(dfs(pos+1,nokori-1,field)) return true;
			}
			//??????????
			//??????????????
		}else {


			if(dfs(pos+1,nokori,field)) return true;
			//??
			if(canPut(y,x,field)) {

				field[y][x]="Q";
				if(dfs(pos+1,nokori-1,field)) return true;
				field[y][x]=".";
			}




		}

		return false;
	}

	//?????????

	boolean isInField(int y,int x) {
		return y>=0 && y<8 && x>=0 && x<8;
	}

	//???????????????????????
	boolean canPut(int y,int x,String[][] field) {

		for(int dy=-1;dy<=1;dy++) {
			for (int dx = -1; dx <=1; dx++) {

				if(dy==0 && dx==0) continue;

				int ty=y;
				int tx=x;

				while(true) {
					ty+=dy;
					tx+=dx;

					if(!isInField(ty, tx)) break;
					if(field[ty][tx].equals("Q")) return false;
				}

			}
		}

		return true;

	}
}