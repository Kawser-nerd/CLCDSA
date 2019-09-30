import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class A {
    public static void main(String[] args) {
        new A().run();
    }
    void run() {
        Scanner sc = new Scanner(System.in);
        int L = sc.nextInt();
        int D = sc.nextInt();
        int N = sc.nextInt();
        String[] dictionary = new String[D];
        for(int i=0;i<D;++i){
            dictionary[i]=sc.next();
        }
        for(int cases=1;cases<=N;++cases){
            int result = 0;
            String pattern = sc.next();
            pattern=pattern.replace('(','[');
            pattern=pattern.replace(')',']');
            for(int i=0;i<D;++i)if(dictionary[i].matches(pattern))result++;
            System.out.println("Case #"+cases+": "+result);
        }
        
    }
}

