import java.util.*;
import java.util.stream.IntStream;

public class Main {

    public static boolean found = false;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int numOfPerson = sc.nextInt();
        int numOfFoot = sc.nextInt();

        int maxFoot = numOfPerson * 4;
        int minFoot = numOfPerson * 2;

        // ????????
        if (numOfFoot < minFoot || maxFoot < numOfFoot) {
            System.out.println("-1 -1 -1");
            return;
        }

        int numOfAdult = numOfPerson;  // ??????????????????????
        int diff = numOfFoot - minFoot;// ???????????

        // ??1???????????+1,?????????+2????
        // ??????????????????????????????????=???????????
        if (diff % 2 == 0) {
            int numOfBaby = (diff / 2);
            numOfAdult = numOfAdult - numOfBaby;
            System.out.println(numOfAdult + " 0 " + numOfBaby);
        } else {
            int numOfBaby = (diff / 2);
            numOfAdult = numOfAdult - numOfBaby - 1;
            System.out.println(numOfAdult + " 1 " + numOfBaby);
        }
    }

}