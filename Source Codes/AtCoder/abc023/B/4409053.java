import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        int ans = -1;

        if(n % 2 == 1){
            String t = "";
            for(int i = 0; t.length() < n; i++){
                if(i == 0){
                    t += "b";
                }else if(i % 3 == 1){
                    t = "a" + t + "c";
                }else if(i % 3 == 2){
                    t = "c" + t + "a";
                }else{
                    t = "b" + t + "b";
                }

                if(t.equals(s)){
                    ans = i;
                    break;
                }
            }
        }

        System.out.println(ans);
    }
}