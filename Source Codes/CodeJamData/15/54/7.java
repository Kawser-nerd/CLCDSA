import java.util.*;
import java.io.*;

public class D
{
    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int P = input.nextInt();
            long[] nums = new long[P];
            for (int i = 0; i < P; i++)
                nums[i] = input.nextLong();
            long[] freqs = new long[P];
            for (int i = 0; i < P; i++)
                freqs[i] = input.nextLong();

            TreeMap<Long, Long> numFreqs = new TreeMap<Long, Long>();
            for (int i = 0; i < P; i++)
                numFreqs.put(nums[i], freqs[i]);
            List<Long> diffs = new ArrayList<Long>();
            solve(numFreqs, diffs);

            System.out.printf("Case #%d:", n + 1);
            for (long num : diffs)
                System.out.print(" " + num);
            System.out.println();
        }
    }

    static boolean solve(TreeMap<Long, Long> numFreqs, List<Long> diffs)
    {
        if (numFreqs.size() == 1 && numFreqs.containsKey(0L) && numFreqs.get(0L) == 1L)
            return true;
        for (long diff : numFreqs.keySet())
        {
            TreeMap<Long, Long> chopped = chop(numFreqs, diff);
            if (chopped != null)
            {
                diffs.add(diff);
                if (solve(chopped, diffs))
                    return true;
                diffs.remove(diffs.size() - 1);
            }
        }
        return false;
    }

    static TreeMap<Long, Long> chop(TreeMap<Long, Long> numFreqs, long diff)
    {
        TreeMap<Long, Long> copy = new TreeMap<Long, Long>(numFreqs);
        TreeMap<Long, Long> chop = new TreeMap<Long, Long>();
        while (copy.size() > 0)
        {
            long num = copy.firstKey();
            if (diff > 0)
            {
                if (!copy.containsKey(num + diff) || copy.get(num + diff) < copy.get(num))
                    return null;
                copy.put(num + diff, copy.get(num + diff) - copy.get(num));
                if (copy.get(num + diff) == 0)
                    copy.remove(num + diff);
                chop.put(num, copy.get(num));
                copy.remove(num);
            }
            else if (diff < 0)
            {
                if (!copy.containsKey(num - diff) || copy.get(num - diff) < copy.get(num))
                    return null;
                copy.put(num - diff, copy.get(num - diff) - copy.get(num));
                if (copy.get(num - diff) == 0)
                    copy.remove(num - diff);
                chop.put(num - diff, copy.get(num));
                copy.remove(num);
            }
            else
            {
                if (copy.get(num) % 2 != 0)
                    return null;
                chop.put(num, copy.get(num) / 2);
                copy.remove(num);
            }
        }
        return chop;
    }
}
