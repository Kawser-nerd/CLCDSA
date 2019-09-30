import java.util.*;
import java.io.*;

public class B
{
    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int R = input.nextInt();
            int C = input.nextInt();
            int N = input.nextInt();

            int total = R * C;
            int total1 = total / 2, total2 = total - total1;

            int mid = (R - 2) * (C - 2);
            int mid1 = mid / 2, mid2 = mid - mid1;

            int corner = 4;
            int corner1 = R * C % 2 == 1 ? 0 : 2, corner2 = corner - corner1;

            int side = total - mid - corner;
            int side1 = total1 - mid1 - corner1, side2 = total2 - mid2 - corner2;

            int ans;
            if (N <= (R * C + 1) / 2)
                ans = 0;
            else if (R == 1 || C == 1)
                ans = R * C - 1 - 2 * (R * C - N);
            else
            {
                int cand1, cand2;
                {
                    int numHoles = R * C - N;
                    cand1 = (R - 1) * C + (C - 1) * R;
                    if (numHoles >= mid1)
                    {
                        numHoles -= mid1;
                        cand1 -= 4 * mid1;
                    }
                    else
                    {
                        cand1 -= 4 * numHoles;
                        numHoles = 0;
                    }
                    if (numHoles >= side1)
                    {
                        numHoles -= side1;
                        cand1 -= 3 * side1;
                    }
                    else
                    {
                        cand1 -= 3 * numHoles;
                        numHoles = 0;
                    }
                    cand1 -= 2 * numHoles;
                }
                {
                    int numHoles = R * C - N;
                    cand2 = (R - 1) * C + (C - 1) * R;
                    if (numHoles >= mid2)
                    {
                        numHoles -= mid2;
                        cand2 -= 4 * mid2;
                    }
                    else
                    {
                        cand2 -= 4 * numHoles;
                        numHoles = 0;
                    }
                    if (numHoles >= side2)
                    {
                        numHoles -= side2;
                        cand2 -= 3 * side2;
                    }
                    else
                    {
                        cand2 -= 3 * numHoles;
                        numHoles = 0;
                    }
                    cand2 -= 2 * numHoles;
                }
                ans = Math.min(cand1, cand2);
            }

            System.out.printf("Case #%d: ", n + 1);
            System.out.println(ans);
        }
    }
}
