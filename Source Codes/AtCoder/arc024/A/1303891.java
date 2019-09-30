import java.util.*;
public class Main {
  public static void main(String[] args) {
        String[] LArray = new String[100];
        String[] RArray = new String[100];
        int cnt = 0;
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int L = sc.nextInt();
        sc.nextLine();
        String l = sc.nextLine();
        String r = sc.nextLine();
        LArray = l.split(" ");
        RArray = r.split(" ");
           // l????
         char[] l2 = l.toCharArray();
         Arrays.sort(l2);
         String l2sort = new String(l2);
           // r????
         char[] r2 = r.toCharArray();
         Arrays.sort(r2);
         String r2sort = new String(r2);
         List<String> LArray2 = Arrays.asList(LArray);
         List<String> RArray2 = Arrays.asList(RArray);
         for (int i = 0; i < LArray.length ; i++) {
           for (int j = 0; j < RArray.length  ; j++) {
             String wkL = LArray[i];
             String wkR = RArray[j];
             if (wkL.equals(wkR)) {
               cnt++;
               RArray = remove(RArray,wkR);
               break;
             } 
           }
         }
       System.out.println(cnt);
  }

  private static String[] remove(String[] target,String removeStr) {
    List<String> temp = new ArrayList<>(Arrays.asList(target));
    temp.remove(removeStr);
    return temp.toArray(new String[0]);
  }
}