import java.util.Scanner;
public class Main{
	static int b;
	static int[][] c;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		 b = sc.nextInt();
		 c =new int[a][b];
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				c[i][j] = sc.nextInt();
			}
		}
		System.out.println(judge(a-1,0)?"Found":"Nothing");
	}
	 public static boolean judge(int a,int r){
		if(a<0){
				return r==0;
		}
		for(int i = 0; i < b; i++){
			if(judge(a-1,r^c[a][i])){
				return true;
			}
		}
		return false;
	}
}