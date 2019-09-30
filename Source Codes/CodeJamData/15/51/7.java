import java.util.*;
import java.io.*;

public class A
{
    static int N, D;
    static int[] salaries;
    static int[] managers;

    static List<Integer>[] salaryTable;
    static List<Integer>[] children;
    static int[] counts;
    static int ans;

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            N = input.nextInt();
            D = input.nextInt();

            salaries = new int[N];
            int S0 = input.nextInt();
            int As = input.nextInt();
            int Cs = input.nextInt();
            int Rs = input.nextInt();
            salaryTable = (List<Integer>[]) new List[Rs];
            for (int i = 0; i < Rs; i++)
                salaryTable[i] = new ArrayList<Integer>();
            salaries[0] = S0;
            for (int i = 1; i < N; i++)
            {
                salaries[i] = (salaries[i - 1] * As + Cs) % Rs;
                salaryTable[salaries[i]].add(i);
            }

            managers = new int[N];
            managers[0] = -1;
            children = (List<Integer>[]) new List[N];
            for (int i = 0; i < N; i++)
                children[i] = new ArrayList<Integer>();
            int M0 = input.nextInt();
            int Am = input.nextInt();
            int Cm = input.nextInt();
            int Rm = input.nextInt();
            for (int i = 1; i < N; i++)
            {
                M0 = (M0 * Am + Cm) % Rm;
                managers[i] = M0 % i;
                children[M0 % i].add(i);
            }

            counts = new int[N];
            initCounts(0);
            ans = counts[0];

            for (int salary = S0 + 1; salary <= S0 + D; salary++)
            {
                if (salary - D - 1 >= 0)
                    for (int i : salaryTable[salary - D - 1])
                        removeNode(i);
                if (salary < Rs)
                    for (int i : salaryTable[salary])
                        addNode(i);

                if (counts[0] > ans)
                    ans = counts[0];
            }

            System.out.printf("Case #%d: ", n + 1);
            System.out.println(ans);
        }
    }

    static void initCounts(int node)
    {
        boolean good = salaries[node] <= salaries[0] &&
                salaries[0] - salaries[node] <= D;
        if (good)
            counts[node] = 1;
        for (int child : children[node])
        {
            initCounts(child);
            if (good)
                counts[node] += counts[child];
        }
    }

    static void removeNode(int node)
    {
        int numRemoved = counts[node];
        while (node != -1 && counts[node] > 0)
        {
            counts[node] -= numRemoved;
            node = managers[node];
        }
    }

    static void addNode(int node)
    {
        counts[node] = 1;
        for (int child : children[node])
            counts[node] += counts[child];
        int numAdded = counts[node];
        node = managers[node];
        while (node != -1 && counts[node] > 0)
        {
            counts[node] += numAdded;
            node = managers[node];
        }
    }
}
