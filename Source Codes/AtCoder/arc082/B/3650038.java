import java.util.Scanner;
	

public class Main{

	public static void main(String args[])throws Exception{
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		
		int[] p = new int[N];
		for(int i=0;i<N;i++){
			p[i] = sc.nextInt()-1;
		}
		int pos = 0;
		int ans = 0;
		while(pos<N){
			if(pos == p[pos]){
				if(pos!=N-1){
					if(pos+1 == p[pos+1]){
						ans++;
						pos += 2;
					}else{
						ans++;
						pos++;
					}
				}else{
					ans++;
					pos++;
				}
			}else{
				pos++;
			}
		}
		System.out.println(ans);
	}
	

}