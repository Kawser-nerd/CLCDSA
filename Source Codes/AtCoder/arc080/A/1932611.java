public class Main {
	int i=100100;
	long a[] =new long[i];
	String b[] =new String[i];
	int four=0,two=0,one=0;
	String str;
	String[] temp;
	public static void main(String[] args) {
		Main c=new Main();
		java.util.Scanner sc =new java.util.Scanner (System.in);
		String str=sc.nextLine();
		String[] temp=str.trim().split(" ");
		int n=(int) Long.parseLong(temp[0]);
		c.read_in(n,sc);
		c.check();
		sc.close();
	}
	public void read_in(int n, java.util.Scanner sc){
			str=sc.nextLine();
			temp=str.trim().split(" ");
		for(i=0;i<n;i++){
			a[i]= Long.parseLong(temp[i]);
			if(a[i]%4==0){
				four++;
			}
			else if(a[i]%2==0){
				two++;
			}
			else	one++;
		}		
	}
	public void check(){
		 if(one>four+1||(one==four+1&&two!=0)) 
			 System.out.println("No");
	      else System.out.println("Yes");
	}
}