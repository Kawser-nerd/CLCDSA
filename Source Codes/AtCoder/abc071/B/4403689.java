import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String S = sc.next();

        for(char i = 'a'; i <= 'z'; i++){
            if(S.indexOf(i) >= 0){
                continue;
            }else{
                System.out.println(i);
                return;
            }
        }
        System.out.println("None");
    }
}