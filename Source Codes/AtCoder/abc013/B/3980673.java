import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        Queue<Integer> q=new ArrayDeque<>();
        Queue<Integer> ans=new ArrayDeque<>();
        q.add(a);
        ans.add(0);
        int answer=10;
        while (!q.isEmpty()){
            int p=q.poll();
            int c=ans.poll();
            if(p==b){
                answer=c;
                break;
            }
            else {
                q.add((p + 1)%10);
                q.add((p - 1+10)%10);
                ans.add(c + 1);
                ans.add(c + 1);
            }
        }
        out.println(answer);
    }
}