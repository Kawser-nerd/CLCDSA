import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
      	int b = sc.nextInt();
      	int x = sc.nextInt();
      
      for(int i=x; ;i++){
		if(i%a==0 && i%b==0){
          System.out.println(i);
        break;
        }
      }
      
    }
}