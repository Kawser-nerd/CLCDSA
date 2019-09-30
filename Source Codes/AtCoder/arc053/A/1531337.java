import java.util.*;

public class Main{     
        
    public static void main(String[] args){
      
        Scanner sc = new Scanner(System.in);                                               
        
        int H = sc.nextInt();
        
        int W = sc.nextInt();
                                                      
        if(W > H){
            int temp = H;
            H = W;
            W = temp;
        }
        
        if(W == 1 && H == 1){
            System.out.println(0);
            return;
        }
        
        if(W == 1 && H >= 2){
            System.out.println(H - 1);
            return;
        }
        
        if(W >= 2 && H>=2){
            System.out.println((W-1)*H + (H-1)*W);
            return;
        }
                                
    }        
}