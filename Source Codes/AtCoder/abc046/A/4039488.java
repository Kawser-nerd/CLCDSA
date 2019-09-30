import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
      	int b = sc.nextInt();
      	int c = sc.nextInt();
      
        int co = 3;
      
      if(a==b){co--;}
      if(a==c){co--;}
      if(b==c){co--;}
      if(a==b&&b==c){co=1;}
      
      System.out.print(co);
      
    }
    }