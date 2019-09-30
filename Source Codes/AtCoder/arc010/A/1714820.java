import java.util.Scanner;
 class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] n=new int[4];
		for(int i=0;i<4;i++){
			n[i]=sc.nextInt();
		}
		int[] c=new int[n[1]];
		String s="";
		int a=0;
		boolean error=true;
		for(int i=0;i<n[1];i++){
			int aa=sc.nextInt();
			if(n[0]<=n[2]){
				n[0]+=n[3];
			}
			if(aa>n[0]){
				error=false;
				a=i+1;
				break;
			}
			n[0]-=aa;
		}
		System.out.println((error)?"complete":a);
	}
}