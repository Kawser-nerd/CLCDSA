import java.util.Arrays;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		// ?????
		int D = Integer.parseInt(sc.next());
		int G = Integer.parseInt(sc.next());
		int[][] p = new int[D][2];
		for(int i=0; i<D; i++){
			p[i][0] = Integer.parseInt(sc.next());	//???
			p[i][1] = Integer.parseInt(sc.next());	//?????
		}
		
		int ans = Integer.MAX_VALUE;
		
		for(int i=0; i<(1<<D); i++){
			int solve = 0;
			int need = G;
			for(int j=0;j<D;j++){
				if((i>>j & 1)==1){
					solve += p[j][0];
					need -= ((j+1)*100*p[j][0] + p[j][1]);
				}
			}
			
			if(need>0){
				for(int k=D-1; k>=0; k--){
					if(((i>>k) & 1)== 1)continue;
					int count=0;
					while(p[k][0]>count){
						need -= (k+1)*100;
						solve++;
						count++;
						if(need<=0)break;
					}
					if(need>0)solve=Integer.MAX_VALUE;
					break;
				}
			}
			if(solve < ans)ans = solve;
		}		
		System.out.println(ans);
		sc.close();
	}
}