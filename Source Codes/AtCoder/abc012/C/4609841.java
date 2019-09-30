import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=2025-sc.nextInt();
        for(int i=1;i<10;i++){
            if(n%i==0&&n/i<10){
                System.out.println(i+" x "+n/i);
            }
        }
        
        
    }
    

}