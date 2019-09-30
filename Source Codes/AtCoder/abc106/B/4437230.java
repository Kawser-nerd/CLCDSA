import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int co = 0;
        int yakusu = 0;
      
      for(int i=1;i<=N;i++){
        co = 0;
        if(i%2!=0){
          for(int j=1;j<=i;j++){
            if(i%j==0){co++;}
          }
          if(co==8){yakusu++;}
        }
      }
      System.out.print(yakusu);
    }
}