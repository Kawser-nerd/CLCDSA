import java.util.*;

public class Main{

	public static void main(String[] args){

		int i, j, n, m, a[][], b[][];
		String a1[];
		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();
		m = sc.nextInt();
		a = new int[n][m];
		b = new int[n][m];
		a1 = new String[n];

		for(i=0;i<n;i++) a1[i] = sc.next();
		for(i=0;i<n;i++) for(j=0;j<m;j++) a[i][j] = Character.getNumericValue(a1[i].charAt(j));
		for(i=0;i<n;i++) for(j=0;j<m;j++) b[i][j] = 0;

		for(i=0;i<n-2;i++){
			for(j=1;j<m-1;j++){
				if(a[i][j]!=0){
					b[i+1][j] = a[i][j];
					a[i+1][j-1] -= a[i][j];
					a[i+1][j+1] -= a[i][j];
					a[i+2][j] -= a[i][j];
					a[i][j] = 0;
				}
			}
		}

		for(i=0;i<n;i++){
			for(j=0;j<m;j++)System.out.print(b[i][j]);
			System.out.println("");
		}
	}
}