import java.util.*;
import java.io.*;

public class A
{
    static int N;

    static int ans;

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            N = input.nextInt();

            int[] nums = new int[N];
            int sum = 0;
            for (int i = 0; i < N; i++)
            {
                nums[i] = input.nextInt();
                sum += nums[i];
            }

            List<String> steps = new ArrayList<String>();
            while (sum > 0)
            {
                String s = "";
                s += add(nums, false);
                s += add(nums, true);
                steps.add(s);
                sum -= s.length();
            }

            System.out.printf("Case #%d:", n + 1);
            for (String s : steps)
                System.out.print(" " + s);
            System.out.println();
        }
    }

    static String add(int[] nums, boolean check)
    {
        int most = 0;
        for (int i = 0; i < nums.length; i++)
            if (nums[i] > nums[most])
                most = i;
        nums[most]--;
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (check)
        for (int num : nums)
            if (num > sum / 2)
            {
                nums[most]++;
                return "";
            }
        return (char) ('A' + most) + "";
    }
}
