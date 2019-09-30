import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long goal = sc.nextLong();
		long ng1 = sc.nextLong();
		long ng2 = sc.nextLong();
		long ng3 = sc.nextLong();
		int a = 100;
		if(goal==ng1 || goal==ng2 || goal==ng3){
			System.out.println("NO");
			return;
		}
		while(goal!=0 && a>0){
		if(goal-3!=ng1 && goal-3!=ng2 && goal-3!=ng3 && goal-3>=0){
			goal = goal-3;
		}else if(goal-2!=ng1 && goal-2!=ng2 && goal-2!=ng3 && goal-2>=0){
			goal = goal-2;
		}else if(goal-1!=ng1 && goal-1!=ng2 && goal-1!=ng3){
			goal = goal-1;
		}else{
			System.out.println("NO");
			return;
		}
			a--;
	}
		if(goal==0){
			System.out.println("YES");
		}else{
			System.out.println("NO");
		}
	}
}