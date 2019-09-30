import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int max = a/4+2;
        int flag = 0;
        int total = 0;

      
      for(int i = 0;i<max;i++){
       for(int j =0;j<max;j++){
         total = i*4+j*7;
         if(total==a){flag = 1;break;}
       }
      }
		if(flag==1){
          System.out.print("Yes");
        }else{
          System.out.print("No");
        }
    }
}