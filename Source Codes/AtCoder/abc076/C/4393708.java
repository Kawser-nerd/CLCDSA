import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s=sc.next();
		String t=sc.next();
		for(int i=s.length()-t.length(); i>=0; i--){
			int count=0;
			for(int j=i; j<i+t.length(); j++){
				if(s.charAt(j)==t.charAt(j-i) || s.charAt(j)=='?'){
					count++;
					continue;
				}else{
					break;
				}
			}
			if(count==t.length()){
				String ans=s.substring(0,i)+t+s.substring(i+t.length(),s.length());
				ans=ans.replace("?","a");
				System.out.println(ans);
				return;
			}
		}
		System.out.println("UNRESTORABLE");
	}
}