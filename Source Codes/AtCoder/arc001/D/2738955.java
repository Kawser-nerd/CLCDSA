import java.util.Scanner;

public class Main{


	public static void main(String[] args) {
		Main main=new Main();
		main.run();
	}

	void run() {

		Scanner sc=new Scanner(System.in);

		String[][] field=new String[8][8];

		for(int i=0;i<8;i++) {
			String buf=sc.next();
			field[i]=buf.split("");
		}

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

	}

	boolean dfs(int pos,int nokori,String[][] field) {
		//?????????????????????????
			//??????????????????true;
			if(nokori==0) return true;
			//???????????nokori?0????????????false????
			if(pos==64) return false;

		//????????????????????x,y???????
			int y=pos/8;
			int x=pos%8;

		//???????????????Q?????????????

			if(field[y][x].equals("Q")) {
				if(isPuttable(y,x,field)) {
					if(dfs(pos+1,nokori-1,field))return true;
				}

			}else {

				if(isPuttable(y,x,field)) {
					field[y][x]="Q";
					if(dfs(pos+1,nokori-1,field)) return true;
					field[y][x]=".";
				}

				if(dfs(pos+1,nokori,field)) return true;
			}

			return false;
	}

	boolean isinfield(int y,int x) {
		return y>=0 && x>=0 && y<8 && x<8;
	}

	boolean isPuttable(int y,int x,String[][] field) {

		for (int vy = -1; vy <=1; vy++) {
			for (int vx = -1; vx <=1; vx++) {

				//??????????????
				if(vy==0 && vx==0) continue;

				int ty=y;
				int tx=x;

				while(true) {
					ty+=vy;
					tx+=vx;

					if(!isinfield(ty, tx)) break;

					if(field[ty][tx].equals("Q")) return false;
				}

			}
		}

		return true;

	}

}