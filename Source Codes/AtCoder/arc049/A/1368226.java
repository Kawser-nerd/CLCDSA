import java.util.*;

public class Main {    
    
    public static void main(String[] args){
       
      Scanner sc = new Scanner(System.in);          
      
      String in = sc.next();
   
      int A = sc.nextInt();
      int B = sc.nextInt();
      int C = sc.nextInt();
      int D = sc.nextInt();                      

      in = insert(in,D,"\"");      
      in = insert(in,C,"\"");
      in = insert(in,B,"\"");
      in = insert(in,A,"\"");
      
      System.out.println(in);      
      
    }   
   
    private static String insert(String in,int a,String S){
          return in.substring(0,a) + S + in.substring(a);
    }
   
}