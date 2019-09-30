import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

class Main{

	//static long[] a;
	static	int N ;
	static	int M ;
	static long[][] dp;
	static int ans = 100000000;
	static	boolean[] flag ;

	public static void main(String[] args) {


		Scanner sc = new Scanner(System.in);			//?????
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] x = new int[n];
		int[] y = new int[n];
		int[] lx = new int[n];
		int[] ly = new int[n];
		for(int i = 0; i < n; i++) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
			lx[i] = x[i];
			ly[i] = y[i];
		}
		Arrays.sort(lx);
		Arrays.sort(ly);
 
		Long ans = 1L * (lx[n-1]-lx[0]) * (ly[n-1]-ly[0]);
		for(int xl = 0;xl < n;xl++){
			for(int xr = 0;xr < n;xr++){
				for(int yl = 0;yl < n;yl++){
					for(int yr =0 ;yr < n;yr++){
						int num = 0;
						Long XL = (long)lx[xl];
						Long XR = (long)lx[xr];
						Long YL = (long)ly[yl];
						Long YR = (long)ly[yr];

						for(int i = 0;i < n;i++){
							if(XL <= x[i] && XR >= x[i] && YL >= y[i] && YR <= y[i]){
								num++;
							}
						}
						if(num >= k){
							ans = Math.min(ans,(XR -XL)*1L*(YL-YR));
						}
						
						
					}
				}
			}
		}
		System.out.println(ans);




	}

}
class Bridge{
	int p;			//?????
	ArrayList<Integer> town = new ArrayList<Integer>();				//??????????
	public Bridge(int n) {
		p = n;
	}
	void addtown(int t){
		town.add(t);
	}

	int townnum(){
		return town.size();
	}





}