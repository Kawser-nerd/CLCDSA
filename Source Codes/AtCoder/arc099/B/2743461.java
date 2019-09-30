import java.util.LinkedHashSet;
import java.util.Scanner;
import java.util.Set;

public class Main{
        public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            long K = sc.nextLong();
            Set<Long> sunekeSet = new LinkedHashSet<>();
            for (long m =1; m <=10e15; m*=10){
                boolean sunukeCheckFlag = true;
                for(int i = 1; sunukeCheckFlag; i++){
                    long x = i * m + m - 1;
                    long y = (i + 1) * m + m - 1;
                    if (x * Sn(y) <=  y * Sn(x)){
                        sunekeSet.add(x);
                        if (K == sunekeSet.size()){
                            sunekeSet.stream().forEach(System.out::println);
                            return ;
                        }
                    }else{
                        sunukeCheckFlag = false;

                    }
                }
            }
        }
        public static long Sn(long num){
            long Sn = 0;
            while (num != 0){
                Sn += num % 10;
                num /= 10;
            }
            return Sn;
        }
}