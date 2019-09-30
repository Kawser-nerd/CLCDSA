import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
      	int x = sc.nextInt();
      	int mai = n-x;
      
      if(mai>x){System.out.print(x-1);}
      if(mai<x){System.out.print(mai);}
      if(mai==x){System.out.print(x-1);}
        
    }
}