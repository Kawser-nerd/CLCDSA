import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class D {
	public static String source="D-small-attempt0";
	public static Scanner in;
	public static PrintWriter out;


		public static void main(String[] args) throws FileNotFoundException,IOException{
			in=new Scanner(new File(source+".in"));
			out=new PrintWriter(new FileWriter(source+".out"));

			int Cases=in.nextInt();
			for(int Case=1;Case<=Cases;Case++){
				int rows=in.nextInt();
				int cols=in.nextInt();in.nextLine();
				boolean[][] used=new boolean[rows][cols];
				int x=0,y=0;
				for(int i=0;i<rows;i++){
					String line=in.nextLine();
					for(int j=0;j<cols;j++){
						switch(line.charAt(j)){
							case '#':
								used[i][j]=true;
								break;
							case '.':
								used[i][j]=false;
								break;
							case 'K':
								used[i][j]=true;
								x=j;
								y=i;
								break;
						}
					}
				}
				if(winningPosition(used,x,y))
					out.printf("Case #"+Case+": A\n");
				else
					out.printf("Case #"+Case+": B\n");
			}
			out.flush();
		}

		public static boolean winningPosition(boolean[][] used, int x, int y){
			for(int i=-1;i<2;i++){
				for(int j=-1;j<2;j++){
					if(canMove(used,x+j,y+i)){
						used[y+i][x+j]=true;
						boolean result=winningPosition(used,x+j,y+i);
						used[y+i][x+j]=false;
						if(!result)return true;
					}
				}
			}

			return false;
		}
		public static boolean canMove(boolean[][] used, int x, int y){
			if(x<0 || x>=used[0].length || y<0 || y>=used.length)return false;
			return !used[y][x];
		}
}
