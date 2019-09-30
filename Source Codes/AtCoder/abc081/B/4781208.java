import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int hako[]  = new int[a];
        int cont = 0;
        int flag = 1;

      
      for(int i = 0;i<a;i++){
        hako[i] = sc.nextInt();
      }
      
      while(flag==1){
        for(int i = 0;i<a;i++){
          if(hako[i]%2==0){
            hako[i] =hako[i]/2; 
          }else{flag=0;}
        }
        if(flag==1){cont++;}
      }
 
      System.out.print(cont);
    }
}