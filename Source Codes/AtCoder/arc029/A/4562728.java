import java.util.Arrays;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		// ?????
		int ans=Integer.MAX_VALUE;
		int N = Integer.parseInt(sc.next());
		int[] T = new int[N];
		for(int i=0; i<N; i++){
			T[i] = Integer.parseInt(sc.next());
		}
		for(int i=0; i<(1<<N); i++){
			int min;
			int plate_1 = 0;
			int plate_2 = 0;
			for(int j=0; j<N; j++){
				if(((i>>j)&1)==1){
					plate_1 += T[j];
				}else{
					plate_2 += T[j];
				}
			}
			
			if(plate_1>plate_2){
				min = plate_1;
			}else{
				min = plate_2;
			}
			if(ans > min)ans = min;
		}
		System.out.println(ans);
		sc.close();
	}
}