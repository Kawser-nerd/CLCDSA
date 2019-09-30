import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int T = scan.nextInt();
		for(int t=1;t<=T;t++){
			int R = scan.nextInt(), C = scan.nextInt();
			
			char[][] mat = new char[R][C];
			for(int i=0;i<R;i++){
				String line = scan.next();
				for(int j=0;j<C;j++){
					mat[i][j] = line.charAt(j);
				}
			}
			
			for(int i=0;i<R;i++){
				char prev = '-';
				for(int j=0;j<C;j++){
					if(prev!='-' && mat[i][j]=='?'){
						mat[i][j] = prev;
					}
					else if (mat[i][j]!='?')prev = mat[i][j];
				}
				prev = '-';
				for(int j=C-1;j>=0;j--){
					if(prev!='-' && mat[i][j]=='?'){
						mat[i][j] = prev;
					}
					else if (mat[i][j]!='?')prev = mat[i][j];
				}
			}
			
			for(int i=1;i<R;i++){
				for(int j=0;j<C;j++){
					if(mat[i][j]=='?')mat[i][j]= mat[i-1][j];
				}
			}
			for(int i=R-1;i>=0;i--){
				for(int j=0;j<C;j++){
					if(mat[i][j]=='?')mat[i][j]= mat[i+1][j];
				}
			}
			System.out.println("Case #"+t+":");
			print(mat);
		}
	}
	private static void print(char[][] mat) {
		for(int i=0;i<mat.length;i++){
			for(int j=0;j<mat[0].length;j++){
				System.out.print(mat[i][j]);
			}System.out.println();
		}
	}
}
