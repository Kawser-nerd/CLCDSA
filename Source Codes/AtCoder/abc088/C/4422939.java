import java.util.*;
 
class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int[][] c = new int[3][3];
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				c[i][j] = sc.nextInt();
			}
		}
		int[] a = new int[3];
		int[] b = new int[3];
		for(int i = 0; i < 3; i++){
			a[i] = Math.min(c[i][0],Math.min(c[i][1],c[i][2]));
		}
		for(int i = 0; i < 3; i++){
			b[i] = Math.min(c[0][i],Math.min(c[1][i],c[2][i]));
		}
		boolean flag = false;
		for(int i = a[0]; i > -1; i--){
			for(int j = a[1]; j > -1; j--){
				for(int k = a[2]; k > -1; k--){
					int l = c[0][0] - i;
					int m = c[1][1] - j;
					int n = c[2][2] - k;
					if(i+l==c[0][0] && i+m==c[0][1] && i+n==c[0][2] && j+l==c[1][0] && j+m==c[1][1] && j+n==c[1][2] && k+l==c[2][0] && k+m==c[2][1] && k+n==c[2][2]){
					   flag = true;
					   break;
					}
				}
			}
		}
		/*for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				System.out.print(c[i][j]);
			}
			System.out.println();
		}
		for(int i = 0; i < 3; i++){
			System.out.print(a[i]);
		}
		for(int i = 0; i < 3; i++){
			System.out.print(b[i]);
		}*/
		if(flag){
			System.out.print("Yes");
		}else{
			System.out.print("No");
		}
	}
}