import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
      	String b = sc.next();
      	String c = sc.next();
      char x = a.charAt(a.length()-1);
      char y = b.charAt(0);
      char z = b.charAt(b.length()-1);
      char w = c.charAt(0);
      
	if(x==y&&z==w){System.out.println("YES");}
     else{System.out.println("NO");}
      
    }
}