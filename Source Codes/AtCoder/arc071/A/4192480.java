import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] list=new int[26];
		Arrays.fill(list,Integer.MAX_VALUE);
		for(int i=0;i<n;i++){
			String str=sc.next();
			int[] ta=new int[26];
			for(int j=0;j<str.length();j++){
				char ch=str.charAt(j);
				ta[(int)(ch-'a')]++;
			}
			for(int j=0;j<26;j++){
				list[j]=Math.min(list[j],ta[j]);
			}
		}
		String res="";
		for(int i=0;i<26;i++){
			for(int j=0;j<list[i];j++){
				res+=(char)('a'+i);
			}
		}
		System.out.println(res);
	}
}