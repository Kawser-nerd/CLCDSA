import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		int n = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for(int i=0;i<n;i++){
			a[i] = sc.nextInt();
			b[i] = 1+i;
		}
		int[][] map = new int[h][w];

		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]<a[j]){
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
					temp = b[i];
					b[i] = b[j];
					b[j] = temp; 
				}
			}
		}
		int hnow = 0;
		int wnow = 0;
		for(int i=0;i<n;i++){
			while(true){
				if(hnow%2==0){
					if(a[i]>=w-wnow){
						for(int j=wnow;j<w;j++){
							map[hnow][j] = b[i];
						}
						a[i] -= (w - wnow);
						hnow++;
						wnow = w -1;
					}
					else{
						for(int j=wnow;j<wnow+a[i];j++){
							map[hnow][j] = b[i];
						}
						wnow += a[i];
						a[i] = 0;
					}
				}
				else{
					if(a[i]>wnow){
						for(int j=wnow;j>=0;j--){
							map[hnow][j] = b[i];
						}
						a[i] -= (wnow + 1);
						hnow++;
						wnow = 0;
					}
					else{
						for(int j=wnow;j>wnow-a[i];j--){
							map[hnow][j] = b[i];
						}
						wnow -= a[i];
						a[i] = 0;
					}
				}
				if(a[i]==0){
					break;
				}
			}
		}


		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				System.out.print(map[i][j]);
				if(j!=w-1){
					System.out.print(" ");
				}
				else{
					System.out.println();
				}
			}
		}
	}
}