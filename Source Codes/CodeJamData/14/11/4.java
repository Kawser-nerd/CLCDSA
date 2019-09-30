import java.util.*;
import java.io.*;

public class A
{
    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int N = input.nextInt();
            int L = input.nextInt();
            String[] start = new String[N];
            String[] end = new String[N];
            for (int i = 0; i < N; i++)
                start[i] = input.next();
            for (int i = 0; i < N; i++)
                end[i] = input.next();

            boolean[] change = new boolean[L];
            int minChanges = 9999;
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                {
                    int numChanges = 0;
                    for (int k = 0; k < L; k++)
                    {
                        change[k] = start[i].charAt(k) != end[j].charAt(k);
                        if (change[k])
                            numChanges++;
                    }
                    
                    Map<String, Integer> map = new HashMap<String, Integer>();
                    for (int l = 0; l < N; l++)
                    {
                        char[] chars = start[l].toCharArray();
                        for (int k = 0; k < L; k++)
                            if (change[k])
                                chars[k] = chars[k] == '1' ? '0' : '1';
                        String s = new String(chars);
                        if (!map.containsKey(s))
                            map.put(s, 0);
                        map.put(s, map.get(s) + 1);
                    }

                    boolean match = true;
                    for (int l = 0; l < N && match; l++)
                    {
                        String s = end[l];
                        if (map.containsKey(s) && map.get(s) > 0)
                            map.put(s, map.get(s) - 1);
                        else
                            match = false;
                    }

                    if (match && numChanges < minChanges)
                        minChanges = numChanges;
                }

            System.out.printf("Case #%d: ", n + 1);
            if (minChanges == 9999)
                System.out.println("NOT POSSIBLE");
            else
                System.out.println(minChanges);
        }
    }
}
