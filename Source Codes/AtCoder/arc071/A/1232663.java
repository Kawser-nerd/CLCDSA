import java.util.*;
public class Main{
	public static int order(long a){
		int o=0;
		long d=1;
		while(d<=a){
			o++;d*=10;
		}
		return o;
	}
	public static int ABCNumber(char a){
		int num=-1;
		char[] abc= "abcdefghijklmnopqrstuvwxyz".toCharArray();
		for(int n=0;n<26;n++){
			if(a==abc[n])num=n;
		}
		return num;
	}
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int N =Integer.parseInt(sc.next());
		String[] S= new String[N];
		for(int i=0;i<N;i++){
			S[i]=sc.next();
		}
		
		int[] xmin= new int[26];
		for(int n=0;n<26;n++)xmin[n]=50;
		for(int i=0;i<N;i++){
			int[] x= new int[26];
			for(char a: S[i].toCharArray()){
				x[ABCNumber(a)]++;
			}
			for(int n=0;n<26;n++){
				xmin[n]=Math.min(xmin[n], x[n]);
			}
		}
		
		
		char[] abc= "abcdefghijklmnopqrstuvwxyz".toCharArray();
		StringBuilder sb= new StringBuilder();
		for(int n=0;n<26;n++){
			for(int cnt=0;cnt<xmin[n];cnt++)sb.append(abc[n]);
		}
		System.out.println(sb.toString());
		
		sc.close();
	}
}