import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt();
        int h = 0, m = 0;

        for(;s>0;){
            if(s/3600 >= 1){
                h++;
                s -= 3600;
                continue;
            }
            if(s/60 >= 1){
                m++;
                s -= 60;
                continue;
            }
            break;
        }
        System.out.println(String.format("%02d:%02d:%02d",h,m,s));
    }
}