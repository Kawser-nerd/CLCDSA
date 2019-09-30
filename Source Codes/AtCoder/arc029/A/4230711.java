import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int meatQuantity = sc.nextInt();
        int[] meatTime = new int[meatQuantity];
        for(int i=0; i<meatQuantity; i++){
            meatTime[i] = sc.nextInt();
        }
        int min = 1000;
        for(int bit = 0; bit < Math.pow(2, meatQuantity); bit++){
            int time1 = 0;
            int time2 = 0;
            for(int i = 0; i < meatQuantity; i++){
                if((bit >> i & 1) == 1){
                    time1 += meatTime[i];
                } else {
                    time2 += meatTime[i];
                }
            }
            min = time1 > time2 ? (time1 < min ? time1 : min) : (time2 < min ? time2 : min);
        }
        System.out.println(min);
    }
}