import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * Created by vitalii on 08.04.17.
 */
public class TaskB {

    Scanner in;
    PrintWriter out;

    public int solve()
    {
       int n = in.nextInt();
       int m = in.nextInt();

       int ans = 0;

       PriorityQueue<Integer>[] a = new PriorityQueue[n];

       long[] cost = new long[n];

       for (int i = 0; i < n; i++)
       {
           cost[i] = in.nextInt();
       }

       for (int i = 0; i < n; i++)
       {
           a[i] = new PriorityQueue<Integer>();
           for (int j = 0; j < m; j++)
           {
               a[i].add(in.nextInt());
           }
       }

       boolean shouldAdd = true;

       int[] presenters = new int[n];

       while (true)
       {
           if (shouldAdd)
           {
               shouldAdd = false;
               for (int i = 0; i < n; i++)
               {
                   if (a[i].size() == 0)
                   {
                       return ans;
                   }
                   presenters[i] = a[i].poll();
               }
           }

           int minP = 0, maxP = 0;

           for (int i = 0; i < n; i++)
           {
               if (presenters[i]*cost[minP] < presenters[minP]*cost[i])
               {
                   minP = i;
               }
               if (presenters[i]*cost[maxP] > presenters[maxP]*cost[i])
               {
                   maxP = i;
               }
           }

           int cand = 100+(int)(Math.round(presenters[maxP]/cost[maxP]/1.1));

           while (cand * cost[maxP] * 110 >= presenters[maxP]*100)
           {
               cand--;
           }

           cand++;

           boolean isOk =
               cand*cost[minP]*90 <= presenters[minP]*100 &&
               cand*cost[minP]*110 >= presenters[minP]*100;

           if (isOk)
           {
               ans++;
               shouldAdd = true;
               continue;
           }

           if (a[minP].size() == 0)
           {
               return ans;
           }
           presenters[minP] = a[minP].poll();
       }



    }

    public void run() throws FileNotFoundException {
        in = new Scanner(new File("B.in"));
        out = new PrintWriter("B.out");
        int n = in.nextInt();
        for (int i = 0; i < n; i++)
        {
            out.println("Case #"+(i+1)+": " + solve());
        }
        in.close();
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new TaskB().run();
    }

}
