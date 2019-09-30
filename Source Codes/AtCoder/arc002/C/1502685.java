import java.util.Scanner;


public class Main 
{

	public static void main(String[] args) 
	{
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String c_i = sc.next();
		
		String comm[]={"A","B","X","Y"};
		
		int min = n;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				for(int k=0;k<4;k++)
				{
					for(int l=0;l<4;l++)
					{
						String L = comm[i]+comm[j];
						String R = comm[k]+comm[l];
						int count=Main.count(n, c_i, L, R);
						
						if(count<min)
						{
							min=count;
						}
					}
				}
			}
		}
		System.out.println(min);
		
	}
	
	static int count(int n, String c_i ,String L, String R)
	{
		String tmp_c = c_i;
		int count=0;
		int index=0;
		for(;;)
		{
		
				String headchar="";
				if(index<(n-1))
				{
					headchar = String.valueOf(tmp_c.charAt(index))+String.valueOf(tmp_c.charAt(index+1));
				}
//				System.out.println(headchar);
				if(headchar.equals(L)||headchar.equals(R))
				{
					index+=2;
				}
				else
				{
					index++;
				}
				count++;
				
				if(index==n)
				{
					break;
				}
			
		}
		
		return count;
	}

}