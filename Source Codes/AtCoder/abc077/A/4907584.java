import java.util.*;

class Main{
	public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        String b = sc.nextLine();
        
        String c11 = a.substring(0,1);
        String c12 = a.substring(1,2);
        String c13 = a.substring(2,3);
        String c21 = b.substring(0,1);
        String c22 = b.substring(1,2);
        String c23 = b.substring(2,3);
        if (c11.equals(c23) && c12.equals(c22) && c13.equals(c21)){
        	System.out.println("YES");
        }else{
        	System.out.println("NO");
        }
    }
}