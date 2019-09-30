import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
      	int s = sc.nextInt();
      	int t = sc.nextInt();
      	int w = sc.nextInt();
        int cout = 0;
      
      if(w>=s&&w<=t){cout++;}
      for(int i=0;i<n-1;i++){
        w = w + sc.nextInt();
        if(w>=s&&w<=t){cout++;}
      }
      System.out.println(cout);
      

    }
}