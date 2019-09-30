import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class GCJ2011QualB{
	void solve(){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int QB=1;QB<=T;QB++){
			int C = sc.nextInt();
			char[][] cb = new char[C][3];
			for(int i=0;i<C;i++) cb[i] = sc.next().toCharArray();
			int D = sc.nextInt();
			char[][] op = new char[D][3];
			for(int i=0;i<D;i++) op[i] = sc.next().toCharArray();
			int N = sc.nextInt();
			char[] spell = sc.next().toCharArray();
			char[] res   = new char[T];
			int size = 0;
			for(int i=0;i<N;i++){
				res[size++] = spell[i];
				if(size>=2){
					for(int j=0;j<C;j++){
						if((res[size-1]==cb[j][0]&&res[size-2]==cb[j][1]) ||
						   (res[size-2]==cb[j][0]&&res[size-1]==cb[j][1])){
							res[size-2] = cb[j][2];
							size--;
							break;
						}
					}
				}
				for(int j=0;j<size-1;j++){
					for(int k=0;k<D;k++){
						if((res[j]==op[k][0]&&res[size-1]==op[k][1]) ||
						   (res[size-1]==op[k][0]&&res[j]==op[k][1])){
							size = 0;
							break;
						}
					}
				}
			}
			
			System.out.print("Case #"+QB+": [");
			if(size > 0){
				for(int i=0;i+1<size;i++) System.out.print(res[i] + ", ");
				System.out.println(res[size-1] + "]");
			} else {
				System.out.println("]");
			}
		}
	}
	public static void main(String args[]){
		new GCJ2011QualB().solve();
	}
}