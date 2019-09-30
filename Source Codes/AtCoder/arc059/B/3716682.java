import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		int ngs=s.length();
		int[][] unko=new int[26][ngs+1];		//26*10^5
		for(int i=0; i<26; i++) {
			for(int j=0; j<=ngs; j++) {
				unko[i][j]=0;
			}
		}
		for(int i=0; i<ngs; i++) {
			unko[s.charAt(i)-97][i+1]++;
		}
		for(int i=0; i<26; i++) {		//26*10^5
			for(int j=1; j<=ngs; j++) {
				unko[i][j]=unko[i][j]+unko[i][j-1];
			}
		}
		int l=0;
		int r=0;
		int tmp=0;
		for(int i=0; i<26; i++) {
			for(int j=0; j<=ngs-2; j++) {
				if(unko[i][j+2]-unko[i][j]==2) {		// oo????????2????????
					System.out.println(j+1+" "+(j+2));
					System.exit(0);
				}
			}

			for(int j=0; j<=ngs-3; j++) {
				if(unko[i][j+3]-unko[i][j]>=2) {		//oxo??????????????
					System.out.println(j+1+" "+(j+3));
					System.exit(0);
				}
			}
		}
		System.out.println(-1+" "+-1);
	}
}