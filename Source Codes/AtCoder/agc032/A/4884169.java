import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		boolean flag = false, imposible = false;		
		ArrayList<Integer> a = new ArrayList<Integer>();
		ArrayList<Integer> b = new ArrayList<Integer>();
		for(int i = 0; i < n; i++){
			b.add(sc.nextInt());
		}
		for(int i = 0; i < n; i++){
			for(int j = b.size() - 1; 0 <= j; j--){
				if(b.get(j) == j + 1){
					a.add(j + 1);
          b.remove(j);
					flag = true;
					break;
				}
			}
			if(flag == false){
				imposible = true;
				break;
			}else{
				flag = false;
			}
		}
		if(imposible == true){
			System.out.println(-1);
		}else {
			for(int i = a.size() -1 ; 0 <= i; i--){
				System.out.println(a.get(i));
			}
		}
	}
}