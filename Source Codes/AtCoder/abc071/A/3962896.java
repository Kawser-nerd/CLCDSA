import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
      
      int y = Math.abs(x-a);
      int z = Math.abs(x-b);
       
      if(y<z){
        System.out.print("A");
      }else{
        System.out.print("B");
      }

    }
}