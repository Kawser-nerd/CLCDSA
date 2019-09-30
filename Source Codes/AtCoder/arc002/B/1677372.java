import java.util.*;

public class Main {                   
    
  public static void main(String[] args) {                     
    Scanner sc = new Scanner(System.in);      
    
    //y m d
    
    int md[] = new int[]{-1,31,28,31,30,31,30,31,31,30,31,30,31};      
    
    String S = sc.next();
    String sp[] = S.split("/");
    
    int Y = Integer.parseInt(sp[0]);
    int M = Integer.parseInt(sp[1]);
    int D = Integer.parseInt(sp[2]);
    
    int ansy = 0;
    int ansm = 0;
    int ansd = 0;

     int y = Y;    
     int m = M;     
    
    while(ansy == 0){
             int day = md[m];             
             if(m == 2){
                boolean flag =false;
                if(y%4 == 0){
                    flag = true;    
                }
                if(y%100 == 0){
                    flag = false;
                }
                if(y%400 == 0){
                    flag = true;
                }                                 
                if(flag){
                    day++;
                }                 
             }               
             for(int d = D;d <= day;d++){                               
                  if(y%m == 0){
                      int y1 = y/m;
                      if(y1%d == 0){
                          ansy = y;
                          ansm = m;
                          ansd = d;
                          break;
                      }                      
                  }                                   
             }      
             D = 1;
        m++;
        if(m == 13){
         m = 1;  
        }
        if(m == 1)y++;        
      }   
     
    String sy = String.valueOf(ansy);
    String sm = String.valueOf(ansm);
    String sd = String.valueOf(ansd);
    if(ansm < 10){
        sm = "0" + sm;
    }    
    if(ansd < 10){
        sd = "0" + sd;
    }    
     System.out.println(sy + "/" + sm + "/" + sd);
    
  }      
}