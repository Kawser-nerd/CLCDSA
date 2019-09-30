import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[] c=sc.next().toCharArray();
		
		boolean sh[]=new boolean[n+2];
		
		for(int z=0;z<4;z++){
			Arrays.fill(sh, false);
			sh[0]=(z&1)==0; sh[1]=(z&2)==0;
			for(int i=2;i<n+2;i++){
				sh[i]=sh[i-1]^sh[i-2]^c[(i-1)%n]=='o';
			}
			if(sh[n]==sh[0]&&sh[n+1]==sh[1]){
				put(sh);
				return;
			}
		}
		
		System.out.println(-1);
	}
	
	static void put(boolean[] sh){
		for(int i=0;i<sh.length-2;i++){
			System.out.print(sh[i]?"S":"W");
		}
		System.out.println();
	}
}