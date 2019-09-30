import java.util.Scanner;
public class Main{
	static char[][] cv;
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		int h=sc.nextInt();
		int w=sc.nextInt();
		sc.nextLine();
		cv=new char[h][w];
		for(int i=0;i<h;i++) {
			String str=sc.nextLine();
			for(int j=0;j<w;j++) {
				cv[i][j]=str.charAt(j);
			}
		}
		boolean flg=true;
		boolean up,down,left,right;
		for(int i=0;i<h&&flg;i++) {
			for(int j=0;j<w&&flg;j++) {
				if(isBlack(i,j)) {
					up=isBlack(i-1,j);
					down=isBlack(i+1,j);
					left=isBlack(i,j-1);
					right=isBlack(i,j+1);
					if(!(up||down||left||right)) {
						flg=false;
					}
				}
			}
		}
		if(flg) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
	static boolean isBlack(int y,int x) {
		try {
			if(cv[y][x]=='#') {
				return true;
			}else {
				return false;
			}
		} catch (ArrayIndexOutOfBoundsException e) {
			return false;
		}
	}
}