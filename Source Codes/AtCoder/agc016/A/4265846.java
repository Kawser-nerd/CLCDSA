import java.util.Arrays;
import java.util.Scanner;

class Main{
	static int max;
	static int[][] mjs;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		int[] alp=new int[26];
		Arrays.fill(alp, 0);
		for(int i=0; i<s.length(); i++) {
			alp[s.charAt(i)-97]++;
		}
		mjs=new int[s.length()][s.length()];
		for(int i=0; i<s.length(); i++) {
			Arrays.fill(mjs[i],-1);
		}
		for(int i=0; i<s.length(); i++) {
			mjs[0][i]=s.charAt(i)-97;
		}
		int answ=114514;
		for(max=0; max<26; max++) {
			for(int i=1; i<s.length(); i++) {
				for(int j=0; j<s.length()-i; j++) {
					if(mjs[i-1][j]!=max && mjs[i-1][j+1]!=max) {
						if(mjs[i-1][j+1]==-1) {
							mjs[i][j]=mjs[i-1][j];
						}
						else {
							mjs[i][j]=mjs[i-1][j];
						}
					}
					if(mjs[i-1][j]==max || mjs[i-1][j+1]==max) {
						mjs[i][j]=max;
					}
				}
			}
			for(int i=0; i<s.length(); i++) {
				boolean ans=ac(i);
				if(ans) {
					answ=Math.min(i, answ);
				}
			}
		}
		System.out.println(answ);
	}
	public static boolean ac(int a) {
		for(int i=0; i<mjs[0].length; i++) {
			if(mjs[a][i]!=-1 && max!=mjs[a][i]) {
				return false;
			}
			else if(mjs[a][i]==-1) {
				break;
			}
		}
		return true;
	}
}