import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        HashSet<String> set = new HashSet<String>();
	for(int i = 0; i<N; i++)	{
            set.add(sc.next());
	}
        System.out.println((set.size()==3)?"Three":"Four");
    }
}