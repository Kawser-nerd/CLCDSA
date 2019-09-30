import java.util.*;
import java.io.*;

class Main{
	public static void main(String[] args)throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] input = new int[n][n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n;j++){
				input[i][j] = sc.nextInt();
			}
		}
		int q = sc.nextInt();
		int[] array = new int[q];
		for(int i=0; i<q; i++){
			array[i] = sc.nextInt();
		}
		int[][] sum = new int[n+1][n+1];
		for(int i=0; i<n+1; i++){
			sum[i][0] = 0;
		}
		for(int j=0; j<n+1; j++){
			sum[0][j] = 0;
		}
		for(int i=0; i<n+1; i++){
			for(int j=0; j<n+1; j++){
				for(int k=0; k<i; k++){
					for(int l=0; l<j; l++){
						sum[i][j] += input[k][l];
					}
				}
			}
		}
		int size = n*n;
		int[] area = new int[size];
		for(int i=0; i<size; i++){
			area[i] = -10000000;
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				for(int k=i+1; k<n+1; k++){
					for(int l=j+1; l<n+1; l++){
						int areaSize = (k-i)*(l-j);
						int value = (sum[k][l]-sum[i][l]-sum[k][j]+sum[i][j]);
/*						System.out.print("k="+k+" ");
						System.out.print("l="+l+" ");
						System.out.print(sum[k][l]);
						System.out.println(value);*/
						area[areaSize-1] = Math.max(area[areaSize-1],value);
					}
				}
			}
		}
		for(int i=0; i<array.length; i++){
			int idx = array[i];
			int max = -100000;
			for(int j=0; j<idx; j++)
				max = Math.max(max, area[j]);
				System.out.println(max);
		}
	}
}