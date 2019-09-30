import java.util.*;

public class Main {
    private static String s;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        s = scan.next();
    }

    public static void main(String args[]) {
        //??
        input();

        int N = s.length();

        int count = 0;
        for(int i = 0;i < N/2;i++){
            if(s.charAt(i) != s.charAt(N-i-1))
                count++;
        }

        int ans = 0;
        if(count == 0){
            if(N%2 == 1){
                ans = 25*N - 25;
            }else{
                ans = 25*N;
            }
        }
        else if(count == 1){
            ans = 25*N - 2;
        }
        else if(count >= 2){
            ans = 25*N;
        }

        System.out.println(ans);
    }
}