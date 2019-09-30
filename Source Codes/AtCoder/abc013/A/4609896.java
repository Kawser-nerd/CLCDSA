import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String x=sc.next();
        String[] chars={"A","B","C","D","E"};
        for(int i=0;i<5;i++){
            if(x.equals(chars[i])){
                System.out.println(i+1);
            }
        }
        
        
    }
    

}