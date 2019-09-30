import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
      	String s=sc.nextLine();
      	String S[]=s.split("[+]");
      	int ans=0;
      	for(int i=0;i<S.length;i++) {
      		if(S[i].contains("0")==false)ans++;
      	}
      	System.out.println(ans);
    }
}