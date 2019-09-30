package qualifiers;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class AlienLanguage 
{
	public int match(int L,String[] d,String wordRegex)
	{
		String[] tokens=new String[L];
		int idx=0;
		for(int i=0;i<wordRegex.length();)
		{
			String tok="";
			char cur=wordRegex.charAt(i);
			if(cur=='(')
			{
				tok+=cur;
				int j=i+1;
				for(;wordRegex.charAt(j)!=')';++j)
					tok+=wordRegex.charAt(j);
				i=j;
			}
			else if(cur==')')
			{
				++i;
				continue;
			}
			else
			{
				tok+=cur;
				++i;
			}
			tokens[idx++]=tok;
		}
		
		
		int ret=0;
		for(int i=0;i<d.length;++i)
		{
			String cur=d[i];
			boolean found=true;
			for(int j=0;j<cur.length();++j)
			{
				if(tokens[j].indexOf(cur.charAt(j))<0)
				{
					found=false;
					break;
				}
			}
			if(found)
				++ret;
		}
		return ret;
	}

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException 
	{
		AlienLanguage obj=new AlienLanguage();
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String t=br.readLine();
		String[] tok=t.split(" ");
		int L=Integer.valueOf(tok[0]);
		int D=Integer.valueOf(tok[1]);
		int N=Integer.valueOf(tok[2]);
		String[] d=new String[D];
		for(int i=0;i<D;++i)
			d[i]=br.readLine();
		for(int i=1;i<=N;++i)
		{
			String w=br.readLine();
			int ret=obj.match(L,d,w);
			System.out.println("Case #"+i+": "+ret);
		}
		
		

	}

}
