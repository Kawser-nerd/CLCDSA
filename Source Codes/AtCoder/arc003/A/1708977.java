import java.util.Scanner;
class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		String[] data={"F","D","C","B","A"};
		String s=sc.next();
		double ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<=4;j++){
				if(data[j].equals(s.substring(i,i+1))){
					ans+=j;
					break;
				}
			}
		}
		System.out.println(ans/n);
	}

}