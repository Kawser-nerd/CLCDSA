import java.util.*;
import java.io.*;
import static lib.Util.*;

public class C
{
    static int H, W;
    static int[] lovers;
    static List<Integer> perim;
    static char[][] grid;

    static int ans;

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            H = input.nextInt();
            W = input.nextInt();
            lovers = new int[2 * (W + H)];
            for (int i = 0; i < W + H; i++)
            {
                int lover1 = input.nextInt() - 1;
                int lover2 = input.nextInt() - 1;
                lovers[lover1] = lover2;
                lovers[lover2] = lover1;
            }

            perim = new ArrayList<Integer>();
            for (int i = 0; i < lovers.length; i++)
                perim.add(i);

            grid = new char[H][W];
            for (int i = 0; i < H; i++)
                for (int j = 0; j < W; j++)
                    grid[i][j] = ' ';

            boolean broke = false;
            while (!perim.isEmpty() && !broke)
            {
                boolean met = false;
                for (int i = 0; i < perim.size(); i++)
                {
                    int lover1 = perim.get(i), lover2 = perim.get((i + 1) % perim.size());
                    if (lovers[lover1] == lover2)
                    {
                        if (!meet(lover1, lover2))
                        {
                            broke = true;
                            break;
                        }
                        met = true;
                        perim.remove(i);
                        if (lover1 < lover2)
                            perim.remove(i);
                        else
                            perim.remove(0);
                    }
                }
                if (!met)
                    broke = true;
            }

            for (int i = 0; i < H; i++)
                for (int j = 0; j < W; j++)
                    if (grid[i][j] == ' ')
                        grid[i][j] = '/';

            System.out.printf("Case #%d:\n", n + 1);
            if (broke)
                System.out.println("IMPOSSIBLE");
            else for (char[] chars : grid)
                System.out.println(chars);
        }
    }

    static boolean meet(int lover1, int lover2)
    {
        int[] start = find(lover1);
        int[] goal = findEnd(lover2);
        while (true)
        {
            if (grid[start[0]][start[1]] == ' ')
                grid[start[0]][start[1]] = start[2] % 2 == 0 ? '\\' : '/';

            if (grid[start[0]][start[1]] == '/')
            {
                if (start[2] == 0) { start[1]--; start[2] = 1; }
                else if (start[2] == 1) { start[0]++; start[2] = 0; }
                else if (start[2] == 2) { start[1]++; start[2] = 3; }
                else if (start[2] == 3) { start[0]--; start[2] = 2; }
            }
            else
            {
                if (start[2] == 0) { start[1]++; start[2] = 3; }
                else if (start[2] == 1) { start[0]--; start[2] = 2; }
                else if (start[2] == 2) { start[1]--; start[2] = 1; }
                else if (start[2] == 3) { start[0]++; start[2] = 0; }
            }

            if (start[0] == goal[0] && start[1] == goal[1] && start[2] == goal[2])
                return true;

            if (start[0] < 0 || start[0] >= H || start[1] < 0 || start[1] >= W)
                return false;
        }
    }

    static int[] find(int lover)
    {
        if (lover < W)
            return new int[] {0, lover, 0};
        else if (lover < W + H)
            return new int[] {lover - W, W - 1, 1};
        else if (lover < W + H + W)
            return new int[] {H - 1, W + H + W - lover - 1, 2};
        else
            return new int[] {W + H + W + H - lover - 1, 0, 3};
    }

    static int[] findEnd(int lover)
    {
        if (lover < W)
            return new int[] {-1, lover, 2};
        else if (lover < W + H)
            return new int[] {lover - W, W, 3};
        else if (lover < W + H + W)
            return new int[] {H, W + H + W - lover - 1, 0};
        else
            return new int[] {W + H + W + H - lover - 1, -1, 1};
    }
}
