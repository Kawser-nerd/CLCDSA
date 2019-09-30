import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int output=Integer.MAX_VALUE;
        int tmp;
        for(int i=0;i<n;i++){
            tmp=sc.nextInt();
            if(tmp<output){
                output=tmp;
            }
        }
        System.out.println(output);
        
        

    }

}