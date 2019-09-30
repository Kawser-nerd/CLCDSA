import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double n=sc.nextInt();
        double tmpN=n;
        double a=0;
        int tmp;
        for(int i=0;i<n;i++){
            tmp=sc.nextInt();
            if(tmp==0){
                tmpN--;
            }else{
                a+=tmp;
            }
        }
        n=tmpN;
        int output=0;
        while(true){
            if(a/n<=output){
                System.out.println(output);
                return;
            }
            output++;
        }
        
        
    }

}