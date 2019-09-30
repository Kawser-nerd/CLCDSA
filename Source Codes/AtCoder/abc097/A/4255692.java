import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
      	int b = sc.nextInt();
      	int c = sc.nextInt();
      	int d = sc.nextInt();
      int x = Math.abs(b-a);
      int y = Math.abs(c-b);
      int z = Math.abs(c-a);
      
      if(x<=d&&y<=d){System.out.println("Yes");}
      else if(z<=d){System.out.println("Yes");}
      else{System.out.println("No");}
      
    }
}