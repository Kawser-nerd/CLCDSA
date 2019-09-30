import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
public class ChargingChaos {
	public final static String INPUT_FILE_NAME = "A-large.in";
	public final static String OUTPUT_FILE_NAME = "ChargingChaos.out";
	public static void main(String[] args) {
		try (Scanner in = new Scanner(new FileReader(INPUT_FILE_NAME));
				PrintWriter out = new PrintWriter(new FileWriter(
						OUTPUT_FILE_NAME))) {
			int numT = in.nextInt();
			for (int t = 1; t <= numT; t++) {
				System.out.println("case " +t);
				int num = in.nextInt();
				int len = in.nextInt();
				
				ArrayList<String> initFlow = new ArrayList<String>();
				for(int i = 0; i < num; i ++)
				{
					initFlow.add(in.next());
				}
				
				ArrayList<String> reqFlow = new ArrayList<String>();
				for(int i = 0; i < num; i ++)
				{
					reqFlow.add(in.next());
				}
				//System.out.println(initFlow);
				//System.out.println(reqFlow);
				ArrayList<FlowGroup> fg = new ArrayList<>();
				fg.add(new FlowGroup(initFlow,reqFlow));

				int res = getRes(fg);
				if(res >= FAILVAL)
				{
					out.println("Case #"+t+": NOT POSSIBLE");
				}
				else
				{
					out.println("Case #"+t+": " + res);
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static int FAILVAL = 99999;
	private static int getRes(ArrayList<FlowGroup> fg)
	{
		Result currRes = Result.EITHER;
		
		for(FlowGroup f : fg)
		{
			Result nr = f.getReq();
			//System.out.println(nr);
			if(nr == Result.BASE)return 0;
			if(nr == Result.FAIL || (nr != Result.EITHER && currRes != Result.EITHER && nr != currRes))
			{
				//System.out.println("fail");
				return FAILVAL;
			}
			if(nr != Result.EITHER)currRes = nr;
		}
		//System.out.println(currRes + " end");
		if(currRes == Result.OFF)
		{
			ArrayList<FlowGroup> nfg = new ArrayList<>();
			for(FlowGroup f : fg)
			{
				nfg.addAll(f.split(false));
			}
			return getRes(nfg);
		}
		if(currRes == Result.ON)
		{
			ArrayList<FlowGroup> nfg = new ArrayList<>();
			for(FlowGroup f : fg)
			{
				nfg.addAll(f.split(true));
			}
			return getRes(nfg)+1;
		}
		ArrayList<FlowGroup> nfg = new ArrayList<>();
		for(FlowGroup f : fg)
		{
			nfg.addAll(f.split(false));
		}
		int firstRes = getRes(nfg);
		nfg = new ArrayList<>();
		for(FlowGroup f : fg)
		{
			nfg.addAll(f.split(true));
		}
		firstRes = Math.min(firstRes, getRes(nfg)+1);
		return firstRes;
	}
	
	private static enum Result
	{
		OFF,ON,EITHER,FAIL,BASE;
	}
	
	private static class FlowGroup
	{
		ArrayList<String> init;
		ArrayList<String> req;
		
		public FlowGroup(ArrayList<String> i, ArrayList<String> r)
		{
			init = new ArrayList<>(i);
			req = new ArrayList<>(r);
		}
		
		public Result getReq()
		{
			if(init.get(0).length() == 0)return Result.BASE;
			int numInitOn = 0;
			int numReqOn = 0;
			for(int i = 0; i < init.size(); i ++)
			{
				if(init.get(i).charAt(0) == '1')
				{
					numInitOn++;
				}
				if(req.get(i).charAt(0) == '1')
				{
					numReqOn++;
				}
			}
			
			if(numInitOn == numReqOn && numInitOn == init.size() - numReqOn)
			{
				return Result.EITHER;
			}
			if(numInitOn == numReqOn)
			{
				return Result.OFF;
			}
			if(numInitOn == init.size() - numReqOn)
			{
				return Result.ON;
			}
			return Result.FAIL;
		}
		
		public ArrayList<FlowGroup> split(boolean isOn)
		{
			ArrayList<String> iOn = new ArrayList<String>();
			ArrayList<String> iOff = new ArrayList<String>();
			ArrayList<String> rOn = new ArrayList<String>();
			ArrayList<String> rOff = new ArrayList<String>();
			
			for(int i = 0; i < init.size(); i ++)
			{
				if(init.get(i).charAt(0) == '1')
				{
					iOn.add(init.get(i).substring(1));
				}
				else
				{
					iOff.add(init.get(i).substring(1));
				}
				if((req.get(i).charAt(0) == '1')^isOn)
				{
					rOn.add(req.get(i).substring(1));
				}
				else
				{
					rOff.add(req.get(i).substring(1));
				}
			}
			
			ArrayList<FlowGroup> ret = new ArrayList<>();
			if(iOn.size()>0)ret.add(new FlowGroup(iOn,rOn));
			if(iOff.size()>0)ret.add(new FlowGroup(iOff,rOff));
			return ret;
		}
	}
}
