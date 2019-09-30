import java.util.*;

public class Main{
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	String SA = sc.next();
	String SB = sc.next();
	String SC = sc.next();
	int i = 0,j = 0,k = 0;
	String ans = "";
	char tmp = SA.charAt(i);
	i++;
	boolean f = true;
	while(f){
	    // System.out.println(tmp);
	    if ( tmp == 'a' ) {
		if ( i == SA.length() ) {
		    ans = "A";
		    break;
		}				
		tmp = SA.charAt(i);
		i++;

		//	System.out.println("111111");
	    } else if (tmp == 'b') {
		if ( j == SB.length() ) {
		    ans = "B";
		    break;
		}						
		tmp = SB.charAt(j);
		j++;
		//		System.out.println("222222");		
	    } else if (tmp == 'c') {
		if ( k == SC.length() ) {
		    ans = "C";
		    break;
		}						
		tmp = SC.charAt(k);
		k++;
		//		System.out.println("333333");		
	    }
	    
	}
	System.out.println(ans);
    }
}