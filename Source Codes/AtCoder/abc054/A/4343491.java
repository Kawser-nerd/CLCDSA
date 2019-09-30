import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        if(A == 1)A = 14;
        if(B == 1)B = 14;
        String ans;

        if(A > B){
            ans = "Alice";
        }else if(A < B){
            ans = "Bob";
        }else{
            ans = "Draw";
        }
        System.out.print(ans);
    }
}