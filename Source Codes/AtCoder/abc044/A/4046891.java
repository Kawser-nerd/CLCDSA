import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
      	int k = sc.nextInt();
      	int x = sc.nextInt();
      	int y = sc.nextInt();
		
      int sam = n*x;
      if(n>k){
        sam=sam-((x-y)*(n-k));
      }
     
      System.out.print(sam);
    }
}