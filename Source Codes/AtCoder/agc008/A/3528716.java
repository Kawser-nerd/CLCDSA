import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main{
    public static void main(String[]$){
        Scanner sc = new Scanner(in);
        int x=sc.nextInt();
        int y=sc.nextInt();
        if(x==y){
            out.println(0);
            exit(0);
        }
        if(abs(x)==abs(y)){
            out.println(1);
            exit(0);
        }
        if(x==0){
            if(y<0)out.println(1-y);
            else out.println(y);
        }else if(y==0){
            if(x>0)out.println(1+x);
            else out.println(-x);
        }else if(x>0&&y>0){
            if(x>y)out.println(x-y+2);
            else out.println(y-x);
        }else if(x<0&&y>0){
            out.println(abs(x+y)+1);
        }else if(x<0&&y<0){
            if(x<y)out.println(y-x);
            else out.println(x-y+2);
        }else{
            out.println(abs(x+y)+1);
        }
    }
}