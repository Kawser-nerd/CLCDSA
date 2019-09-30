import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int a = sc.nextInt();
        
        int ans = x-a;
        if(ans<1){
          System.out.print("0");
        }else{
           System.out.print(ans);
        }
      
		
      
    }
}