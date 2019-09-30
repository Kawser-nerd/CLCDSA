import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class C {
    public static void main(String[] args) {
        new C().run();
    }
    void run() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine();
        for(int cases=1;cases<=N;++cases){
            String line = sc.nextLine();
            int result = solve2(line,"welcome to code jam");
            System.out.printf("Case #"+cases+": %04d\n",result);
        }
    }
    int solve(String line, String object){
        if(object.length()==0)return 1;
        int result = 0;
        for(int i=0;i<line.length();++i){
            if(line.charAt(i)==object.charAt(0))result+=solve(line.substring(i),object.substring(1));
        }
        return result%10000;
    }
    int solve2(String line, String object){
        int[] table = new int[object.length()+1];
        table[0]=1;
        for(int i=0;i<line.length();++i)for(int j=0;j<object.length();++j){
                if(line.charAt(i)==object.charAt(j))table[j+1]=(table[j+1]+table[j])%10000;
        }
        return table[object.length()];
    }
}

