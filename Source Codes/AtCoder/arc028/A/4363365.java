import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt(),a=sc.nextInt(),b=sc.nextInt();
        String[] ans={"Bug","Ant"};
        int turn=0;
        while (n>0){
            turn++;
            n-=turn%2==1?a:b;
        }
        out.println(ans[turn%2]);
    }
}