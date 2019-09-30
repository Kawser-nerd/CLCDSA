import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int[] b = new int[10];
        for(int i = 0; i < 10; i++)
            b[sc.nextInt()] = i;

        int N = sc.nextInt();

        List<Long> a = new ArrayList<>();
        for(int i = 0; i < N; i++)
            a.add(sc.nextLong());

        Collections.sort(a, (num1, num2) -> Long.compare(convert(num1, b), convert(num2, b)));

        for(long l : a)
            System.out.println(l);
    }

    public static long convert(long num, int[] b) {
        long cvt = 0;
        
        String s = Long.toString(num);
        for(int i = 0; i < s.length(); i++) {
            cvt *= 10;
            cvt += b[Integer.parseInt("" + s.charAt(i))];
        }

        return cvt;
    }
}