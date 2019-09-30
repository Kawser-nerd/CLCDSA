package qualifiers;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class WelcomeToCodeJam 
{
	private char[] input;
	private char[] target;
	private BigInteger[][] memo;
	private BigInteger solve(int inputIdx,int targetIdx)
	{
		if(memo[inputIdx][targetIdx]!=null)
			return memo[inputIdx][targetIdx];
		else
		{
			BigInteger ret=BigInteger.ZERO;
			if(inputIdx>=input.length)
			{ 	
				if(targetIdx>=target.length)
				{
					ret=BigInteger.ONE;
				}
				else
					ret=BigInteger.ZERO;
			}
			else
			{
				if(targetIdx<target.length)
				{
					char c1=target[targetIdx];
					char c2=input[inputIdx];
					if(c1==c2)
						ret=ret.add(solve(inputIdx+1,targetIdx+1));
				}
				ret=ret.add(solve(inputIdx+1,targetIdx));
			}
			memo[inputIdx][targetIdx]=ret;
			return ret;
		}			
	}
	public String getWelcome(String inp,String target)
	{
		this.input=inp.toCharArray();
		this.target=target.toCharArray();
		this.memo=new BigInteger[input.length+1][this.target.length+1];
		BigInteger val=solve(0,0);
		String ret=val.toString();
		if(ret.length()<4)
		{
			for(int i=ret.length();i<4;++i)
				ret="0"+ret;
		}
		else
			ret=ret.substring(ret.length()-4);
		return ret;
	}

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		WelcomeToCodeJam obj=new WelcomeToCodeJam();
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int N=Integer.valueOf(br.readLine());
		String target="welcome to code jam";
		for(int i=1;i<=N;++i)
		{
			String inp=br.readLine();			
			String ret=obj.getWelcome(inp, target);
			System.out.println("Case #"+i+": "+ret);
		}

	}

}
