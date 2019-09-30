import java.util.*;
public class TrainTimetable {
   public static void main(String[] args) {
      try {
         Scanner s = new Scanner(System.in);
         int n = Integer.parseInt(s.nextLine());
         for (int i=0; i<n; i++) {
            int t = Integer.parseInt(s.nextLine());
            StringTokenizer st = new StringTokenizer(s.nextLine(), " ");
            int na = Integer.parseInt(st.nextToken());
            int nb = Integer.parseInt(st.nextToken());
            int[] data = new int[2*(na+nb)];
            int k=0;
            for (int j=0; j<na; j++) {
               st = new StringTokenizer(s.nextLine(), " ");
               data[k++] = 4*parseTime(st.nextToken()) + 2;
               data[k++] = 4*(t + parseTime(st.nextToken())) + 1;
            }
            for (int j=0; j<nb; j++) {
               st = new StringTokenizer(s.nextLine(), " ");
               data[k++] = 4*parseTime(st.nextToken()) + 3;
               data[k++] = 4*(t + parseTime(st.nextToken()));
            }
            Arrays.sort(data);
            int[] req = new int[2];
            int[] curr = new int[2];
            for (int j=0; j<data.length; j++) {
               boolean arrives = (data[j]%4 < 2);
               int idx = data[j]%2;
               if (arrives) {
                  curr[idx]++;
               } else {
                  if (curr[idx]==0) {
                     req[idx]++;
                  } else {
                     curr[idx]--;
                  }
               }
            }
            System.out.println("Case #" + (i+1) + ": " + req[0] + " " + req[1]);
         }
      } catch (Exception e) {
         e.printStackTrace();
      }
   }
   static int parseTime(String s) {
      String[] ss = s.split(":");
      return 60*Integer.parseInt(ss[0]) + Integer.parseInt(ss[1]);
   }
}
