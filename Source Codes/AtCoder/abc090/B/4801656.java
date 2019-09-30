import java.util.*;
 
class Main {
  
   public static int findSumOfDigits (int n){
     int conut = 0;
     int buf[] = new int[5];
     int flag = 0;
     
     while(n>0){
       buf[conut]=n%10;
       n = n/10;
       conut++;
     } 
     if(buf[0]==buf[1]&&buf[3]==buf[4]){
       if(buf[0]==buf[4]){
         flag = 1;
       }
     }else if(buf[0]==buf[4]&&buf[1]==buf[3]){
       flag = 1;
     }
     return flag;
   }
  
  
    public static void main(String[] args) {
      
      
        Scanner sc = new Scanner(System.in);
        int A = Integer.parseInt(sc.next());
        int B = Integer.parseInt(sc.next());
        int conut = 0;
      for(int i=A;i<=B;i++){
        int flag = findSumOfDigits(i);
        if(flag==1){
          conut++;
        }
      }

		System.out.print(conut);
    }
}