import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
      	int x = sc.nextInt();
      
      if(x%5==0){
        System.out.print(s.charAt(x/5-1));
        System.out.println(s.charAt(4));
      }
      else{
        System.out.print(s.charAt(x/5));
        System.out.println(s.charAt(x%5-1));
       }
      
       
      
    }
}