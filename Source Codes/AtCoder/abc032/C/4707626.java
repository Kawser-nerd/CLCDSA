import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        long[] nums = new long[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
            if (nums[i] == 0) {
                System.out.println(n);
                return;
            }
        }
        long syakutori = nums[0];
        int beginIndex = 0;
        int endIndex = 0;
        int output = 0;
        try {
            while (true) {
                if (syakutori <= k || beginIndex == endIndex) {
                    if (syakutori <= k && output < endIndex - beginIndex + 1) {
                        output = endIndex - beginIndex + 1;
                    }
                    endIndex++;
                    syakutori *= nums[endIndex];
                } else {
                    syakutori /= nums[beginIndex];
                    beginIndex++;
                }
            }
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println(output);
        }

        
    }

}