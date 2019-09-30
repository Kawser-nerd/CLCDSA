import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		char[] s1=new char[s.length()];
		for(int i=0; i<s.length(); i++){
			s1[i]=s.charAt(i);
		}
		long ans=0;
		for(int i = 0; i<Math.pow(2,s.length()-1); i++){
			int t=i;
			int count=1;
			String a=String.valueOf(s1[0]);
			while(count<s.length()){
				if((t & 1)==1){
					ans+=Long.parseLong(a);
					a=String.valueOf(s1[count]);
				}else{
					a+=s1[count];
				}
				t>>=1;
				count++;
			}
			ans+=Long.parseLong(a);
		}
		System.out.println(ans);
	}
}