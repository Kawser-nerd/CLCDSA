import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		
		int n=s.length();
		int[][] table=new int[n/26+1][26];
		int[][] table2=new int[n/26+1][26];
		for(int i=0;i<table.length;i++) Arrays.fill(table[i],-1);
		int res=0;
		int index=n-1;
		int count=0;
		for(;index>=0;index--){
			int c=(int)(s.charAt(index)-'a');
			table2[res][c]=index;
			if(table[res][c]!=-1) continue;
			table[res][c]=index;
			count++;
			if(count==26){
				res++;
				count=0;
			}
		}
		int[] str=new int[res+1];
		for(int i=res;i>=0;i--){
			int pre=0;
			for(int j=0;j<26;j++){
				if(table[i][j]!=-1)continue;
				pre=j;
				break;
			}
			str[res-i]=pre;
			if(i>0){
				int min=table2[i-1][pre];
				for(int j=0;j<26;j++){
					if(table[i-1][j]<=min)table[i-1][j]=-1;
				}
			}
		}
		for(int i=0;i<res+1;i++) System.out.print((char)('a'+str[i]));
		System.out.println();
	}
}