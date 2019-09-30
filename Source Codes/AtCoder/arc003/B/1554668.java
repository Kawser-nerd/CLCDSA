import java.util.*;

public class Main {
    private static int n;
    private static ArrayList<String> arrayList = new ArrayList<>();

    public static void input(){
        Scanner scan = new Scanner(System.in);

        n = scan.nextInt();

        for (int i=0;i<n;i++){
            StringBuffer sb = new StringBuffer();
            sb.append(scan.next());
            sb.reverse();
            arrayList.add(sb.toString());
        }

    }

    public static void main(String args[]) {
        //??
        input();

        Collections.sort(arrayList);

        for (int i=0;i<n;i++){
            StringBuffer sb = new StringBuffer();
            sb.append(arrayList.get(i));
            sb.reverse();
            System.out.println(sb.toString());
        }
    }
}