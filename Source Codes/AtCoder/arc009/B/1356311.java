import java.util.*;


/**
 * Created by takaesumizuki on 2017/06/14.
 * arc011_1
 */
public class Main {
    int[] numbers = new int[10];
    int[] invers = new int[10];
    Scanner sc;
    void run() {
        this.initialize();
//        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        ArrayList<Integer> convertedNum = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            convertedNum.add(this.convert(sc.nextInt()));
        }
        Collections.sort(convertedNum);
        for (int num : convertedNum) {
            System.out.println(this.deconvert(num));
        }
    }

    void initialize() {
        sc = new Scanner(System.in);
//        numbers[0] = 0;
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = sc.nextInt();
        }
        for (int i = 0; i < numbers.length; i++) {
            invers[numbers[i]] = i;
        }
//        sc.close();
    }

    int convert(int num) {
        int m = num;
        int p = num;
        int ret = 0;
        for (int i = 0; m > 0; i++) {
            p = m % 10;
            m /= 10;
//            ret += numbers[p] * Math.pow(10, i);
            ret += invers[p] * Math.pow(10, i);
        }
        return ret;
    }

    int deconvert(int num) {
        int m = num;
        int p = num;
        int ret = 0;
        for (int i = 0; m > 0; i++) {
            p = m % 10;
            m /= 10;
//            ret += invers[p] * Math.pow(10, i);
            ret += numbers[p] * Math.pow(10, i);
        }
        return ret;
    }

    public static void main(String[] args) {
        new Main().run();
    }
}