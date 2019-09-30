import java.util.Arrays;
import java.util.Scanner;
 
public class Main{
 
	static boolean[][] first;
	static char[][] a;
	static int h;
	static int w;
	static int k;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		h = sc.nextInt();
		w = sc.nextInt();
		k = sc.nextInt();
		a = new char[h][w];
		String s = sc.nextLine();
		first = new boolean[h][w];
		for(int i=0;i<h;i++)Arrays.fill(first[i], false);
		int si=0,sj=0;
		for(int i=0;i<h;i++){
			s = sc.nextLine();
			for(int j=0;j<w;j++){
				a[i][j] = s.charAt(j);
				if(a[i][j] == 'S'){
					si = i;
					sj = j;
				}
			}
		}
		sc.close();
		/*
		for(int i=0;i<k;i++){
			for(int j=0;j<h;j++){
				for(int l=0;l<w;l++){
					if(first[j][l]){
						if(j>0&&a[j-1][l]=='.') first[j-1][l] = true;
						if(j<h-1&&a[j+1][l]=='.') first[j+1][l] = true;
						if(l>0&&a[j][l-1]=='.') first[j][l-1] = true;
						if(l<w-1&&a[j][l+1]=='.') first[j][l+1] = true;
					}
				}
			}
		}
		*/
		dec(si,sj);
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
 
				if(Math.abs(si-i)+Math.abs(sj-j)>k) first[i][j] = false;
			}
		}
		int minscore = Math.min(h, w);
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				//System.out.print(first[i][j]?1:0);
				if(first[i][j]){
					int cx = Math.min(i, h-1-i);
					int cy = Math.min(j, w-1-j);
					int cscore = Math.min(cx, cy);
					minscore = Math.min(cscore, minscore);
				}
			}
			//System.out.println();
		}
		//System.out.println(minscore);
		int ans = 1;
		ans += (minscore+k-1)/k;
		System.out.println(ans);
	}
	public static void dec(int i,int j){
		first[i][j] = true;
		if(i>0&&a[i-1][j]=='.'&&!first[i-1][j]) dec(i-1,j);
		if(i<h-1&&a[i+1][j]=='.'&&!first[i+1][j]) dec(i+1,j);
		if(j>0&&a[i][j-1]=='.'&&!first[i][j-1]) dec(i,j-1);
		if(j<w-1&&a[i][j+1]=='.'&&!first[i][j+1]) dec(i,j+1);
	}
 
}