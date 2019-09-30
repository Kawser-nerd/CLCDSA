import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
      	int b = sc.nextInt();
      	int c = sc.nextInt();
      	int k = sc.nextInt();
      	int s = sc.nextInt();
      	int t = sc.nextInt();
      int sam = s+t;
      int sam2 = (a*s)+(b*t);
      
      if(sam>=k){System.out.println(sam2-sam*c);}
      else{System.out.println(sam2);}
      	

    }
}