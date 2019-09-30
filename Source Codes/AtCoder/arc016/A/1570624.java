import java.util.*;

public class Main {
    private static int n;
    private static int m;
    
    public static void input(){
        Scanner scan = new Scanner(System.in);

        n = scan.nextInt();
        m = scan.nextInt();
    }

    public static void main(String args[]) {
        //??
        input();
        
        for (int i=1;i<=n;i++){
            if(i != m){
                System.out.println(i);
                break;
            }
        }
    }
}