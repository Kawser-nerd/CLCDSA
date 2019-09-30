import java.util.*;

public class Main {        
    
  public static void main(String[] args) {              
     Scanner sc = new Scanner(System.in);                                    
     
     String S = sc.next();
     
     String ans = "";
     
     int A = sc.nextInt();
     int B = sc.nextInt();
     int C = sc.nextInt();
     int D = sc.nextInt();
     
     S = insert(S,D,"\"");
     S = insert(S,C,"\"");
     S = insert(S,B,"\"");
     S = insert(S,A,"\"");
     
     System.out.println(S);
     
  }   
  
  private static String insert(String in,int a,String S){
      return in.substring(0,a) + S + in.substring(a);
  }
  
}