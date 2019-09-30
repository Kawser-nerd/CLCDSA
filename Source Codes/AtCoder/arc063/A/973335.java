import java.util.Scanner;

public class Main {
	static String ban[];
	static int ban2[];
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		ban = sc.next().split("");
		ban2= new int[ban.length];

		int sum = 0;
		boolean flag = true;
		int left = 1;
		int right = ban.length-2;
		while(flag){
			String colorL = handan(0);
			String colorR = handan(ban.length-1);
			//System.out.println("left;"+left);
			//System.out.println("right;"+right);
			for(int i = left;left < ban.length;left++){
				/*if(!colorL.equals(handan(left))){
					sum++;
					for(int j = 0;j < left;j++){
						ban2[j]++;
					}
					break;
				}
				if(left == ban.length-1){
					flag = false;
					System.out.println(sum);
					return;
				}*/
				if(!colorL.equals(handan(left))){
					break;
				}
			}

			for(int i = right;right >= 0;right--){
				if(!colorR.equals(handan(right))){
					break;
				}
			}

			int R = ban.length-1-right;
			int L = left;
			if(L >ban.length-1){
				flag = false;
				break;
			}else if(L < R){
				sum++;
				for(int j = 0;j < left;j++){
					ban2[j]++;
				}
			}else{
				sum++;
				for(int j = right;j >=0;j--){
					ban2[j]++;
				}
			}
		}

		System.out.println(sum);
	}

	static String handan(int a){
		if(ban2[a]%2 == 0){
			return ban[a];
		}else{
			if(ban[a].equals("B")){
				return "W";
			}else{
				return "B";
			}
		}
	}
}