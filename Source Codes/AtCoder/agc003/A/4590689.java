import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	String s=sc.nextLine();
    	String S[]=s.split("");
    	String ans="Yes";
    	int south=0;
    	int north=0;
    	int east=0;
    	int west=0;
    	for(int i=0;i<S.length;i++) {
    		if(S[i].equals("S"))south++;
    		if(S[i].equals("N"))north++;
    		if(S[i].equals("W"))west++;
    		if(S[i].equals("E"))east++;
    	}
    	if(south>0&&north<=0) ans="No";
    		if(north>0&&south<=0) ans="No";
    		if(east>0&&west<=0) ans="No";
    		if(west>0&&east<=0) ans="No";
    		System.out.println(ans);
    }
}