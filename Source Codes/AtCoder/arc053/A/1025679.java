import java.util.*;


public class Main{
           
    public static void main(String[] args){
            
        Scanner sc = new Scanner(System.in);
        
        int H = sc.nextInt();
        int W = sc.nextInt();
        
         //weith
         int count = 0;
         
         int witdhcount = 0;
         for(int i = 0 ;i < W-1;i++){
             witdhcount++;
         }
         
         count += witdhcount*H;
        
        //heigth
        
        int heightcount = 0;
        for(int i = 0 ;i < H - 1;i++){
            heightcount++;
        }
        
        count+= heightcount*W;
        
        System.out.println(count);
        
        
        
    }
}