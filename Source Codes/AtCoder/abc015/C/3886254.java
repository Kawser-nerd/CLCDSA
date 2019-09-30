import java.util.Scanner;
public class Main{
	static int a;
	static int b;
	static int[][] c;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		 a = sc.nextInt();
		 b = sc.nextInt();
		 c =new int[a][b];
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				c[i][j] = sc.nextInt();
			}
		}
		System.out.println(judge(0,0)?"Found":"Nothing");
	}
	 public static boolean judge(int t,int r){
		if(t==a){
				return r==0;
		}
		for(int i = 0; i < b; i++){
			if(judge(t+1,r^c[t][i])){
				return true;
			}
		}
		return false;
	}
}